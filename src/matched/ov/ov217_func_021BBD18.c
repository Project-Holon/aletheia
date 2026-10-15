/*
 * function: RESEARCH_LIST_SetEntryPaletteIdle
 * address:  0x021BBD18
 * packet:   pkt_021BBD18
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_LIST_GetOamObject  0x021BC740  thumb  ov217
 *   BMP_OAM_SetPalette  0x02025A54  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int RESEARCH_LIST_GetOamObject(char *p, int i);
extern void BMP_OAM_SetPalette(u8 *g, u32 a);

void RESEARCH_LIST_SetEntryPaletteIdle(int a, int b)
{
    BMP_OAM_SetPalette((u8 *)RESEARCH_LIST_GetOamObject((char *)a, b), 0);
}
