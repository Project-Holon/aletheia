/*
 * function: func_021E3E00
 * address:  0x021E3E00
 * packet:   pkt_ov093_021E3E00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);

void func_021E3E00(int u, int a, int b, int *p)
{
    if (b == func_021D775C(4)) {
        if (func_021D775C(0x46) == 0) {
            if (p[6] != 0)
                p[1] += func_021D775C(0x32);
        }
    }
}
