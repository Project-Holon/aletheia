/*
 * file:     unit_02195590_p04.c
 * unit:     yes
 * function: func_02195918, func_02195980
 * address:  0x02195918
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
 *   gti2CheckTimeout     0x02195798  arm  ov009
 *   gti2CheckKeepAlive   0x021958E4  arm  ov009
 *   gti2SendRetries      0x0219583C  arm  ov009
 *   gti2CheckPendingAck  0x021958A8  arm  ov009
 *   gti2ConnectionClosed    0x021959D0 arm
 *   gti2SendClosed          0x02197BB8 arm
 *   gti2ClosedCallback      0x02195158 arm
 *   gti2FreeSocketConnection 0x02198264 arm
 *   gti2SendClose           0x02197868 arm
 */
struct GTI2Connection;
struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    void *socket;
    int state;
};

extern int gti2CheckTimeout(struct GTI2Connection *connection, unsigned int now);
extern int gti2CheckKeepAlive(struct GTI2Connection *connection,
                              unsigned int now);
extern int gti2SendRetries(struct GTI2Connection *connection, unsigned int now);
extern int gti2CheckPendingAck(struct GTI2Connection *connection,
                               unsigned int now);
extern void gti2ConnectionClosed(struct GTI2Connection *connection);
extern int gti2SendClosed(struct GTI2Connection *connection);
extern int gti2ClosedCallback(struct GTI2Connection *connection, int reason);
extern void gti2FreeSocketConnection(struct GTI2Connection *connection);
extern int gti2SendClose(struct GTI2Connection *connection);
int gti2ConnectionThink(struct GTI2Connection *connection, unsigned int now);
void gti2CloseConnection(struct GTI2Connection *connection, int hard);


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
        gti2SendClosed(connection);
        gti2ClosedCallback(connection, 0);
        gti2FreeSocketConnection(connection);
    }
    else
    {
        connection->state = 6;
        gti2SendClose(connection);
    }
}
