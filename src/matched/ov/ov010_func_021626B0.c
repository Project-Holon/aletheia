/*
 * function: func_021626B0
 * address:  0x021626B0
 * packet:   pkt_ov010_021626B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call wrapper over func_02162BCC (a pool word plus bx r3,
 * no prologue); witness for ov021 func_0218B2E8.
 *
 * symbols:
 *   func_02162BCC  0x02162BCC  thumb  ov010
 */

typedef unsigned short u16;

struct Box;
struct Q;
extern u16 func_02162BCC(struct Box *b, struct Q *q);

u16 func_021626B0(void *b, void *q)
{
    return func_02162BCC(b, q);
}
