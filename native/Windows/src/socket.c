/* Windows Native source code file */
#include <socket.h>
#include <string.h>

/*************************************************************
 * Private
 ************************************************************/

WSADATA _wsa;
linki_error_t _error;
const char* _error_prefix =  "[Linki]: ";
const char* _error_buffer[] = {
    [LINKI_OK]              = "OK",

    // linki_create
    [LINKI_ERROR_INIT]      = "Invalid init",
    [LINKI_ERROR_SOCKET]    = "Invalid socket",
    [LINKI_ERROR_BIND]      = "Bind failed",

    // linki_start
    [LINKI_ERROR_LISTEN]    = "Listening error",
    [LINKI_ERROR_MALLOC]    = "Memeory allocation error",
    [LINKI_ERROR_RECV]      = "Receive data error",

    [LINKI_ERROR_CACCEPT]   = "Client accept error",

};

static const  char* default_answer =    "HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n\r\n"
                                "<html><body><h1>[linki]: There's no user's content!</h1></body></html>";
static const size_t default_answer_size = 114;

/*************************************************************
 * Public
 ************************************************************/


void linki_init(void) {
    if (WSAStartup(MAKEWORD(2, 2), &_wsa) != 0) {
        _error = LINKI_ERROR_INIT;
    } 
}

linki_web_t linki_create(linki_web_config_t config) {
    linki_web_t web = {0};

    // Create socket
    web.socket = socket(config.af, config.sock_type, config.iproto);
    if (web.socket == INVALID_SOCKET) {
        _error = LINKI_ERROR_SOCKET;
        return web;
    }

    // Create web server
    web.server.sin_family = config.af;
    web.server.sin_addr.s_addr = config.inaddr;
    web.server.sin_port = htons(config.port);

    // Bind
    if (bind(web.socket, (struct sockaddr *)&(web.server), sizeof(web.server))) {
        _error = LINKI_ERROR_BIND;
        return web;
    }

    // Allocate buffer
    web.buffer.data = calloc(config.buffer_size, 1);
    if (web.buffer.data == NULL) {
        _error = LINKI_ERROR_MALLOC;
        return web;
    }

    _error = LINKI_OK;
    return web;
}

void linki_start(linki_web_t* web, int backlog, char* (*handler)(char*)) {
    // listening
    if (listen(web->socket, backlog) != 0) {
        _error = LINKI_ERROR_BIND;
        closesocket(web->socket);
        return;
    }

    // main part
    SOCKET client_socket;
    struct sockaddr_in client;
    int c = sizeof(struct sockaddr_in);

    while((client_socket = accept(web->socket, (struct sockaddr *)&client, &c)) != INVALID_SOCKET) {
        memset(web->buffer.data, 0, web->buffer.size);
        int recv_size = recv(client_socket, web->buffer.data, web->buffer.size, 0);
        if (recv_size == SOCKET_ERROR) {
            _error = LINKI_ERROR_RECV;
            closesocket(client_socket);
            return;
        }
        
        // user's function
        char* response = handler(web->buffer.data);

        if (response != NULL) {
            send(client_socket, response, strlen(response), 0);
        } else {
            send(client_socket, default_answer, default_answer_size, 0);
        }

        closesocket(client_socket);
    }

    if (client_socket == INVALID_SOCKET) {
        _error = LINKI_ERROR_CACCEPT;
        closesocket(web->socket);
        closesocket(client_socket);
        return;
    }
}

void linki_stop(linki_web_t web) {
    closesocket(web.socket);
    WSACleanup();
}


linki_error_t linki_get_error(const char* error_code) {
    if (error_code != NULL)
        error_code = _error_buffer[_error];
    return _error;
}