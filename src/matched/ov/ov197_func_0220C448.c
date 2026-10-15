/*
 * function: B_BAG_MAIN_DeleteItemGraphics
 * address: 0x0220C448
 * packet: pkt_ov197_0220C448
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_BAG_MAIN_DeleteFingerCursor 0x0220C6E8 thumb ov197
 *   B_BAG_MAIN_DeleteToolActors 0x0220C6C0 thumb ov197
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj25035.h"
struct Obj;
struct Bank;
extern void B_BAG_MAIN_DeleteFingerCursor(char *);
extern void B_BAG_MAIN_DeleteToolActors(char *);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void B_BAG_MAIN_DeleteItemGraphics(char *p)
{
    unsigned i;
    B_BAG_MAIN_DeleteFingerCursor(p);
    for (i = 0; i < 63; i++) CLACT_DeleteActor(*(struct Obj **)(p + i * 4 + 0x424));
    B_BAG_MAIN_DeleteToolActors(p);
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x544) != -1) CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x544));
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x568) != -1) CLACT_ReleasePalette(*(int *)(p + i * 4 + 0x568));
    for (i = 0; i < 3; i++) if (*(int *)(p + i * 4 + 0x58c) != -1) CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0x58c));
    CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25035 *)p)->f420);
}
