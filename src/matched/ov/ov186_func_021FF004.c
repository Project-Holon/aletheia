/*
 * function: func_021FF004
 * address: 0x021FF004
 * packet: pkt_ov186_021FF004
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj24851.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
extern void func_02082BCC(void *,int,unsigned);
void func_021FF004(u8 *p){CLACT_DeleteActor(*(struct Obj * *)&((struct Obj24851 *)p)->f4);func_02082BCC(p,0,76);}
