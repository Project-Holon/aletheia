/*
 * function: BOX2_SEQ_CreateBox2Actors
 * address: 0x021EBEAC
 * packet: pkt_ov170_021EBEAC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BOX2_UI_CreatePartyActors 0x021ED824 thumb ov170
 *   BOX2_SEQ_CreateBoxSlotActors 0x021EC2A0 thumb ov170
 *   BOX2_SEQ_CreateCursorObjects 0x021ED370 thumb ov170
 *   BOX2_SEQ_CreateHandSlotActors 0x021ECF78 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23996.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);extern void BOX2_UI_CreatePartyActors(char *);extern void BOX2_SEQ_CreateBoxSlotActors(char *);extern void BOX2_SEQ_CreateCursorObjects(unsigned char *);extern void BOX2_SEQ_CreateHandSlotActors(char *);
void BOX2_SEQ_CreateBox2Actors(unsigned char *p){((struct Obj23996 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f9E70=CLACT_CreateUnit(180,0,76);BOX2_UI_CreatePartyActors(*(char * *)&((struct Obj00000 *)p)->f2C);BOX2_SEQ_CreateBoxSlotActors(*(char * *)&((struct Obj00000 *)p)->f2C);BOX2_SEQ_CreateCursorObjects(p);BOX2_SEQ_CreateHandSlotActors(*(char * *)&((struct Obj00000 *)p)->f2C);}
