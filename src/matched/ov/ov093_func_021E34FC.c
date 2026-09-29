/*
 * unit:     yes
 * function: func_021E34FC, func_021E3544
 * address:  0x021E34FC
 * packet:   pkt_ov093_021E34FC
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
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E8798  0x021E8798  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(void *l, u32 v);
extern void func_021C88C8(void *a, void *b);
extern void func_021E8798(int a, int b, int c, int d);

void func_021E34FC(int u, void *p, int key, int *o)
{
    u8 *q;
    if (key == func_021D775C(3) && o[6] == 0) {
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 2, 761);
        func_021C8860(q + 4, key);
        func_021C88C8(p, q);
        o[6] = 1;
    }
}

void func_021E3544(int a, int b, int c, int d)
{
    func_021E8798(a, b, c, d);
}
