/*
 * function: GTSNEGO_DISP_ShowPartySelect
 * address: 0x021D588C
 * packet: pkt_ov120_021D588C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_SetupRowBg 0x021D70F0 thumb ov120
 *   func_0200F800 0x0200F800 thumb
 *   func_020355C4 0x020355C4 arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_MSG_CreateYesNoUi 0x021D7D6C thumb ov120
 *   GTSNEGO_DISP_OnMenuCallback 0x021D4C98 thumb ov120
 *   GTSNEGO_DISP_StartTrade 0x021D42D8 thumb ov120
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetNonEggCount 0x0201AA1C thumb
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   func_02040588 0x02040588 arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_HandlePartyInput 0x021D5AD4 thumb ov120
 */
#include "../include/Obj01729.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GTSNEGO_MSG_SetupRowBg(void *);
extern void func_0200F800(void);
extern u8 func_020355C4(void);
typedef unsigned short u16;
struct BigObj;
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void GTSNEGO_MSG_CreateYesNoUi(char *p, int a, int b);
extern void GTSNEGO_DISP_OnMenuCallback(void *p, int n, u8 *s);
extern int GTSNEGO_DISP_StartTrade(int n, u8 *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetNonEggCount(void *);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_HandlePartyInput(u8 *p);
void GTSNEGO_DISP_ShowPartySelect(u8 *p)
{
    GTSNEGO_MSG_SetupRowBg(((struct Obj01729 *)p)->f3C);
    if (((struct Obj01729 *)p)->f1B0) {
        if ((((struct Obj01729 *)p)->f1B4)++ < 3)
            return;
        func_0200F800();
        ((struct Obj01729 *)p)->f1B0 = 0;
    }
    if (func_020355C4() == 0)
        GTSNEGO_DISP_SetCursorState(((struct Obj01729 *)p)->f3C, 0, ((struct Obj01729 *)p)->f15C);
    else
        GTSNEGO_DISP_SetCursorState(((struct Obj01729 *)p)->f3C, 0, 9);
    GTSNEGO_MSG_CreateYesNoUi(((struct Obj01729 *)p)->f40, (int)GTSNEGO_DISP_OnMenuCallback, (int)p);
    *(void (**)(void))(p + 4) = (void (*)(void))GTSNEGO_DISP_StartTrade;
    if ((int)POKEPARTY_GetNonEggCount(GAME_DATA_GetMyParty(((struct Obj01729 *)p)->f2C)) < 2)
        ((struct Obj01729 *)p)->f184 = 1;
    if (((struct Obj01729 *)p)->f184 == 0)
        GTSNEGO_MSG_PrintWindow(((struct Obj01729 *)p)->f40, 0x20);
    else
        GTSNEGO_MSG_PrintWindow(((struct Obj01729 *)p)->f40, 0x2b);
    func_02040588(4, 1);
    func_02040588(6, 1);
    GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_HandlePartyInput, 0x86c);
}
