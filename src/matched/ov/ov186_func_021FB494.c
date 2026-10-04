/*
 * function: func_021FB494
 * address: 0x021FB494
 * packet: pkt_ov186_021FB494
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10785.h"
struct Grid; struct Obj020437AC; struct Obj;
extern void func_0202570C(struct Grid *);
extern void func_020437AC(struct Obj020437AC *);
extern void func_0204B3B4(struct Obj *);
extern void func_020307B0(void *);
void func_021FB494(char *p) { func_0202570C(*(struct Grid * *)&((struct Obj10785 *)p)->f4);func_020437AC(*(struct Obj020437AC * *)&((struct Obj10785 *)p)->f8);func_0204B3B4(*(struct Obj * *)&((struct Obj10785 *)p)->f0);func_020307B0(p); }
