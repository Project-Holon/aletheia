/*
 * function: func_02162564
 * address: 0x02162564
 * packet: pkt_ov010_02162564
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: same shape as func_02162598 with the callee func_02162D2C.
 * symbols:
 *   func_02162D2C 0x02162D2C thumb ov010
 */
#include "../include/Obj12338.h"
typedef unsigned short u16;
struct Box; struct Q;
extern int func_02162D2C(struct Box *, struct Q *);
int func_02162564(char *p, struct Q *q) { int i; char *r; i=0; r=*(char * *)&((struct Obj12338 *)p)->f24; for(;i<((struct Obj12338 *)p)->f16;i++,r+=20) { if(func_02162D2C((struct Box *)r,q)) return i; } return 0xffff; }
