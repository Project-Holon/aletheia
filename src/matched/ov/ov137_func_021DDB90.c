/*
 * function: func_021DDB90
 * address: 0x021DDB90
 * packet: pkt_ov137_021DDB90
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_021DD93C 0x021DD93C thumb ov137
 */
#include "../include/Obj23722.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(void *);
extern void func_021DD93C(char *,int);
int func_021DDB90(char *p,int state) {((struct Obj23722 *)p)->f4810=0;func_021DD93C(p,0);func_021DD924(p);return state;}
