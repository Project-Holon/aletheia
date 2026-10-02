/*
 * function: func_021E7300
 * address:  0x021E7300
 * packet:   pkt_ov093_021E7300
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);

void func_021E7300(int a, int b, int c)
{
    u8 k;

    if (c == func_021D775C(3)) {
        k = func_021D775C(4);
        func_021D76BC(0x3b, k);
    }
}
