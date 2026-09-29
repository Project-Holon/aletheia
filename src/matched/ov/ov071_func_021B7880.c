/*
 * function: func_021B7880
 * address:  0x021B7880
 * packet:   pkt_ov071_021B7880
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   func_02040588  0x02040588  arm
 *   d_021BA8DC     0x021BA8DC  data  a4
 *   d_021BA8FC     0x021BA8FC  data  a4
 */

typedef unsigned int u32;

extern void func_0203FCA0(int a, void *p, int c);
extern void func_02041300(u32 layer, u32 tile, u32 x, u32 y, u32 w, u32 h, u32 mode);
extern void func_02040588(int a, int b);
extern char d_021BA8DC[];
extern char d_021BA8FC[];

void func_021B7880(void)
{
    func_0203FCA0(5, d_021BA8DC, 0);
    func_0203FCA0(6, d_021BA8FC, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02040588(5, 0);
}
