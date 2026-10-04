/*
 * function: func_021C9F8C
 * address: 0x021C9F8C
 * packet: pkt_ov128_021C9F8C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14048.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_02041300(u32,int,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32 bit);
static inline int ab(int x) { return x<0?-x:x; }
void func_021C9F8C(void *q,char *p) { func_02041300(3,0,ab(((struct Obj14048 *)p)->f0),ab(((struct Obj14048 *)p)->f2),32,24,0);func_02041B6C(3); }
