/*
 * unit: no
 * function: func_0220E27C
 * address: 0x0220E27C
 * packet: pkt_ov198_0220E27C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   func_0220B07C 0x0220B07C thumb ov196
 */
#include "../include/Obj25197.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {u8 lo:4,hi:4;} Bits4;
extern void func_0201F73C(void *,int,int,int);extern void func_0220B07C(void *);
void func_0220E27C(u8 *p){if(((Bits4 *)(p+0x2177))->hi==1){func_0201F73C(((struct Obj25197 *)p)->f1F60,2,1,14);func_0220B07C(p+0x1f60);((Bits4 *)(p+0x2177))->hi=0;}}
