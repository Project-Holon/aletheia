/*
 * function: DUP_FITTING_ITEM_CreateList
 * address: 0x021BA0CC
 * packet: pkt_ov133_021BA0CC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021BA610 0x021BA610 data a4
 */
#include "../include/Obj06503.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char*,u16);
extern const char d_021BA610[];
u8 *DUP_FITTING_ITEM_CreateList(u16 heap, int n){u8 *p;p=func_02030734(heap,16,0,d_021BA610,76);((struct Obj06503 *)p)->f0=heap;((struct Obj06503 *)p)->f4=0;((struct Obj06503 *)p)->f6=n;((struct Obj06503 *)p)->f8=0;((struct Obj06503 *)p)->fC=0;return p;}
