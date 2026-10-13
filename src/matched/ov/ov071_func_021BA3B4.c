/*
 * function: MONOLITH_TOOL_SetupInfoBgs
 * address:  0x021BA3B4
 * packet:   pkt_ov071_021BA3B4
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
 *   gMonolithInfoBgTemplate0     0x021BAB94  data  a4
 *   gMonolithInfoBgTemplate2     0x021BABB4  data  a4
 */

extern char gMonolithInfoBgTemplate0[];
extern char gMonolithInfoBgTemplate2[];

typedef unsigned int   u32;
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(int a, int b, int c, int d, int e, int f, int g);

void MONOLITH_TOOL_SetupInfoBgs(void)
{
    func_0203FCA0(0, (const struct BgTemplate *)gMonolithInfoBgTemplate0, 0);
    func_0203FCA0(2, (const struct BgTemplate *)gMonolithInfoBgTemplate2, 0);
    func_02041300(0, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
}
