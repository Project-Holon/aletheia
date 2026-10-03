/*
 * function: func_021E1FCC
 * address:  0x021E1FCC
 * packet:   pkt_ov093_021E1FCC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u16 func_021D70A8(void *p);
extern int func_021D76BC(int a, int b);

void func_021E1FCC(void *u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021D775C(0x12) == func_021D70A8(u))
            func_021D76BC(0x40, 0);
    }
}
