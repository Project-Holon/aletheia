/*
 * function: func_021542C0
 * address:  0x021542C0
 * packet:   pkt_ov004_021542C0
 * region:   ov004
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callback adapter: unpacks a two-word argument block and tail-calls
 * EVENT_WORLDTRADE_Create (docs/idioms/tail-call-is-a-pool-word-and-bx.md), the twin of
 * ov006 func_02154C20. Region ov004; Thumb code directly before its pool word.
 * ov021 func_021B4C98 holds its address in the pool word at 0x021B4CD8,
 * next to overlay id 4.
 *
 * symbols:
 *   EVENT_WORLDTRADE_Create  0x021542CC  thumb  ov004
 * Addresses are Black-image addresses.
 */

typedef struct Pair {
    int a;
    int b;
} Pair;

extern int EVENT_WORLDTRADE_Create(int a, int b, int c);

int func_021542C0(int x, Pair *p)
{
    return EVENT_WORLDTRADE_Create(x, p->a, p->b);
}
