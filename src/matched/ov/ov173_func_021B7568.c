/*
 * function: func_021B7568
 * address: 0x021B7568
 * packet: pkt_ov173_021B7568
 * region: ov173
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
u8 func_021B7568(void ***p) {u8 i;for(i=0;i<4;i++)if(!POKE_TOOL_GetPartyValue(**p,i+54,0))break;return i;}
