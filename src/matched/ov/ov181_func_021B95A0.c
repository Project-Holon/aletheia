/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov181_021B95A0
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes live r0 from 0203159C as the buffer pointer; its owner declaration is void.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj24498.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj0203159C;
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
int func_021B95A0(struct Obj0203159C *p,int unused,u32 v) { u8 *q; func_0203064C(1,142,0x125000); q=func_0203159C(p,756,142); func_02082BCC(q,0,756); ((struct Obj24498 *)q)->f0=v; return 1; }
