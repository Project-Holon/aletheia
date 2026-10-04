/*
 * function: func_021542C0
 * address:  0x021542C0
 * packet:   pkt_ov007_021542C0
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callback adapter: unpacks a two-word argument block and tail-calls
 * func_021542CC (docs/idioms/tail-call-is-a-pool-word-and-bx.md), the twin of
 * ov006 func_02154C20. Region ov007; Thumb code directly before its pool word.
 * ov021 func_021CA5C4 passes it to func_020124AC with the ov007
 * id (pool word at 0x021CB23C).
 *
 * symbols:
 *   func_021542CC  0x021542CC  thumb  ov007
 * Addresses are Black-image addresses.
 */

typedef struct Pair {
    int a;
    int b;
} Pair;

extern void *func_021542CC(void *p, int a, int b);

int func_021542C0(int x, Pair *p)
{
    return (int)func_021542CC((void *)x, p->a, p->b);
}
