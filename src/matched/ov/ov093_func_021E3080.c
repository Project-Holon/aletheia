/*
 * function: func_021E3080
 * address:  0x021E3080
 * packet:   pkt_ov093_021E3080
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
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);

void func_021E3080(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021D775C(0x21) == 3)
            func_021D76BC(0x42, 0);
    }
}
