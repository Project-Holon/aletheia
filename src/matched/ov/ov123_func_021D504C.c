/*
 * function: GSYNC_MENU_StateConfirmSelect
 * address: 0x021D504C
 * packet: pkt_ov123_021D504C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   GSYNC_MENU_PrintMessageNoStream 0x021D4FAC thumb ov123
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_PrintMessage 0x021D4EF0 thumb ov123
 *   GSYNC_MENU_RestartTimeIcon 0x021D4384 thumb ov123
 *   GSYNC_MENU_SetPaletteFade 0x021D4D40 thumb ov123
 *   GSYNC_MENU_StateWaitTouchAfterMessage 0x021D4AFC thumb ov123
 *   GSYNC_MENU_StateSaveStart 0x021D5020 thumb ov123
 *   GSYNC_MENU_StateSetupButtons 0x021D4A04 thumb ov123
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 */
#include "../include/Obj00273.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Big;
struct MsgBank;
struct Sub020071E4Ctrl;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void BG_SYS_ClearSlot(u32 i);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void GSYNC_MENU_PrintMessageNoStream(char *);
extern void GSYNC_MENU_ChangeState(char *,void *,int);
extern void GSYNC_MENU_PrintMessage(char *,int,int);
extern void GSYNC_MENU_RestartTimeIcon(u8 *p);
extern void GSYNC_MENU_SetPaletteFade(char *,int);
extern void GSYNC_MENU_StateWaitTouchAfterMessage(char *);
extern void GSYNC_MENU_StateSaveStart(char *);
extern void GSYNC_MENU_StateSetupButtons(char *);
void GSYNC_MENU_StateConfirmSelect(char *p)
{
    if (APP_TASKMENU_IsFinish(((struct Obj00273 *)p)->f238)) {
        if (!APP_TASKMENU_GetCursorPos(((struct Obj00273 *)p)->f238)) {
            if (func_020071F0(GAME_DATA_GetSaveControl(((struct Obj00273 *)p)->f260))) {
                MSGDATA_ReadString(((struct Obj00273 *)p)->f24,46,((struct Obj00273 *)p)->f38);
                GSYNC_MENU_PrintMessageNoStream(p);
                GSYNC_MENU_ChangeState(p,GSYNC_MENU_StateWaitTouchAfterMessage,0x50d);
            } else {
                MSGDATA_ReadString(((struct Obj00273 *)p)->f24,6,((struct Obj00273 *)p)->f38);
                GSYNC_MENU_PrintMessage(p,4,0);
                GSYNC_MENU_RestartTimeIcon((u8 *)p);
                GSYNC_MENU_ChangeState(p,GSYNC_MENU_StateSaveStart,0x519);
            }
        } else {
            BG_SYS_ClearSlot(5);
            ((struct Obj00273 *)p)->f8=0;
            GSYNC_MENU_ChangeState(p,GSYNC_MENU_StateSetupButtons,0x51f);
            GSYNC_MENU_SetPaletteFade(p,0);
        }
        APP_TASKMENU_CloseMenu(((struct Obj00273 *)p)->f238);
        ((struct Obj00273 *)p)->f238=0;
    }
}
