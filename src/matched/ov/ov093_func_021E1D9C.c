/*
 * function: func_021E1D9C
 * address:  0x021E1D9C
 * packet:   pkt_ov093_021E1D9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C830C  0x021C830C  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern unsigned int func_021C830C(u8 *p);
extern void func_021E8860(int a);

void func_021E1D9C(int u, void *a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021C830C(a) != 0)
            func_021E8860(2);
    }
}
