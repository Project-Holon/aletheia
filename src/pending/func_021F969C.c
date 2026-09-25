/*
 * function: func_021F969C
 * address:  0x021F969C
 * packet:   pkt_021F969C
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  codegen: the original makes an ordinary bl+pop call, svc3 TCOs it
 *           into ldr r3,[pc]; bx r3 (a sibling pool call).  Tried void/int
 *           return shapes; TCO persists.  Needs a source form that defeats
 *           sibling-call optimisation without adding bytes.
 *
 * symbols:
 *   func_020064B8  0x020064B8  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int func_020064B8(int, int, int);

int func_021F969C(char *p, int a, int b)
{
    return func_020064B8(a, b, *(int *)(p + 0x1e4));
}
