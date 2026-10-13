/*
 * file:     unit_02195E60.c
 * unit:     yes
 * function: gt2GetSocketSOCKET, gt2SetUnrecognizedMessageCallback, gt2SetConnectionData, gt2GetConnectionData
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

int gt2GetSocketSOCKET(const GTI2Socket *socket);
void gt2SetUnrecognizedMessageCallback(GTI2Socket *socket, void *callback);
void gt2SetConnectionData(GTI2Connection *connection, void *data);
void *gt2GetConnectionData(const GTI2Connection *connection);

/*
 * Operating system socket handle behind a socket object.
 */
int gt2GetSocketSOCKET(const GTI2Socket *socket)
{
    return socket->socket;
}

/*
 * Sets the callback for messages that belong to no connection.
 */
void gt2SetUnrecognizedMessageCallback(GTI2Socket *socket, void *callback)
{
    socket->unrecognizedMessageCallback = callback;
}

/*
 * Sets the user data of a connection.
 */
void gt2SetConnectionData(GTI2Connection *connection, void *data)
{
    connection->data = data;
}

/*
 * User data of a connection.
 */
void *gt2GetConnectionData(const GTI2Connection *connection)
{
    return connection->data;
}
