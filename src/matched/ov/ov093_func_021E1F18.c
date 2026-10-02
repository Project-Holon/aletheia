/*
 * function: func_021E1F18
 * address:  0x021E1F18
 * packet:   pkt_ov093_021E1F18
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void func_021D7704(int a, int b);

void func_021E1F18(int u, int a, int b, int *p)
{
    if (*p == 2) {
        if (b == func_021D775C(3)) {
            if (func_021D775C(0x16) == 0xc)
                func_021D7704(0x31, 0x2000);
        }
    }
}
