#ifndef SOCKET_WINDOWS_EUNM_H_
#define SOCKET_WINDOWS_EUNM_H_

/**************************************************************************//**
 * @file     socket.h
 * @brief    Project L - Linki, native header for Windows. Native enums and types.
 * @version  V0.0.1
 * @date     28. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <winsock2.h>

/* Enums */

// ---------------- AF
#define LINKI_AF_INET           AF_INET
#define LINKI_AF_INET6          AF_INET6
#define LINKI_AF_UNIX           AF_UNIX
#ifdef AF_BLUETOOTH
#   define LINKI_AF_BLUETOOTH   AF_BLUETOOTH
#endif
#define LINKI_AF_NETBIOS        AF_NETBIOS

// ---------------- TYPE
#define LINKI_SOCK_STREAM       SOCK_STREAM
#define LINKI_SOCK_DGRAM        SOCK_DGRAM
#define LINKI_SOCK_RAW          SOCK_RAW
#define LINKI_SOCK_SEQPACKET    SOCK_SEQPACKET
#define LINKI_SOCK_RDM          SOCK_RDM

// ---------------- PROTOCOL
#define LINKI_IPPROTO_TCP       IPPROTO_TCP
#define LINKI_IPPROTO_UDP       IPPROTO_UDP
#define LINKI_IPPROTO_ICMP      IPPROTO_ICMP
#define LINKI_IPPROTO_RAW       IPPROTO_RAW
#define LINKI_IPPROTO_IP        IPPROTO_IP

// ---------------- ADDRESS ACCESS

#define LINKI_INADDR_ANY        INADDR_ANY
#define LINKI_INADDR_LOOPBACK   INADDR_LOOPBACK
#define LINKI_INADDR_BROADCAST  INADDR_BROADCAST
#define LINKI_INADDR_NONE       INADDR_NONE

// ---------------- ERRORS

typedef enum {
    LINKI_OK            =   0x00,
    LINKI_ERROR_INIT    =   0x01,
    LINKI_ERROR_SOCKET  =   0x02,
    LINKI_ERROR_BIND    =   0x03,
    LINKI_ERROR_LISTEN  =   0x04,
    LINKI_ERROR_MALLOC  =   0x05,
    LINKI_ERROR_RECV    =   0x06,
    LINKI_ERROR_CACCEPT =   0x07,
} linki_error_t;



/* Data */

typedef int linki_web_af_t;
typedef int linki_web_type_t;
typedef int linki_web_proto_t;

/// @brief Linki buffer with selected size
typedef struct {
    char* data;
    size_t size;
} linki_web_buffer_t;

/// @brief Linki web server main variable/handler
typedef struct {
    SOCKET socket;
    struct sockaddr_in server;
    linki_web_buffer_t buffer;
} linki_web_t;

/// @brief Linki web configuration
typedef struct {
    uint16_t port;              // web port
    linki_web_af_t af;          // address family
    linki_web_type_t sock_type; // socket type LINKI_SOCK_
    linki_web_proto_t iproto;   // protocol LINKI_IPROTO_
    u_long inaddr;              // bind configuration LINKI_INADDR_
    size_t buffer_size;         // input buffer size in bytes
} linki_web_config_t;


#endif // SOCKET_WINDOWS_EUNM_H_
