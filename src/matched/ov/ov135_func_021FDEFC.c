/*
 * function: WORLDTRADE_SEARCH_DeleteActors
 * address: 0x021FDEFC
 * packet: pkt_ov135_021FDEFC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj08189.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
void WORLDTRADE_SEARCH_DeleteActors(char *p) {CLACT_DeleteActor(*(struct Obj * *)&((struct Obj08189 *)p)->fBF4);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj08189 *)p)->fBF8);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj08189 *)p)->fD2C);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj08189 *)p)->fD30);}
