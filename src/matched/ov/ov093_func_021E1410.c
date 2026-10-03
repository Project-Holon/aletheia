/*
 * function: func_021E1410
 * address:  0x021E1410
 * packet:   pkt_ov093_021E1410
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

extern int func_021D775C(int key);
typedef unsigned int   u32;
extern int func_021D76BC(int key, u32 val);

void func_021E1410(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(33) == 4)
        func_021D76BC(66, 0);
}
