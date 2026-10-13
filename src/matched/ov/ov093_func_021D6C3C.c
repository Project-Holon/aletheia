/*
 * function: BTL_POKEPARAM_SetPokeParam
 * address: 0x021D6C3C
 * packet: pkt_ov093_021D6C3C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
void BTL_POKEPARAM_SetPokeParam(void **p,void *q) { POKE_TOOL_GetPartyValue(q,5,0); *p=q; }
