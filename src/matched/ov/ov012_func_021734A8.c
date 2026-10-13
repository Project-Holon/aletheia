/*
 * function: UNION_COMM_SetSituationParam
 * address: 0x021734A8
 * packet: pkt_ov012_021734A8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj05917.h"
typedef unsigned char u8;
typedef unsigned int u32;
void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v) { u8 *p; p=self+0x2830; switch(id) { case 0: ((struct Obj05917 *)p)->f14=v; return; case 1: ((struct Obj05917 *)p)->f18=v; return; case 2: ((struct Obj05917 *)p)->f1C=v; return; case 3: ((struct Obj05917 *)p)->f20=v; return; case 4: *p=v; } }
