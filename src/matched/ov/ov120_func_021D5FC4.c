/*
 * function: GTSNEGO_DISP_DeleteMsgSystem
 * address: 0x021D5FC4
 * packet: pkt_ov120_021D5FC4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: original narrows both BG_SYS_DeleteHalf payloads to halfwords.
 * interface: original narrows func_020403F4 layer argument to one byte.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   GTSNEGO_DISP_DeleteTouchbar 0x021D698C thumb ov120
 *   GTSNEGO_MSG_DeleteCursorActor 0x021D6ED8 thumb ov120
 *   GTSNEGO_MSG_DeleteTileHandle 0x021D6C64 thumb ov120
 *   func_020307B0 0x020307B0 arm
 *   GTSNEGO_MSG_DeleteActors 0x021D6B5C thumb ov120
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_0202EA20 0x0202EA20 thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 */
#include "../include/Obj00199.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 ov_id[];
struct Bank;
struct Node;
struct Obj;
struct Obj0202EA20;
extern void CLACT_DeleteActor(struct Obj *p);
extern void GTSNEGO_DISP_DeleteTouchbar(u8 *);
extern void GTSNEGO_MSG_DeleteCursorActor(u8 *);
extern void GTSNEGO_MSG_DeleteTileHandle(u8 *);
extern u32 func_020307B0(void *p);
extern void GTSNEGO_MSG_DeleteActors(u8 *);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_SetTileUnit(u32,u32,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 i);
extern void BG_SYS_Delete(void);
extern void func_02034A5C(int handle);
void GTSNEGO_DISP_DeleteMsgSystem(u8 *p)
{
    int i;
    CLACT_DeleteActor(((struct Obj00199 *)p)->f134);
    GTSNEGO_DISP_DeleteTouchbar(p);
    GTSNEGO_MSG_DeleteCursorActor(p);
    GTSNEGO_MSG_DeleteTileHandle(p);
    func_020307B0(((struct Obj00199 *)p)->f124);
    func_020307B0(((struct Obj00199 *)p)->f128);
    GTSNEGO_MSG_DeleteActors(p);
    CLACT_ReleasePalette((u32)(((struct Obj00199 *)p)->f18));
    CLACT_ReleasePalette((u32)(((struct Obj00199 *)p)->f1C));
    CLACT_ReleaseCharacter((u32)(((struct Obj00199 *)p)->f28));
    CLACT_ReleaseCharacter((u32)(((struct Obj00199 *)p)->f2C));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00199 *)p)->f74));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00199 *)p)->f78));
    CLACT_ReleasePalette((u32)(((struct Obj00199 *)p)->f24));
    CLACT_ReleaseCharacter((u32)(((struct Obj00199 *)p)->f70));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00199 *)p)->fBC));
    CLACT_ReleasePalette((u32)(((struct Obj00199 *)p)->f20));
    for(i=0;i<16;i++) {
        CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+0x30)));
        CLACT_ReleaseCellAnim((u32)(*(void **)(p+i*4+0x7c)));
    }
    func_02030EAC(((struct Obj00199 *)p)->f14);
    CLACT_DeleteUnit(((struct Obj00199 *)p)->f10);
    CLACT_ExitSystem();
    func_0202EA20(((struct Obj00199 *)p)->fF8);
    func_0202EA20(((struct Obj00199 *)p)->fFC);
    BG_SYS_DeleteHalf(7,(u16)(((struct Obj00199 *)p)->f8),(u16)(((struct Obj00199 *)p)->f8>>16));
    BG_SYS_DeleteHalf(4,(u16)(((struct Obj00199 *)p)->f0),(u16)(((struct Obj00199 *)p)->f0>>16));
    BG_SYS_DeleteHalf(0,(u16)(((struct Obj00199 *)p)->f4),(u16)(((struct Obj00199 *)p)->f4>>16));
    BG_SYS_SetTileUnit(1,1,0);
    BG_SYS_SetTileUnit(5,1,0);
    BG_SYS_SetTileUnit(6,1,0);
    func_02040588(5,0);
    for(i=0;i<=7;i++) func_020403F4((u8)i);
    BG_SYS_Delete();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}
