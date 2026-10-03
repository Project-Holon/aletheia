/*
 * function: func_021E0E00
 * address:  0x021E0E00
 * packet:   pkt_ov093_021E0E00
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
 *   func_021D80A8  0x021D80A8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern int func_021D80A8(void *p);
extern int func_021D76BC(int a, int b);

void func_021E0E00(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(27, func_021D80A8(func_021C7CF4(b, c)));
}
