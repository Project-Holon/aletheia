/*
 * function: func_021B98B8
 * address:  0x021B98B8
 * packet:   pkt_ov217_021B98B8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Hint note: d_021C2E60 data line carries no overlay token (contested hint).
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   d_021C2E30     0x021C2E30  data  ov217  a4
 *   d_021C2E60     0x021C2E60  data  a4
 *   d_021C2E40     0x021C2E40  data  ov217  a4
 *   d_021C2E80     0x021C2E80  data  ov217  a4
 */

extern void func_0203F8F4(unsigned short heapId);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, u32 enable);
extern int d_021C2E30;
extern int d_021C2E60;
extern int d_021C2E40;
extern int d_021C2E80;

void func_021B98B8(unsigned short heapId)
{
    func_0203F8F4(heapId);
    func_0203FC28((struct DispConfig *)(&d_021C2E30));
    func_0203FCA0(4, (const struct BgTemplate *)(&d_021C2E60), 0);
    func_0203FCA0(5, (const struct BgTemplate *)(&d_021C2E40), 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_0203FCA0(1, (const struct BgTemplate *)(&d_021C2E80), 0);
    func_02040588(1, 1);
}