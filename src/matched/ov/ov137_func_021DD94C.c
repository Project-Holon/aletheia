/*
 * function: func_021DD94C
 * address: 0x021DD94C
 * packet: pkt_ov137_021DD94C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_021DE55C 0x021DE55C thumb ov137
 */
#include "../include/Obj14209.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(char *p);
extern int func_021DE55C(char *);
int func_021DD94C(char *p,int state) {if(func_021DE55C(p)) ((struct Obj14209 *)p)->f118=((struct Obj14209 *)p)->f11C;func_021DD924(p);return state;}
