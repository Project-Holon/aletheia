/*
 * function: func_021E101C
 * address:  0x021E101C
 * packet:   pkt_ov093_021E101C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern int func_021D62C4(void *p, int i);
extern int func_021D76BC(int a, int b);

void func_021E101C(int a, int b, int c)
{
    int n;

    if (c != func_021D775C(3))
        return;
    n = (unsigned char)func_021D775C(4);
    if (func_021D62C4(func_021C7CF4(b, n), 2) == 0)
        func_021D76BC(64, 1);
}
