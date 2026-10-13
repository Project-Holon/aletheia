/*
 * function: func_021DC860
 * address: 0x021DC860
 * packet: pkt_ov137_021DC860
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 */
#include "../include/Obj10612.h"
#include "../include/Obj23664.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern void *PROCSYS_Create(int a0);
int func_021DC860(void *obj,int a,u8 *ctx) { u8 *p=PROCSYS_AllocProcWork(obj,36,4); func_02082BCC(p,0,36); ((struct Obj10612 *)p)->f10=((struct Obj23664 *)ctx)->f4; ((struct Obj10612 *)p)->f8=ctx; ((struct Obj10612 *)p)->f20=PROCSYS_Create(1); return 1; }
