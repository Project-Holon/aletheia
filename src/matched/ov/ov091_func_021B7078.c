/*
 * function: func_021B7078
 * address: 0x021B7078
 * packet: pkt_ov091_021B7078
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int   u32;
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned,unsigned);
extern void func_020414AC(unsigned);
extern void func_020409B4(u32 index);
void func_021B7078(const void *p, unsigned id,unsigned type) { func_0203FCA0(id,p,type); func_02040588(id,1); func_020414AC(id); func_020409B4(id); }
