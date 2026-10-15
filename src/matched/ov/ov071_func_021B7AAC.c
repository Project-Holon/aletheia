/*
 * function: MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons
 * address: 0x021B7AAC
 * packet: pkt_ov071_021B7AAC
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
void MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons(void **p) { int i; for(i=0;i<6;i++) MONOLITH_TOOL_DeleteSlotIcon(p[i+3]); }
