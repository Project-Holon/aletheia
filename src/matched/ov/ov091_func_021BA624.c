/*
 * function: POKELIST_SetHeldItem
 * address: 0x021BA624
 * packet: pkt_ov091_021BA624
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKELIST_ReturnBagItem 0x021BA688 thumb ov091
 *   POKELIST_RemoveBagItem 0x021BA670 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern u32 POKELIST_ReturnBagItem(u8 *,u16);
extern u32 POKELIST_RemoveBagItem(u8 *,u16);
void POKELIST_SetHeldItem(u8 *p, void *q, u16 id) { u32 old=POKE_TOOL_GetPartyValue(q,6,0); if(old) POKELIST_ReturnBagItem(p,old); POKE_TOOL_SetPartyValue(q,6,id); if(id) POKELIST_RemoveBagItem(p,id); }
