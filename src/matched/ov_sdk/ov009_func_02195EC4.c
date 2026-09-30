/*
 * function: gti2ConnectionError
 * address:  0x02195EC4
 * packet:   pkt_ov009_02195EC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectionError (gt2message.o, libdwcgsgt2.TWL.HYB.a)
 *
 * The connection's error path. Below state 5 an established callback is
 * torn down and gti2ConnectedCallback is told the result (reason is zeroed);
 * at or above it, state 7 is already terminal and otherwise the closed
 * callback decides. Every path but the two zero returns funnels into ONE
 * `mov r0, #1; pop` tail at 0x02195F54, which is what the shape below buys:
 *
 * w10_t2: the parked body was 156 B / 44 concrete bytes out because 1.1p1
 * IF-CONVERTED both `return 1` sites (movne r4,#1 at +0x48, moveq r0,#1 /
 * popeq at +0x70) where the image BRANCHES to the shared tail (bne / beq
 * 0x02195F54). Two levers close it, both body shape and neither a pin:
 *   (a) `if (state != 7) { ...closed...; closedCallback... }` instead of
 *       `if (state == 7) return 1;` -- inverting the guard makes the arms
 *       share the function's single trailing `return 1` rather than each
 *       materialising its own 1;
 *   (b) the inner pair written `if (gti2ConnectedCallback(...) == 0)
 *       return 0; goto ret1;` with `ret1:` on the function's last statement.
 *       `if (cb(...)) return 1; return 0;`, `if (cb(...) != 0) return 1;`,
 *       `int r = cb(...); if (r) return 1;` and a `goto`-free spelling all
 *       leave the bne if-converted to `movne r4, #1` (152 B, 4 bytes out);
 *       the labelled jump is what makes the compiler keep the branch.
 *
 * symbols:
 *   gti2ConnectionClosed   0x021959D0  arm  ov009
 *   gti2ConnectedCallback  0x0219500C  arm  ov009
 *   gti2ClosedCallback     0x02195158  arm  ov009
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
            if (gti2ConnectedCallback(connection, result, 0, 0) == 0)
                return 0;
            goto ret1;
        }
        if (connection->state == 4)
            connection->field_14 = 1;
        gti2ConnectionClosed(connection);
    }
    else
    {
        if (connection->state != 7)
        {
            gti2ConnectionClosed(connection);
            if (gti2ClosedCallback(connection, reason) == 0)
                return 0;
        }
    }
ret1:
    return 1;
}
