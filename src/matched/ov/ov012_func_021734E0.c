/*
 * function: func_021734E0
 * address: 0x021734E0
 * packet: pkt_ov012_021734E0
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020056EC 0x020056EC thumb
 *   func_02173524 0x02173524 thumb ov012
 */
#include "../include/Obj09357.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Work { struct { void *f0; } *head; } Work;
extern void func_02082BCC(void *p,u32 v,u32 n);
extern u32 func_020056EC(u32 range);
extern void func_02173524(Work *w,u8 *p);
void func_021734E0(Work *w) { u8 *p; p=(u8 *)w+0x2830; func_02082BCC(p,0,0x7c); ((struct Obj09357 *)p)->fC=func_020056EC(0xffff); p[0xf]=1; p[1]=2; func_02173524(w,p+0x14); }
