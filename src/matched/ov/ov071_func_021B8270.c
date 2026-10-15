/*
 * function: MONOLITH_TOOL_MENU_FreeButtons
 * address: 0x021B8270
 * packet: pkt_ov071_021B8270
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MONOLITH_TOOL_FreeButton 0x021B6B38 thumb ov071
 *   d_021BA978 0x021BA978 data a4
 */

extern unsigned d_021BA978[];
extern void MONOLITH_TOOL_FreeButton(void **p);
void MONOLITH_TOOL_MENU_FreeButtons(unsigned char *p) { unsigned i; for(i=0;i<d_021BA978[p[0x32]];i++) MONOLITH_TOOL_FreeButton((void **)(p+i*16)); }
