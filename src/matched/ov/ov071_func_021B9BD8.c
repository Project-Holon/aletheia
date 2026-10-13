/*
 * function: MONOLITH_TOOL_UpdateMarker
 * address: 0x021B9BD8
 * packet: pkt_ov071_021B9BD8
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MONOLITH_TOOL_UpdateBlink 0x021B70C4 thumb ov071
 */

extern void MONOLITH_TOOL_UpdateBlink(void *);
void MONOLITH_TOOL_UpdateMarker(char *p) { MONOLITH_TOOL_UpdateBlink(p + 0x298); }
