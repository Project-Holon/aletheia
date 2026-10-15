/*
 * function: CTVT_CALL_InitBgLayer
 * address:  0x021BD820
 * packet:   pkt_ov172_021BD820
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm  arm9
 *   BG_SYS_FreeSlot  0x020414AC  arm  arm9
 *   BG_SYS_PushTile  0x020409B4  arm  arm9
 */

typedef unsigned int u32;
struct BgTemplate;

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(u32 which);
extern void BG_SYS_PushTile(u32 index);

void CTVT_CALL_InitBgLayer(const struct BgTemplate *tmpl, u32 bgId, u32 type)
{
    BG_SYS_InitBgLayer(bgId, tmpl, type);
    func_02040588(bgId, 1);
    BG_SYS_FreeSlot(bgId);
    BG_SYS_PushTile(bgId);
}
