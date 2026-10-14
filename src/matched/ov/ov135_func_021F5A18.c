/*
 * function: WORLDTRADE_BOX_StateWaitWipeIn
 * address: 0x021F5A18
 * packet: pkt_ov135_021F5A18
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * precondition: entry mode at offset 0x20 must be 5 or 6; original
 *   leaves r4 unchanged for other modes at 021F5A32..021F5A38.
 * symbols:
 *   WORLDTRADE_BOX_PrintMessage 0x021F663C thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 */
#include "../include/Obj00018.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void WORLDTRADE_BOX_PrintMessage(u8 *, u32, u32, u32, u32, u32);
extern void WORLDTRADE_SetNextState(u8 *, u32, u32);
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
int WORLDTRADE_BOX_StateWaitWipeIn(u8 *p)
{
    int index;
    if (WIPE_SYS_EndCheck()) {
        if (((struct Obj00018 *)p)->f20 == 5) {
            index = 0x15;
        } else if (((struct Obj00018 *)p)->f20 == 6) {
            index = 0x11;
        }
        WORLDTRADE_BOX_PrintMessage(p, index, 1, 0, 0xf0f, 0);
        WORLDTRADE_SetNextState(p, 3, 1);
        if (func_020355C4() == 1) {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        }
    }
    return 2;
}
