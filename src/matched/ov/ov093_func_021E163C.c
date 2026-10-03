/*
 * function: func_021E163C
 * address:  0x021E163C
 * packet:   pkt_ov093_021E163C
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
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern u8 func_021D69AC(void *a, int i);
extern int func_021D76BC(int a, int b);

void func_021E163C(int a, int b, int c)
{
    if (c == func_021D775C(2) && func_021D69AC(func_021C7CF4(b, c), 0) >= 3)
        func_021D76BC(34, 26);
}
