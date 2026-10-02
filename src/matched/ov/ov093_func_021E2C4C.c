/*
 * function: func_021E2C4C
 * address:  0x021E2C4C
 * packet:   pkt_ov093_021E2C4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7AF0  0x021D7AF0  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D7AF0(u32 pct);
extern int func_021D76BC(int a, int b);
extern void func_021C83DC(void *a, int k);

void func_021E2C4C(int u, void *a, int b, int *p)
{
    if (b == func_021D775C(3)) {
        if (func_021D7AF0(0x14) != 0)
            *p = func_021D76BC(0x51, 1);
        func_021C83DC(a, (u8)(*p != 0));
    }
}
