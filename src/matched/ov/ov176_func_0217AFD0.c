/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_SelectFlow, BATTLE_CHAMPIONSHIP_FLOW_End
 * address: 0x0217AFD0
 * packet: pkt_ov176_0217AFD0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * unit: yes
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_StartMenu 0x0217B0C8 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch 0x0217B1BC thumb ov176
 */
#include "../include/Obj24399.h"
#include "../include/Obj24400.h"
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int a);
extern void BATTLE_CHAMPIONSHIP_FLOW_StartMenu(int *a, int *state, int *p);
extern void BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch(int *a, int *state, int *p);
void BATTLE_CHAMPIONSHIP_FLOW_SelectFlow(void *a,int b,char *p)
{
    switch(((struct Obj24400 *)(*(char * *)&((struct Obj24399 *)p)->f28))->f4){
    case 0: case 1: case 2:
        WIFIBATTLEMATCH_UTIL_SetCallback(a,(int)BATTLE_CHAMPIONSHIP_FLOW_StartMenu); break;
    case 3: case 4: case 5: case 6:
        WIFIBATTLEMATCH_UTIL_SetCallback(a,(int)BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch); break;
    }
}
void BATTLE_CHAMPIONSHIP_FLOW_End(void *a)
{
    WIFIBATTLEMATCH_UTIL_ClearCallback((int)a);
}
