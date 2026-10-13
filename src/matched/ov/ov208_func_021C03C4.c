/*
 * function: func_021C03C4
 * address: 0x021C03C4
 * packet: pkt_ov208_021C03C4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021C044E..021C0450 is two zero alignment bytes, not a follower.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_DeleteRenderer 0x0204B084 arm
 */
#include "../include/Obj02546.h"
typedef unsigned char u8;
struct Obj;
struct Bank;
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_DeleteRenderer(void *);
void func_021C03C4(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 7; i++) CLACT_DeleteActor(*(struct Obj **)(p + i * 4 + 0xbc));
    CLACT_ReleaseCellAnim(((struct Obj02546 *)p)->fB8);
    CLACT_ReleaseCharacter(((struct Obj02546 *)p)->fB0);
    CLACT_ReleasePalette(((struct Obj02546 *)p)->fB4);
    CLACT_ReleaseCellAnim(((struct Obj02546 *)p)->fAC);
    CLACT_ReleaseCharacter(((struct Obj02546 *)p)->fA4);
    CLACT_ReleasePalette(((struct Obj02546 *)p)->fA8);
    CLACT_ReleaseCellAnim(((struct Obj02546 *)p)->fA0);
    CLACT_ReleaseCharacter(((struct Obj02546 *)p)->f98);
    CLACT_ReleasePalette(((struct Obj02546 *)p)->f9C);
    CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj02546 *)p)->f1D0);
    CLACT_DeleteRenderer(((struct Obj02546 *)p)->f1D4);
}
