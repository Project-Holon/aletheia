/*
 * function: func_021C63D0
 * address:  0x021C63D0
 * packet:   pkt_ov093_021C63D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7A44  0x021D7A44  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021C1678  0x021C1678  thumb  ov093
 *   func_021C5540  0x021C5540  thumb  ov093
 *   func_021C16F8  0x021C16F8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021D78AC(u32 range);
extern u32 _u32_div_f(u32, u32);
extern int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d);
extern void func_021C5540(u8 *p, u8 *a, int c);
extern void func_021C16F8(u8 *p, u8 *q, int v);

u32 func_021C63D0(u8 *p, u8 *q)
{
    u16 dmg;
    int r;
    int a = func_021D59B4(q, 8);
    int b = func_021D59B4(q, 9);
    int c = func_021D59B4(q, 0xF);

    dmg = func_021D7A44(0x28, a, c, b);
    dmg = _u32_div_f((100 - func_021D78AC(16)) * dmg, 100);
    if (dmg == 0) {
        dmg = 1;
    }
    r = func_021C1678(p, q, q, 0, &dmg);
    func_021C5540(p, q, dmg);
    if (r != 0) {
        func_021C16F8(p, q, r);
    }
    return dmg;
}
