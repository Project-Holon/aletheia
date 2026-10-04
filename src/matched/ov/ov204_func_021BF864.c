/*
 * function: func_021BF864
 * address: 0x021BF864
 * packet: pkt_ov204_021BF864
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021BF896 follow; no follower.
 * symbols:
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 */
#include "../include/Obj14628.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02015C30(void *,u32 *); extern void func_02015C48(void *,u32 *);
int func_021BF864(char *p,int delta,int limit) { u32 v[3]; int done; func_02015C30(((struct Obj14628 *)p)->f14,v); v[1]-=delta; if((int)v[1]<=limit) { v[1]=limit;done=1; } else done=0;func_02015C48(((struct Obj14628 *)p)->f14,v);return done; }
