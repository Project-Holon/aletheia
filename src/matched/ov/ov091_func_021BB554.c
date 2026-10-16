/*
 * function: PLIST_PLATE_GetHpBarColor
 * address: 0x021BB554
 * packet: pkt_ov091_021BB554
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 */
#include "../include/Obj03680.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern int BGWINFRM_GetScaleRank(u32 a, u32 b);
int PLIST_PLATE_GetHpBarColor(u32 p) { return BGWINFRM_GetScaleRank(((struct Obj03680 *)p)->f6,POKE_TOOL_GetPartyValue(((struct Obj03680 *)p)->f0,0xa1,0)); }
