/*
 * function: MONOLITH_TOOL_MENU_InitBackgrounds
 * address: 0x021B8308
 * packet: pkt_ov071_021B8308
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02040588 0x02040588 arm
 *   d_021BA984 0x021BA984 data a4
 */

typedef unsigned char u8;
extern const char d_021BA984[];
typedef unsigned int   u32;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetTileEntry(unsigned,int,int,int,u8,u8,u8);
extern void func_02040588(unsigned char which, unsigned char enable);
void MONOLITH_TOOL_MENU_InitBackgrounds(void) { BG_SYS_InitBgLayer(5,(const struct BgTemplate *)d_021BA984,0); BG_SYS_SetTileEntry(5,0,0,0,0x20,0x20,0x11); func_02040588(5,0); }
