/*
 * function: func_021B0ADC
 * address:  0x021B0ADC
 * packet:   pkt_ov021_021B0ADC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159144  0x02159144  thumb  ov010
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_0219129C  0x0219129C  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct Ent;
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern void func_0215A614(u8 *p, u32 v);
extern void func_02159144(int n);

void func_021B0ADC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    func_0215A614((u8 *)a, (u32)func_0219129C((u8 *)b, c, d, e, f, g));
    func_02159144(2);
}
