/*
 * function: MUSICAL_MCSS_GetMonValue
 * address: 0x021F6744
 * packet: pkt_ov112_021F6744
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
int MUSICAL_MCSS_GetMonValue(void *p) {int r; r=0;if(POKE_TOOL_GetPartyValue(p,170,0)!=1)r=1;return r;}
