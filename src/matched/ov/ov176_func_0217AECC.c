/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_IsFinished
 * address: 0x0217AECC
 * packet: pkt_ov176_0217AECC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic 0x0217AF14 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_UpdateText 0x0217AFBC thumb ov176
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback 0x021E8A80 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull 0x021E8A90 thumb ov177
 */
#include "../include/Obj04561.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {void (*fn)(void *);} CB;
extern void BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(int *),BATTLE_CHAMPIONSHIP_FLOW_UpdateText(int *),WIFIBATTLEMATCH_UTIL_InvokeCallback(CB *);
extern int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **);
int BATTLE_CHAMPIONSHIP_FLOW_IsFinished(u32 a,u32 b,u32 c,int *p) {BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(p);BATTLE_CHAMPIONSHIP_FLOW_UpdateText(p);WIFIBATTLEMATCH_UTIL_InvokeCallback(*(CB * *)&((struct Obj04561 *)p)->f4);if(WIFIBATTLEMATCH_UTIL_IsCallbackNull(*(int ** *)&((struct Obj04561 *)p)->f4)) return 1;return 0;}
