/*
 * function: GSYNC_MENU_StateWaitMenuSelect
 * address: 0x021D449C
 * packet: pkt_ov123_021D449C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_StatePrintConfirmMessage 0x021D4FB8 thumb ov123
 *   GSYNC_MENU_StateSetupButtons 0x021D4A04 thumb ov123
 *   GSYNC_MENU_SetPaletteFade 0x021D4D40 thumb ov123
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 */
#include "../include/Obj00273.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void BG_SYS_ClearSlot(u32 i);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void GSYNC_MENU_ChangeState(char *, void *, int);
extern void GSYNC_MENU_StatePrintConfirmMessage(char *p);
extern void GSYNC_MENU_StateSetupButtons(char *p);
extern void GSYNC_MENU_SetPaletteFade(char *, int);
void GSYNC_MENU_StateWaitMenuSelect(char *p)
{
    if (APP_TASKMENU_IsFinish(((struct Obj00273 *)p)->f238)) {
        if (!APP_TASKMENU_GetCursorPos(((struct Obj00273 *)p)->f238)) {
            GSYNC_MENU_ChangeState(p, GSYNC_MENU_StatePrintConfirmMessage, 0x1b6);
        } else {
            BG_SYS_ClearSlot(5);
            ((struct Obj00273 *)p)->f8 = 0;
            GSYNC_MENU_ChangeState(p, GSYNC_MENU_StateSetupButtons, 0x1bb);
        }
        APP_TASKMENU_CloseMenu(((struct Obj00273 *)p)->f238);
        *(int *)&((struct Obj00273 *)p)->f238 = 0;
        GSYNC_MENU_SetPaletteFade(p, 0);
    }
}
