/*
 * function: WORLDTRADE_SEARCH_UpdateCursorVisibility
 * address: 0x021FE1A4
 * packet: pkt_ov135_021FE1A4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_SEARCH_PrintMessage 0x021FF318 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj00018.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d);
extern int func_0207D55C(volatile u16 *reg);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
int WORLDTRADE_SEARCH_UpdateCursorVisibility(unsigned char *p)
{
    if (func_020355C4() == 1)
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
    else
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
    if (((struct Obj00018 *)p)->f20 == 15) {
        if (((struct Obj00018 *)p)->fD0 != 0)
            WORLDTRADE_SEARCH_PrintMessage(p, 38, 0, 0, 0xf0f);
        else
            WORLDTRADE_SEARCH_PrintMessage(p, 8, 1, 0, 0xf0f);
        if (func_0207D55C((u16 *)0x0400006c) == -16) {
            WIPE_SYS_Start(0, 1, 1, 0, 16, 1, 0x48);
            *(int *)&((struct Obj00018 *)p)->f28 = 33;
        } else {
            *(int *)&((struct Obj00018 *)p)->f28 = 1;
        }
    } else {
        WORLDTRADE_SEARCH_PrintMessage(p, 8, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
    }
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fD38, 1);
    return 2;
}
