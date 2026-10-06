/*
 * function: func_021BD820
 * address:  0x021BD820
 * packet:   pkt_ov172_021BD820
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned int u32;
struct BgTemplate;

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32 which);
extern void func_020409B4(u32 index);

void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type)
{
    func_0203FCA0(bgId, tmpl, type);
    func_02040588(bgId, 1);
    func_020414AC(bgId);
    func_020409B4(bgId);
}
