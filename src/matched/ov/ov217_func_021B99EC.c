/*
 * function: func_021B99EC
 * address:  0x021B99EC
 * packet:   pkt_ov217_021B99EC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9850  0x021B9850  thumb  ov217
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_021B9850(const void *p);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);

void func_021B99EC(const void *p)
{
    u32 t = func_021B9850(p) / 10;
    u32 m = (u8)(t % 6);
    func_020413B0(5, 0, 0, 0x20, 0x18, (u8)m);
    func_020409B4(5);
}
