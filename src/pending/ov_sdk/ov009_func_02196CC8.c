/*
 * function: gti2HandleClosed
 * address:  0x02196CC8
 * packet:   pkt_ov009_02196CC8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gti2HandleClosed (gt2message.o)
 *
 * blocker: 56/56 bytes; same truthiness mechanism as gti2HandleClose
 *   (0x02196514): the original materialises the reason as
 *   `mov r2,#0; cmp r1,#6; movne r2,#1` (i.e. `state != 6`, default 1),
 *   while this front end emits `mov r2,#1; cmp r1,#6; moveq r2,#0`.
 *   The final moveq/movne pair is likewise swapped. No C spelling of the
 *   value or the return polarity reproduces the original's `!=` bias.
 *
 * symbols:
 *   gti2ConnectionError   0x02195ec4 arm
 */

struct GTI2Connection {
    unsigned char pad0[0xc];
    int state;
};

extern int gti2ConnectionError(struct GTI2Connection * connection, int result, int reason);

static int gti2HandleClosed(struct GTI2Connection * connection)
{
    if (connection->state == 7)
        return 1;
    if (gti2ConnectionError(connection, 2, (connection->state == 6) ? 0 : 1))
        return 1;
    return 0;
}
