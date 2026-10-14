/*
 * function: ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault
 * address: 0x021BC610
 * packet: pkt_ov208_021BC610
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_DETAIL_COMMON_CreatePaletteAnim 0x021BC560 thumb
 */
typedef unsigned int u32;
extern void *ZUKAN_DETAIL_COMMON_CreatePaletteAnim(u32 heap, unsigned short mask);
void *ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(u32 heap)
{
    return ZUKAN_DETAIL_COMMON_CreatePaletteAnim(heap, 0xf);
}
