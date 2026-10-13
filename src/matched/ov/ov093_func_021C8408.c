/*
 * function: BTL_SERVER_FLOW_TryFinishMainCounter
 * address: 0x021C8408
 * packet: pkt_ov093_021C8408
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_SERVER_FinishMainCounter 0x021BB914 thumb ov093
 */
#include "../include/Obj09974.h"
typedef unsigned char u8;
extern void *BTL_MAIN_GetCompetitor(void ***);
typedef unsigned int   u32;
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern void BTL_SERVER_FinishMainCounter(int *);
void BTL_SERVER_FLOW_TryFinishMainCounter(u8 *p, int a)
{
    unsigned int t = (unsigned int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj09974 *)p)->f4);
    int k = BTL_MAIN_PokeIdToClientIdThunk(a);
    if (t <= 1 && k == BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj09974 *)p)->f4)) BTL_SERVER_FinishMainCounter(*(int * *)&((struct Obj09974 *)p)->f0);
}
