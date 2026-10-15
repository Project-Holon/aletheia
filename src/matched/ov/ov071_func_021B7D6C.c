/*
 * function: MONOLITH_TOOL_TITLE_InitBackgrounds
 * address: 0x021B7D6C
 * packet: pkt_ov071_021B7D6C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   d_021BA928 0x021BA928 data a4
 */

typedef unsigned char u8;
extern const char d_021BA928[];
typedef unsigned int   u32;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetTileEntry(unsigned,int,int,int,u8,u8,u8);
void MONOLITH_TOOL_TITLE_InitBackgrounds(void) { BG_SYS_InitBgLayer(2,(const struct BgTemplate *)d_021BA928,0); BG_SYS_SetTileEntry(2,0,0,0,0x20,0x20,0x11); }
