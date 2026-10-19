/*
 * function: MONOLITH_TOOL_LIST_FreeBgChar
 * address: 0x021B9694
 * packet: pkt_ov071_021B9694
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 */

extern void BG_SYS_FreeTileRun(unsigned int, unsigned int, unsigned int);
void MONOLITH_TOOL_LIST_FreeBgChar(unsigned int *p) { BG_SYS_FreeTileRun(5, p[1], 0x80); }
