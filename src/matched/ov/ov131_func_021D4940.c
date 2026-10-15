/*
 * function: P_STATUS_InitBgLayer
 * address: 0x021D4940
 * packet: pkt_ov131_021D4940
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned int u32;
struct BgConfig;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_PushTile(u32);
void P_STATUS_InitBgLayer(struct BgConfig *cfg,u32 bg,u32 mode)
{
    BG_SYS_InitBgLayer(bg,(const struct BgTemplate *)cfg,mode);
    func_02040588(bg,1);
    BG_SYS_FreeSlot(bg);
    BG_SYS_PushTile(bg);
}
