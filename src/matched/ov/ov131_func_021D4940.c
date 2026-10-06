/*
 * function: func_021D4940
 * address: 0x021D4940
 * packet: pkt_ov131_021D4940
 * region: ov131
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
typedef unsigned int u32;
struct BgConfig;
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
void func_021D4940(struct BgConfig *cfg,u32 bg,u32 mode)
{
    func_0203FCA0(bg,(const struct BgTemplate *)cfg,mode);
    func_02040588(bg,1);
    func_020414AC(bg);
    func_020409B4(bg);
}
