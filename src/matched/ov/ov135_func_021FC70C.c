/*
 * function: WORLDTRADE_DETAIL_StateMenuInput
 * address: 0x021FC70C
 * packet: pkt_ov135_021FC70C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuList 0x021F4E30 thumb ov135
 *   WORLDTRADE_CloseTaskMenuList 0x021F4E64 thumb ov135
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WORLDTRADE_NoOp 0x0200ADB4 thumb
 *   WORLDTRADE_BOX_IsSpeciesFlagged 0x021F6DE8 thumb ov135
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   WORLDTRADE_DETAIL_PrintMessage 0x021FC810 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_DETAIL_DrawRequestWindow 0x021FCBF0 thumb ov135
 */
#include "../include/Obj00045.h"
#include "../include/Obj23409.h"
extern unsigned int WORLDTRADE_UpdateTaskMenuList(unsigned char *p);
extern void WORLDTRADE_CloseTaskMenuList(unsigned char *p);
extern unsigned int BMP_MENUWORK_Delete(void *p);
extern void *WORLDTRADE_NoOp(void *);
extern int WORLDTRADE_BOX_IsSpeciesFlagged(unsigned int handle);
typedef unsigned int   u32;
extern u32 POKEPARTY_GetCount(void *p);
typedef unsigned char  u8;
extern void WORLDTRADE_DETAIL_PrintMessage(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_DETAIL_DrawRequestWindow(char *p);
int WORLDTRADE_DETAIL_StateMenuInput(char *p)
{
    int r;
    void *q;
    r = WORLDTRADE_UpdateTaskMenuList((unsigned char *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenuList((unsigned char *)p);
        BMP_MENUWORK_Delete(((struct Obj00045 *)p)->fDE8);
        q = WORLDTRADE_NoOp(**(void ** *)&((struct Obj00045 *)p)->f0);
        if (WORLDTRADE_BOX_IsSpeciesFlagged((unsigned int)q) && POKEPARTY_GetCount(((struct Obj23409 *)(*(char * *)&((struct Obj00045 *)p)->f0))->f8) == 6) {
            WORLDTRADE_DETAIL_PrintMessage((u8 *)p, 0x2a, 1, 0, 0xf0f, q);
            WORLDTRADE_SetNextState((u8 *)p, 3, 1);
            return 2;
        }
        WORLDTRADE_DETAIL_PrintMessage((u8 *)p, 6, 1, 0, 0xf0f, q);
        WORLDTRADE_SetNextState((u8 *)p, 3, 5);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    } else if (r == 2 || r == -2) {
        WORLDTRADE_CloseTaskMenuList((unsigned char *)p);
        BMP_MENUWORK_Delete(((struct Obj00045 *)p)->fDE8);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        WORLDTRADE_SetStateAndReturn((u8 *)p, 1, 0);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    }
    return 2;
}
