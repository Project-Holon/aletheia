/*
 * function: MONOLITH_TOOL_SUMMARY_InitBackgrounds
 * address:  0x021B8650
 * packet:   pkt_ov071_021B8650
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   d_021BAA64     0x021BAA64  data  a4
 *   d_021BAA84     0x021BAA84  data  a4
 */

extern char d_021BAA64[];
extern char d_021BAA84[];

typedef unsigned int   u32;
struct BgTemplate;
void MONOLITH_TOOL_SUMMARY_InitBackgrounds(void)
{
    extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
    extern void BG_SYS_SetTileEntry(int, int, int, int, int, int, int);

    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)d_021BAA64, 0);
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)d_021BAA84, 0);
    BG_SYS_SetTileEntry(0, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
}
