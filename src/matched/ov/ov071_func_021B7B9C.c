/*
 * function: MONOLITH_TOOL_SLOT_SELECT_FreeButtons
 * address: 0x021B7B9C
 * packet: pkt_ov071_021B7B9C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MONOLITH_TOOL_FreeButton 0x021B6B38 thumb ov071
 */

extern void MONOLITH_TOOL_FreeButton(void **p);
void MONOLITH_TOOL_SLOT_SELECT_FreeButtons(char *p) { int i; p += 0x2c; for (i=0;i<2;i++) MONOLITH_TOOL_FreeButton((void **)(p+i*16)); }
