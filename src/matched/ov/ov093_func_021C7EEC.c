/*
 * function: BTL_SERVER_FLOW_GetPokeClientFrontCount
 * address: 0x021C7EEC
 * packet: pkt_ov093_021C7EEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_SERVER_GetClientChecked 0x021BB85C thumb ov093
 */
#include "../include/Obj21111.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u8 *BTL_SERVER_GetClientChecked(u8 *, unsigned int);
int BTL_SERVER_FLOW_GetPokeClientFrontCount(u8 *p, int i) { return BTL_SERVER_GetClientChecked(*(u8 * *)&((struct Obj21111 *)p)->f0, BTL_MAIN_PokeIdToClientIdThunk(i))[9]; }
