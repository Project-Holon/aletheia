/*
 * function: BTL_CALC_CalcPrizeMoney
 * address: 0x021D7F88
 * packet: pkt_ov093_021D7F88
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CALC_CalcTrainerPrizeMoney 0x021D7FBC thumb ov093
 */
#include "../include/Obj03204.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_CALC_CalcTrainerPrizeMoney(void **,void *);
u32 BTL_CALC_CalcPrizeMoney(u8 *p) { u32 n=0; if(((struct Obj03204 *)p)->f0==1) { if(((struct Obj03204 *)p)->f4C && ((struct Obj03204 *)p)->f28) n+=BTL_CALC_CalcTrainerPrizeMoney(((struct Obj03204 *)p)->f4C,((struct Obj03204 *)p)->f28); if(((struct Obj03204 *)p)->f54 && ((struct Obj03204 *)p)->f30) n+=BTL_CALC_CalcTrainerPrizeMoney(((struct Obj03204 *)p)->f54,((struct Obj03204 *)p)->f30); } return n; }
