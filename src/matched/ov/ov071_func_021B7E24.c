/*
 * function: MONOLITH_TOOL_TITLE_FreeSlotIcons
 * address: 0x021B7E24
 * packet: pkt_ov071_021B7E24
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MONOLITH_TOOL_DeleteSlotIcon 0x021B6FD8 thumb ov071
 */

extern void MONOLITH_TOOL_DeleteSlotIcon(void *);
void MONOLITH_TOOL_TITLE_FreeSlotIcons(void **p) { int i; for(i=0;i<6;i++) MONOLITH_TOOL_DeleteSlotIcon(p[i+3]); }
