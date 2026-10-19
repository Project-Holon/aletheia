/*
 * function: BTL_MAIN_RemoveItemFromBag
 * address: 0x021B9090
 * packet: pkt_ov093_021B9090
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007F1C 0x02007F1C thumb
 */
#include "../include/Obj09938.h"
#include "../include/Obj13272.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02007F1C(void *,u32,int,u16);
void BTL_MAIN_RemoveItemFromBag(u8 *p, u32 k, u32 x) { u8 *q; q=*(u8 * *)&((struct Obj09938 *)p)->f0; if(q[0x23]==0 && k==p[0x46c]) func_02007F1C(((struct Obj13272 *)q)->f60,x,1,((struct Obj09938 *)p)->f468); }
