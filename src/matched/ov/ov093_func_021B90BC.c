/*
 * function: BTL_MAIN_AddItemToBag
 * address: 0x021B90BC
 * packet: pkt_ov093_021B90BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007E50 0x02007E50 thumb
 */
#include "../include/Obj09939.h"
#include "../include/Obj13273.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02007E50(void *,u32,int,u16);
void BTL_MAIN_AddItemToBag(u8 *p,u8 k,u32 x) { u8 *q; q=*(u8 * *)&((struct Obj09939 *)p)->f0; if(q[0x23]==0 && k==p[0x46c]) func_02007E50(((struct Obj13273 *)q)->f60,x,1,((struct Obj09939 *)p)->f468); }
