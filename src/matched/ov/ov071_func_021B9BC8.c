/*
 * function: MONOLITH_TOOL_DeleteMarker
 * address: 0x021B9BC8
 * packet: pkt_ov071_021B9BC8
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MONOLITH_TOOL_DeleteBlink 0x021B70B8 thumb ov071
 */

extern void MONOLITH_TOOL_DeleteBlink(void **);
void MONOLITH_TOOL_DeleteMarker(char *p) { MONOLITH_TOOL_DeleteBlink((void **)(p + 0x298)); }
