/*
 * function: func_0203B1B0
 * address:  0x0203B1B0
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper over func_0203AD80 (the object at 0x021469DC, the
 * callback func_0203B170, 0, 0x1BC).  An unlabelled ARM leaf, filed as the
 * witness chain for func_0203D010 (state 10 of func_0203DC70).
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203B170  0x0203B170  arm
 *   func_0203AD80  0x0203AD80  arm
 */

extern void *g_021469DC;
extern void func_0203B170(void);
extern void func_0203AD80(void *obj, void (*fn)(void), int a, int b);

void func_0203B1B0(void)
{
    func_0203AD80(g_021469DC, func_0203B170, 0, 0x1BC);
}
