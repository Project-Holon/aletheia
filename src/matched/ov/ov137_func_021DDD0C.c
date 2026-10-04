/*
 * function: func_021DDD0C
 * address: 0x021DDD0C
 * packet: pkt_ov137_021DDD0C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_0202208C 0x0202208C thumb
 */
#include "../include/Obj23724.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(void *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
int func_021DDD0C(char *p,int state) {if(++((struct Obj23724 *)p)->f124>60) {func_0202208C(0,0,0,0,16,1,114);state=3;}func_021DD924(p);return state;}
