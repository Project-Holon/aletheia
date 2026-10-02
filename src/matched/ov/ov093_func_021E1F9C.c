/*
 * function: func_021E1F9C
 * address:  0x021E1F9C
 * packet:   pkt_ov093_021E1F9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C88A4(int a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(int a, void *p);

void func_021E1F9C(int u, int a, int b)
{
    u8 *s;

    if (b == func_021D775C(2)) {
        s = func_021C88A4(a, 4, b);
        func_021C8838(s + 4, 1, 0x77);
        func_021C88C8(a, s);
    }
}
