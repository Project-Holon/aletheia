/*
 * file:     unit_02195E60.c
 * unit:     yes
 * function: func_02195E60, func_02195E68, func_02195E70, func_02195E78
 * address:  0x02195E60
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

int func_02195E60(const GTI2Socket *socket);
void func_02195E68(GTI2Socket *socket, void *callback);
void func_02195E70(GTI2Connection *connection, void *data);
void *func_02195E78(const GTI2Connection *connection);

/*
 * Operating system socket handle behind a socket object.
 */
int func_02195E60(const GTI2Socket *socket)
{
    return socket->socket;
}

/*
 * Sets the callback for messages that belong to no connection.
 */
void func_02195E68(GTI2Socket *socket, void *callback)
{
    socket->unrecognizedMessageCallback = callback;
}

/*
 * Sets the user data of a connection.
 */
void func_02195E70(GTI2Connection *connection, void *data)
{
    connection->data = data;
}

/*
 * User data of a connection.
 */
void *func_02195E78(const GTI2Connection *connection)
{
    return connection->data;
}
