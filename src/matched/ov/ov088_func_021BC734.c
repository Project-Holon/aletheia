/*
 * function: STARTMENU_InitBgLayer
 * address: 0x021BC734
 * packet: pkt_ov088_021BC734
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned int   u32;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(int a);
extern void BG_SYS_PushTile(unsigned int a);
void STARTMENU_InitBgLayer(const void *p,int bg) { BG_SYS_InitBgLayer(bg,p,0);func_02040588(bg,1);BG_SYS_FreeSlot(bg);BG_SYS_PushTile(bg); }
