/*
 * function: gti2ConnectionMemoryError
 * address:  0x02195F70
 * packet:   pkt_ov009_02195F70
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectionMemoryError (gt2message.o)
 *
 * symbols:
 *   gti2SendClosed       0x02197BB8 arm
 *   gti2ConnectionError  0x02195EC4 arm
 */

struct GTI2Connection;

extern int gti2SendClosed(struct GTI2Connection *connection);
extern int gti2ConnectionError(struct GTI2Connection *connection,
                               int result, int reason);

static int gti2ConnectionMemoryError(struct GTI2Connection *connection)
{
    if (gti2SendClosed(connection) == 0)
        return 0;
    return gti2ConnectionError(connection, 1, 4);
}
