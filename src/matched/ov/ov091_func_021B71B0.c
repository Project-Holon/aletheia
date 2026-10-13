/*
 * function: POKELIST_DeleteClactUnit
 * address: 0x021B71B0
 * packet: pkt_ov091_021B71B0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj01888.h"
struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void POKELIST_DeleteClactUnit(unsigned p) { CLACT_DeleteActor(((struct Obj01888 *)p)->f1E0); CLACT_DeleteActor(((struct Obj01888 *)p)->f1E4); CLACT_DeleteActor(((struct Obj01888 *)p)->f1D8); CLACT_DeleteActor(((struct Obj01888 *)p)->f1DC); CLACT_DeleteUnit(((struct Obj01888 *)p)->f1D4); }
