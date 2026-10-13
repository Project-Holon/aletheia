/*
 * file:     gt2main_4.c
 * unit:     yes
 * function: gt2GetRemoteIP, gt2GetRemotePort, gt2GetLocalIP, gt2GetLocalPort, gt2GetOutgoingBufferSize
 * address:  0x02195E28
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "gt2main_2_types.h"

unsigned int gt2GetRemoteIP(const GTI2Connection *connection);
unsigned short gt2GetRemotePort(const GTI2Connection *connection);
unsigned int gt2GetLocalIP(const GTI2Socket *socket);
unsigned short gt2GetLocalPort(const GTI2Socket *socket);
int gt2GetOutgoingBufferSize(const GTI2Connection *connection);

/*
 * Remote address of a connection.
 */
unsigned int gt2GetRemoteIP(const GTI2Connection *connection)
{
    return connection->ip;
}

/*
 * Remote port of a connection.
 */
unsigned short gt2GetRemotePort(const GTI2Connection *connection)
{
    return connection->port;
}

/*
 * Local address of a socket.
 */
unsigned int gt2GetLocalIP(const GTI2Socket *socket)
{
    return socket->ip;
}

/*
 * Local port of a socket.
 */
unsigned short gt2GetLocalPort(const GTI2Socket *socket)
{
    return socket->port;
}

/*
 * Size of the outgoing buffer of a connection.
 */
int gt2GetOutgoingBufferSize(const GTI2Connection *connection)
{
    return connection->outgoingBuffer.size;
}
