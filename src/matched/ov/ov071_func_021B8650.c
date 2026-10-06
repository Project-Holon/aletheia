/*
 * function: func_021B8650
 * address:  0x021B8650
 * packet:   pkt_ov071_021B8650
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   d_021BAA64     0x021BAA64  data  a4
 *   d_021BAA84     0x021BAA84  data  a4
 */

extern char d_021BAA64[];
extern char d_021BAA84[];

typedef unsigned int   u32;
struct BgTemplate;
void func_021B8650(void)
{
    extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
    extern void func_02041300(int, int, int, int, int, int, int);

    func_0203FCA0(0, (const struct BgTemplate *)d_021BAA64, 0);
    func_0203FCA0(2, (const struct BgTemplate *)d_021BAA84, 0);
    func_02041300(0, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
}
