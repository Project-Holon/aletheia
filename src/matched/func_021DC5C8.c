/*
 * function: func_021DC5C8
 * address:  0x021DC5C8
 * packet:   pkt_021DC5C8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note:     the listing extent (72 B) runs into the neighbour's `mov r8,r8`
 *           pad and pool word; all 48 compiled bytes match.
 *
 * symbols:
 *   func_021B9774   0x021B9774  thumb  ov114
 *   func_021B9838   0x021B9838  thumb  ov114
 *   func_021DAE18   0x021DAE18  thumb  ov175
 *
 * Kind 3 or 6 teardown of the +0x121c sub-object: its handle is unregistered
 * from both pools, the slot cleared, and the object recomputed.
 */

typedef unsigned int u32;

extern void func_021B9774(int h);
extern void func_021B9838(int h);
extern void func_021DAE18(void *p);

void func_021DC5C8(void *p, int unused, int kind)
{
    if (kind != 3 && kind != 6)
        return;
    if (*(u32 *)((char *)p + 0x121c) != 0) {
        func_021B9774(*(u32 *)((char *)p + 0x121c));
        func_021B9838(*(u32 *)((char *)p + 0x121c));
        *(u32 *)((char *)p + 0x121c) = 0;
    }
    func_021DAE18(p);
}
