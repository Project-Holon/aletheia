/*
 * function: func_021E8878
 * address:  0x021E8878
 * packet:   pkt_ov093_021E8878
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021D76BC(int key, u32 val);

void func_021E8878(int a, int b, int c)
{
    if (func_021B9A24((u8)func_021D775C(2), c) != 0)
        func_021D76BC(0x51, 1);
}
