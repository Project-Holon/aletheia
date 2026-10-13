/*
 * function: GAME_BEACON_SEARCH_OnSessionStarted
 * address: 0x02164C04
 * packet: pkt_ov010_02164C04
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02010360 0x02010360 thumb
 */
#include "../include/Obj12363.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_02010360(int idx, void *heap);
void GAME_BEACON_SEARCH_OnSessionStarted(u8 *p){((struct Obj12363 *)p)->f4=1; ((struct Obj12363 *)p)->f80=func_02010360(4,(void *)0x8005);}
