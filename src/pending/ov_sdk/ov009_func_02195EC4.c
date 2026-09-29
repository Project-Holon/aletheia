/*
 * function: gti2ConnectionError
 * address:  0x02195EC4
 * packet:   pkt_ov009_02195EC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * blocker: gti2ConnectedCallback branch if-converted (movne) and return-1 blocks unmerged; 156 vs 152 B
 * status:   DIFF
 *
 * w9_nm: not reached this wave.
 *
 * sdk:      gti2ConnectionError (gt2message.o)
 *
 * symbols:
 *   gti2ConnectionClosed   0x021959D0 arm
 *   gti2ConnectedCallback  0x0219500C arm
 *   gti2ClosedCallback     0x02195158 arm
 */

struct GTI2Connection;

extern void gti2ConnectionClosed(struct GTI2Connection *connection);
extern int gti2ConnectedCallback(struct GTI2Connection *connection, int result,
                                 unsigned char *message, int len);
extern int gti2ClosedCallback(struct GTI2Connection *connection, int reason);

struct GTI2Connection {
    char pad00[8];
    void *socket;
    int state;
    int field_10;
    int field_14;
};

static int gti2ConnectionError(struct GTI2Connection *connection,
                               int result, int reason)
{
    if (connection->state < 5)
    {
        if (connection->field_10 != 0)
        {
            gti2ConnectionClosed(connection);
            reason = 0;
            if (gti2ConnectedCallback(connection, result, 0, 0))
                return 1;
            return 0;
        }
        if (connection->state == 4)
            connection->field_14 = 1;
        gti2ConnectionClosed(connection);
    }
    else
    {
        if (connection->state == 7)
            return 1;
        gti2ConnectionClosed(connection);
        if (gti2ClosedCallback(connection, reason) == 0)
            return 0;
    }
    return 1;
}
