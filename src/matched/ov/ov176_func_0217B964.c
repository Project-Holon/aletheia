/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone
 * address: 0x0217B964
 * packet: pkt_ov176_0217B964
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 */
#include "../include/Obj01762.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *p) {return WIFIBATTLEMATCH_UTIL_GetBusy(*(int * *)&((struct Obj01762 *)p)->f18);}
