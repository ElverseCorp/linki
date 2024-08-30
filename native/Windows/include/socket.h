#ifndef SOCKET_WINDOWS_H_
#define SOCKET_WINDOWS_H_

/**************************************************************************//**
 * @file     socket.h
 * @brief    Project L - Linki, native header for Windows. General operations.
 * @version  V0.0.1
 * @date     28. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include "socket.enum.h"

/*************************************************************
 * Private
 ************************************************************/

extern WSADATA _wsa;
extern const char* _error_buffer[];

/*************************************************************
 * Public
 ************************************************************/


/**
 * @brief Initialize Linki libraries.
 * 
 * @returns 
 */
extern void linki_init(void); 

/**
 * @brief Creates web server based on configuration.
 * 
 * @param[in] config web server configuration
 */
extern linki_web_t linki_create(linki_web_config_t config); 

/**
 * @brief Enable server listening.
 * 
 * @param[in] web handler pointer
 * @param[in] backlog is number of maximum clients.
 * @param[in] handler function. It will be receive and responde
 */
extern void linki_start(linki_web_t* web, int backlog, char* (*handler)(char*));

/**
 * @brief Gets the last error of library functions.
 * 
 * @param[in] web is number of maximum clients.
 */
extern void linki_stop(linki_web_t web); 


/**
 * @brief Gets the last error of library functions.
 * 
 * @param[out] error_code str explanation of the error (for logging)
 * @returns error code of the
 */
extern linki_error_t linki_get_error(const char* error_code); 

/*

af (Address Family): Указывает семейство адресов, с которым будет работать сокет. Определяет тип адресов, которые могут быть использованы с сокетом. Некоторые распространённые значения:

    AF_INET (IPv4): Используется для сетей IPv4.
    AF_INET6 (IPv6): Используется для сетей IPv6.
    AF_UNIX или AF_LOCAL: Используется для локальных соединений на Unix-системах (не поддерживается в Windows).
    AF_BLUETOOTH: Используется для соединений по Bluetooth (специфично для некоторых устройств).
    AF_NETBIOS: Используется для сетей NetBIOS.

type (Socket Type): Указывает тип сокета, определяя, как данные будут передаваться через него. Основные типы:

    SOCK_STREAM: Потоковый сокет, который обеспечивает двустороннюю последовательную передачу данных. Обычно используется для протокола TCP.
    SOCK_DGRAM: Дейтаграммный сокет, обеспечивает передачу пакетов данных. Обычно используется для протокола UDP.
    SOCK_RAW: Сырой сокет, который предоставляет прямой доступ к основным транспортным протоколам. Полезно для реализации собственных протоколов.
    SOCK_SEQPACKET: Последовательный пакетный сокет, обеспечивает упорядоченную передачу пакетов данных с гарантией доставки.
    SOCK_RDM: Надежная доставка дейтаграмм (меньше используется, специфичен).

protocol (Protocol): Определяет конкретный протокол, который будет использоваться с сокетом. Обычно этот аргумент используется для уточнения, когда параметр type допускает несколько вариантов протоколов. Например:

    IPPROTO_TCP: Протокол TCP (Transmission Control Protocol).
    IPPROTO_UDP: Протокол UDP (User Datagram Protocol).
    IPPROTO_ICMP: Протокол ICMP (Internet Control Message Protocol), используется для диагностических сообщений.
    IPPROTO_RAW: Указывает использование сырого протокола (без обработки протоколов более высокого уровня).
    IPPROTO_IP: Используется для выбора IP-протокола по умолчанию, если протокол не определен.

*/


#endif // SOCKET_WINDOWS_H_
