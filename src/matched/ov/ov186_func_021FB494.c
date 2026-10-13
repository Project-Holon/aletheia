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
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10785.h"
struct Grid; struct Obj020437AC; struct Obj;
extern void BMP_OAM_Delete(struct Grid *);
extern void BMP_Delete(struct Obj020437AC *);
extern void CLACT_DeleteActor(struct Obj *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021FB494(char *p) { BMP_OAM_Delete(*(struct Grid * *)&((struct Obj10785 *)p)->f4);BMP_Delete(*(struct Obj020437AC * *)&((struct Obj10785 *)p)->f8);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10785 *)p)->f0);func_020307B0(p); }
