/*
 * file:     gt2connection.c
 * unit:     yes
 * function: gti2NewOutgoingConnection, gti2NewIncomingConnection, gti2StartConnectionAttempt, gti2AcceptConnection, gti2RejectConnection, gti2ConnectionSendData, gti2CheckTimeout, gti2SendRetries, gti2CheckPendingAck, gti2CheckKeepAlive, gti2ConnectionThink, gti2CloseConnection, gti2ConnectionClosed, gti2ConnectionCleanup
 * address:  0x02195590
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gti2NewSocketConnection  0x02198038 arm
 *   gti2MessageCheck  0x02198808  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   memcpy  0x02092344  arm
 *   gti2GetChallenge  0x02194B74  arm  ov009
 *   gti2GetResponse  0x02194C6C  arm  ov009
 *   gti2SendClientChallenge  0x021975FC  arm  ov009
 *   gti2SendAccept  0x02197784 arm
 *   gti2MessageCheck  0x02198808 arm
 *   gti2SendReject    0x021977E8 arm
 *   gti2SocketSend  0x02198328 arm
 *   current_time    0x0217F264 arm
 *   gti2SendClosed  0x02197BB8  arm  ov009
 *   gti2ConnectedCallback  0x0219500C  arm  ov009
 *   ArrayLength       0x02184200 arm
 *   ArrayNth          0x02184208 arm
 *   gti2ResendMessage 0x02197C5C arm
 *   gti2SendAck  0x02197A30 arm
 *   gti2SendKeepAlive  0x021978CC arm
 *   gti2SendClosed          0x02197BB8 arm
 *   gti2ClosedCallback      0x02195158 arm
 *   gti2FreeSocketConnection 0x02198264 arm
 *   gti2SendClose           0x02197868 arm
 *   TableRemove  0x021847BC arm
 *   ArrayAppend  0x02184234 arm
 *   gsifree  0x0217EAE0  arm  ov009
 *   ArrayFree  0x021841B0  arm  ov009
 */
#include "gt2main_types.h"
#include "darray.h"

#include "gt2socket.h"
#include "gt2utility.h"
#include "gsmemory.h"
#include "../arm9/msl_string_mem.h"
#include "gt2auth.h"
#include "gt2message.h"
#include "gsplatformutil.h"
#include "gt2callback.h"
#include "darray.h"
#include "hashtable.h"
int gti2NewOutgoingConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
int gti2NewIncomingConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
int gti2StartConnectionAttempt(struct GTI2Connection *c, unsigned char *message, int len, struct GT2ConnectionCallbacks *callbacks);
int gti2AcceptConnection(struct GTI2Connection *connection, struct GT2ConnectionCallbacks *callbacks);
void gti2RejectConnection(struct GTI2Connection *connection, unsigned char *message, int len);
int gti2ConnectionSendData(struct GTI2Connection *connection, unsigned char *message, int len);
int gti2CheckTimeout(struct GTI2Connection *c, unsigned int now);
int gti2ConnectionThink(struct GTI2Connection *connection, unsigned int now);
void gti2CloseConnection(struct GTI2Connection *connection, int hard);
void gti2ConnectionClosed(struct GTI2Connection *connection);
void gti2ConnectionCleanup(struct GTI2Connection *c);






int gti2NewOutgoingConnection(struct GTI2Socket *socket,
                              struct GTI2Connection **connection,
                              unsigned int ip, unsigned short port)
{
    int result = gti2NewSocketConnection(socket, connection, ip, port);

    if (result)
        return result;
    (*connection)->state = 0;
    (*connection)->initiated = 1;
    return 0;
}






int gti2NewIncomingConnection(struct GTI2Socket *socket,
                              struct GTI2Connection **connection,
                              unsigned int ip, unsigned short port)
{
    int result = gti2NewSocketConnection(socket, connection, ip, port);

    if (result)
        return result;
    (*connection)->state = 2;
    (*connection)->initiated = 0;
    return 0;
}






/*
 * sdk:      gti2StartConnectionAttempt (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 */
int gti2StartConnectionAttempt(struct GTI2Connection *c, unsigned char *message, int len, struct GT2ConnectionCallbacks *callbacks)
{
	char challenge[32];

	gti2MessageCheck(&message, &len);
	if (len > 0) {
		c->initialMessage = gsimalloc(len);
		if (!c->initialMessage)
			return 1;
		memcpy(c->initialMessage, message, len);
		c->initialMessageLen = len;
	}
	if (callbacks)
		c->callbacks = *callbacks;
	gti2GetChallenge((unsigned char *)challenge);
	gti2GetResponse(c->response, (unsigned char *)challenge);
	gti2SendClientChallenge(c, challenge);
	c->state = 0;
	return 0;
}






int gti2AcceptConnection(struct GTI2Connection *connection,
                         struct GT2ConnectionCallbacks *callbacks)
{
    if (connection->freeAtAcceptReject)
    {
        connection->freeAtAcceptReject = 0;
        return 0;
    }
    connection->freeAtAcceptReject = 0;
    if (connection->state != 4)
        return 0;
    gti2SendAccept(connection);
    connection->state = 5;
    if (callbacks)
        connection->callbacks = *callbacks;
    return 1;
}






void gti2RejectConnection(struct GTI2Connection *connection,
                          unsigned char *message, int len)
{
    connection->freeAtAcceptReject = 0;
    if (connection->state != 4)
        return;
    gti2MessageCheck(&message, &len);
    gti2SendReject(connection, message, len);
    connection->state = 6;
}






int gti2ConnectionSendData(struct GTI2Connection *connection,
                           unsigned char *message, int len)
{
    if (gti2SocketSend(connection->socket, connection->ip, connection->port,
                       message, len) == 0)
        return 0;
    connection->lastSend = current_time();
    return 1;
}






/*
 * sdk:      gti2CheckTimeout (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 */
int gti2CheckTimeout(struct GTI2Connection *c, unsigned int now)
{
	int timedOut;

	if (c->state < 5) {
		timedOut = 0;
		if (c->initiated) {
			if (c->timeout) {
				if (now - c->startTime > c->timeout)
					timedOut = 1;
			}
		} else if (c->state < 4) {
			if (now - c->startTime > 60000)
				timedOut = 1;
		}
		if (timedOut) {
			gti2SendClosed((int *)c);
			gti2ConnectionClosed(c);
			if (!gti2ConnectedCallback(c, 6, 0, 0))
				return 0;
		}
	}
	return 1;
}





static int gti2SendRetries(struct GTI2Connection *connection, unsigned int now)
{
    int i;
    int len;

    len = ArrayLength((struct DArrayImplementation *)connection->outgoingBufferMessages);
    for (i = 0; i < len; i++)
    {
        struct GTI2OutgoingBufferMessage *message =
            ArrayNth(connection->outgoingBufferMessages, i);

        if ((now - message->sendTime) > 1000)
        {
            if (gti2ResendMessage(connection, message) == 0)
                return 0;
        }
    }
    return 1;
}





static int gti2CheckPendingAck(struct GTI2Connection *connection,
                               unsigned int now)
{
    if (!connection->pendingAck)
        return 1;
    if ((now - connection->pendingAckTime) > 100)
    {
        if (gti2SendAck(connection) == 0)
            return 0;
    }
    return 1;
}





static int gti2CheckKeepAlive(struct GTI2Connection *connection,
                              unsigned int now)
{
    if ((now - connection->lastSend) > 30000)
    {
        if (gti2SendKeepAlive(connection) == 0)
            return 0;
    }
    return 1;
}




int gti2ConnectionThink(struct GTI2Connection *connection, unsigned int now)
{
    if (gti2CheckTimeout(connection, now) == 0)
        return 0;
    if (gti2CheckKeepAlive(connection, now) == 0)
        return 0;
    if (gti2SendRetries(connection, now) == 0)
        return 0;
    return gti2CheckPendingAck(connection, now) != 0;
}




void gti2CloseConnection(struct GTI2Connection *connection, int hard)
{
    if (hard)
    {
        if (connection->state >= 7)
            return;
        gti2ConnectionClosed(connection);
        gti2SendClosed((int *)connection);
        gti2ClosedCallback(connection, 0);
        gti2FreeSocketConnection(connection);
    }
    else
    {
        connection->state = 6;
        gti2SendClose(connection);
    }
}



void gti2ConnectionClosed(struct GTI2Connection *connection)
{
    if (connection->state == 7)
        return;
    connection->state = 7;
    TableRemove(connection->socket->connections, &connection);
    ArrayAppend(connection->socket->closedConnections, &connection);
}



/*
 * sdk:      gti2ConnectionCleanup (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 */
void gti2ConnectionCleanup(struct GTI2Connection *c)
{
	if (c->initialMessage)
		gsifree(c->initialMessage);
	if (c->incomingBuffer.buffer)
		gsifree(c->incomingBuffer.buffer);
	if (c->outgoingBuffer.buffer)
		gsifree(c->outgoingBuffer.buffer);
	if (c->incomingBufferMessages)
		ArrayFree(c->incomingBufferMessages);
	if (c->outgoingBufferMessages)
		ArrayFree(c->outgoingBufferMessages);
	if (c->sendFilters)
		ArrayFree(c->sendFilters);
	if (c->receiveFilters)
		ArrayFree(c->receiveFilters);
	gsifree(c);
}
