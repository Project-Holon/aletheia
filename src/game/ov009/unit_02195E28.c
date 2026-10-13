/*
 * file:     unit_02195E28.c
 * unit:     yes
 * function: func_02195E28, func_02195E30, func_02195E38, func_02195E40, func_02195E48
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
#include "unit_02195B20_types.h"

unsigned int func_02195E28(const GTI2Connection *connection);
unsigned short func_02195E30(const GTI2Connection *connection);
unsigned int func_02195E38(const GTI2Socket *socket);
unsigned short func_02195E40(const GTI2Socket *socket);
int func_02195E48(const GTI2Connection *connection);

/*
 * Remote address of a connection.
 */
unsigned int func_02195E28(const GTI2Connection *connection)
{
    return connection->ip;
}

/*
 * Remote port of a connection.
 */
unsigned short func_02195E30(const GTI2Connection *connection)
{
    return connection->port;
}

/*
 * Local address of a socket.
 */
unsigned int func_02195E38(const GTI2Socket *socket)
{
    return socket->ip;
}

/*
 * Local port of a socket.
 */
unsigned short func_02195E40(const GTI2Socket *socket)
{
    return socket->port;
}

/*
 * Size of the outgoing buffer of a connection.
 */
int func_02195E48(const GTI2Connection *connection)
{
    return connection->outgoingBuffer.size;
}
