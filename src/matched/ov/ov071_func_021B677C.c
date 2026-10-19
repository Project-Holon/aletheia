/*
 * function: MONOLITH_TOOL_FreeSubBgChar
 * address: 0x021B677C
 * packet: pkt_ov071_021B677C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 */
typedef unsigned int u32;
extern void BG_SYS_FreeTileRun(u32, u32, u32);
void MONOLITH_TOOL_FreeSubBgChar(u32 *p)
{
    BG_SYS_FreeTileRun(7, p[0x138 / 4], 0x80);
}
