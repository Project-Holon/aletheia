/*
 * function: WIFILOGIN_DISP_DeleteActors
 * address: 0x021D584C
 * packet: pkt_ov115_021D584C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 */
#include "../include/Obj02170.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Bank;
struct Node;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
void WIFILOGIN_DISP_DeleteActors(u8 *p) {
    int i;
    for (i = 0; i < 5; ++i) {
        if (*(u32 *)(p + i * 4 + 0x99c)) {
            CLACT_DeleteActor((struct Obj *)(*(u32 *)(p + i * 4 + 0x99c)));
            *(u32 *)(p + i * 4 + 0x99c) = 0;
        }
    }
    CLACT_ReleasePalette(((struct Obj02170 *)p)->f98C);
    CLACT_ReleaseCharacter(((struct Obj02170 *)p)->f990);
    CLACT_ReleaseCellAnim(((struct Obj02170 *)p)->f994);
    if (((struct Obj02170 *)p)->f988) func_02030EAC((struct Node *)(((struct Obj02170 *)p)->f988));
    func_02030EAC((struct Node *)(((struct Obj02170 *)p)->f984));
    CLACT_DeleteUnit((struct Bank *)(((struct Obj02170 *)p)->f980));
    CLACT_ExitSystem();
}
