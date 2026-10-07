/*
 * file:     unit_02195E80_p04.c
 * unit:     yes
 * function: func_02196458, func_021964A8, func_02196514
 * address:  0x02196458
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
 *   gti2ConnectionCommunicationError  0x02195f5c arm
 *   gti2ConnectedCallback             0x0219500c arm
 *   gti2ConnectionClosed              0x021959d0 arm
 *   gti2SendClosed                    0x02197bb8 arm
 *   gti2ConnectionError   0x02195ec4 arm ov009
 */
struct GTI2Connection {
    unsigned char pad0[0xc];
    int state;
};

typedef int GT2Bool;

typedef enum { GT2Success, GT2OutOfMemory, GT2Rejected } GT2Result;

typedef enum { GT2LocalClose, GT2RemoteClose } GT2CloseReason;

extern int gti2ConnectionCommunicationError(struct GTI2Connection * connection);
extern int gti2ConnectedCallback(struct GTI2Connection * connection, int result, unsigned char * message, int len);
extern void gti2ConnectionClosed(struct GTI2Connection * connection);
extern int gti2SendClosed(struct GTI2Connection * connection);
extern GT2Bool gti2ConnectionError(struct GTI2Connection *connection, GT2Result result, GT2CloseReason reason);


static int gti2HandleAccept(struct GTI2Connection * connection)
{
    if (connection->state != 1)
        return gti2ConnectionCommunicationError(connection) != 0;
    connection->state = 5;
    return gti2ConnectedCallback(connection, 0, 0, 0) != 0;
}


static int gti2HandleReject(struct GTI2Connection * connection, unsigned char * message, int len)
{
    if (connection->state != 1)
        return gti2ConnectionCommunicationError(connection) != 0;
    gti2ConnectionClosed(connection);
    if (!gti2SendClosed(connection))
        return 0;
    if (gti2ConnectedCallback(connection, 2, message, len))
        return 1;
    return 0;
}


static GT2Bool gti2HandleClose(struct GTI2Connection *connection)
{
    if (!gti2SendClosed(connection))
        return 0;
    if (!gti2ConnectionError(connection, GT2Rejected,
                             (connection->state == 6) ? GT2LocalClose : GT2RemoteClose))
        return 0;
    return 1;
}
