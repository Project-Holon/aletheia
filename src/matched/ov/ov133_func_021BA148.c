/*
 * function: DUP_FITTING_ITEM_RemoveElem
 * address: 0x021BA148
 * packet: pkt_ov133_021BA148
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 */
#include "../include/Obj06504.h"
#include "../include/Obj06505.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void DUP_FITTING_ITEM_RemoveElem(u8*p,u8*q){u8 *prev;u8 *cur;prev=0;cur=*(u8* *)&((struct Obj06504 *)p)->f8;while(cur!=q && cur){prev=cur;cur=*(u8* *)&((struct Obj06505 *)cur)->f30;}if(cur){if(prev)*(u8* *)&((struct Obj06505 *)prev)->f30=*(u8* *)&((struct Obj06505 *)cur)->f30;else *(u8* *)&((struct Obj06504 *)p)->f8=*(u8* *)&((struct Obj06505 *)cur)->f30;if(*(u8* *)&((struct Obj06504 *)p)->fC==q)*(u8* *)&((struct Obj06504 *)p)->fC=prev;*(u8* *)&((struct Obj06505 *)cur)->f30=0;(((struct Obj06504 *)p)->f4)--;}}
