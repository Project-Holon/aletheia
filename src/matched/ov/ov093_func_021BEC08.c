/*
 * function: BTL_SERVER_FLOW_IsPlayerSidePoke
 * address: 0x021BEC08
 * packet: pkt_ov093_021BEC08
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 */
#include "../include/Obj09965.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
int BTL_SERVER_FLOW_IsPlayerSidePoke(u8 *p,u8 *a)
{
    int n;
    n=BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(a));
    if(n==BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj09965 *)p)->f4)) return 1;
    return 0;
}
