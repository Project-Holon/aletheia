/*
 * function: MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons
 * address: 0x021B7AC4
 * packet: pkt_ov071_021B7AC4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MONOLITH_TOOL_GetSlotIconStates 0x021B6F40 thumb ov071
 *   MONOLITH_TOOL_UpdateSlotIconState 0x021B6FE0 thumb ov071
 */
typedef unsigned char u8;
extern void *MONOLITH_TOOL_GetSlotIconStates(u8 **p);
extern void MONOLITH_TOOL_UpdateSlotIconState(void *,u8 *,int);
void MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons(void **p, void *q) { u8 *t;int i;t=MONOLITH_TOOL_GetSlotIconStates(q);for(i=0;i<6;i++)MONOLITH_TOOL_UpdateSlotIconState(p[i+3],t,i);}
