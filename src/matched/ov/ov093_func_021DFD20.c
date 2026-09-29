/*
 * function: func_021DFD20
 * address:  0x021DFD20
 * packet:   pkt_ov093_021DFD20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern int func_021D5D14(void *m, u32 e, int d);
extern void func_021DD044(int a, int b, int c);

void func_021DFD20(int self, int q, int id)
{
    if (id != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    if (func_021D775C(0x16) != 10)
        return;
    if (func_021D5D14(func_021C7CF4(q, id), 3, 1) == 0)
        return;
    func_021DD044(self, q, id);
}
