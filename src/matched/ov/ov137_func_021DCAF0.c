/*
 * function: GURU2_EntryStateDestroySession
 * address: 0x021DCAF0
 * packet: pkt_ov137_021DCAF0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_SessionDestroy 0x021DC90C thumb ov137
 */
#include "../include/Obj23669.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GURU2_SessionDestroy(u8 *p);
int GURU2_EntryStateDestroySession(u8 *p) {GURU2_SessionDestroy(((struct Obj23669 *)p)->fC);return 1;}
