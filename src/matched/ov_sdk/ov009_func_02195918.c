/*
 * function: gti2ConnectionThink
 * address:  0x02195918
 * packet:   pkt_ov009_02195918
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectionThink (gt2connection.o)
 *
 * symbols:
 *   gti2CheckTimeout     0x02195798  arm  ov009
 *   gti2CheckKeepAlive   0x021958E4  arm  ov009
 *   gti2SendRetries      0x0219583C  arm  ov009
 *   gti2CheckPendingAck  0x021958A8  arm  ov009
 */

struct GTI2Connection;

extern int gti2CheckTimeout(struct GTI2Connection *connection, unsigned int now);
extern int gti2CheckKeepAlive(struct GTI2Connection *connection,
                              unsigned int now);
extern int gti2SendRetries(struct GTI2Connection *connection, unsigned int now);
extern int gti2CheckPendingAck(struct GTI2Connection *connection,
                               unsigned int now);

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
