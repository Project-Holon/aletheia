/*
 * function: BTL_SERVER_FLOW_GetPokeIdAtFieldIndex
 * address: 0x021C8020
 * packet: pkt_ov093_021C8020
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding follow.
 * symbols:
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
u8 BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(u8 *p, u8 v) { return BTL_POKEPARAM_GetPokeId((u8 *)BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj00003 *)p)->f8, v)); }
