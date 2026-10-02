/*
 * function: func_021E1DF4
 * address:  0x021E1DF4
 * packet:   pkt_ov093_021E1DF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void func_021C88B4(void *a, int k, int b);

void func_021E1DF4(int u, void *a, int b)
{
    if (b == func_021D775C(2))
        func_021C88B4(a, 0x3b, b);
}
