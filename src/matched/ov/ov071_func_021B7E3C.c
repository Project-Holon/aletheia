/*
 * function: MONOLITH_TOOL_TITLE_UpdateSlotIcons
 * address: 0x021B7E3C
 * packet: pkt_ov071_021B7E3C
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

typedef unsigned char  u8;
extern void *MONOLITH_TOOL_GetSlotIconStates(u8 **p);
extern void MONOLITH_TOOL_UpdateSlotIconState(void *,unsigned char *,int);
void MONOLITH_TOOL_TITLE_UpdateSlotIcons(void **a,void *p) { int i; unsigned char *t; t=MONOLITH_TOOL_GetSlotIconStates(p); for(i=0;i<6;i++) MONOLITH_TOOL_UpdateSlotIconState(a[i+3],t,i); }
