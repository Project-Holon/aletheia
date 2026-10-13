/*
 * function: BTL_SERVER_FLOW_QueryPokeClientFlag
 * address: 0x021C7ED8
 * packet: pkt_ov093_021C7ED8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_MAIN_GetClientVoiceFlag 0x021B997C thumb ov093
 */
#include "../include/Obj21110.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern int BTL_MAIN_GetClientVoiceFlag(u8 *, unsigned int);
int BTL_SERVER_FLOW_QueryPokeClientFlag(u8 *p, int i) { return BTL_MAIN_GetClientVoiceFlag(*(u8 * *)&((struct Obj21110 *)p)->f4, BTL_MAIN_PokeIdToClientIdThunk(i)); }
