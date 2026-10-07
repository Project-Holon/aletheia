/*
 * function: func_02154C20
 * address:  0x02154C20
 * packet:   pkt_ov006_02154C20
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callback adapter: unpacks a two-word argument block and tail-calls
 * func_02154BF8 (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Region
 * ov006: the only overlay mapped at this address; Thumb code directly after
 * the pool word of func_02154BF8, which is also its tail-call target.
 * ov021 func_021B4C54 passes it as a function pointer together with the block
 * {func_0201210C(..), 0} (wave A1 witness).
 *
 * symbols:
 *   func_02154BF8  0x02154BF8  thumb  ov006
 * Addresses are Black-image addresses.
 */

typedef struct Pair {
    int a;
    int b;
} Pair;

extern int func_02154BF8(int a, int b, int c);

int func_02154C20(int x, Pair *p)
{
    return func_02154BF8(x, p->a, p->b);
}
