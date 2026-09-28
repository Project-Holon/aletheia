/*
 * function: gti2HandleClose
 * address:  0x02196514
 * packet:   pkt_ov009_02196514
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gti2HandleClose (gt2message.o)
 *
 * blocker: 68/68 bytes; every instruction present, 5 differ only in the
 *   truthiness materialisation and the final moveq/movne swap. The
 *   original tests `state == 6` first with `movne r2,#1` (default reason
 *   = 1 when state != 6); this front end always materialises the `!=`
 *   form as default-1/`moveq r2,#0`, and no C spelling of the return
 *   (`!= 0`, `== 0 ? 0 : 1`, `!x`, `!!x`, `x != 0 ? 0 : 1`, bool) makes
 *   it pick the `!=` polarity. Tried all of those plus `!(state == 6)`.
 *   Caller gti2HandleReject (0x021964A8) is EXACT with the same callee.
 *
 * symbols:
 *   gti2SendClosed        0x02197bb8 arm
 *   gti2ConnectionError   0x02195ec4 arm
 */

struct GTI2Connection {
    unsigned char pad0[0xc];
    int state;
};

extern int gti2SendClosed(struct GTI2Connection * connection);
extern int gti2ConnectionError(struct GTI2Connection * connection, int result, int reason);

static int gti2HandleClose(struct GTI2Connection * connection)
{
    if (!gti2SendClosed(connection))
        return 0;
    if (gti2ConnectionError(connection, 2, (connection->state == 6) ? 0 : 1))
        return 1;
    return 0;
}
