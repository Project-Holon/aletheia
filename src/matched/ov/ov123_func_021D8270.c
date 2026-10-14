/*
 * function: GSYNC_STATE_StateConfirmMenuSelect
 * address: 0x021D8270
 * packet: pkt_ov123_021D8270
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_STATE_StateWaitMessageThenPrintThird 0x021D8244 thumb ov123
 *   GSYNC_STATE_StateShowProgressMessage 0x021D8154 thumb ov123
 *   GSYNC_STATE_StateSetErrorExit 0x021D706C thumb ov123
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj03796.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_MESSAGE_ClearStream(char *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void GSYNC_STATE_StateWaitMessageThenPrintThird(char *p);
extern void GSYNC_STATE_StateShowProgressMessage(char *p);
extern void GSYNC_STATE_StateSetErrorExit(char *p);
void GSYNC_STATE_StateConfirmMenuSelect(char *p)
{
    if (((struct Obj03796 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (((struct Obj03796 *)p)->f64)++;
    if (APP_TASKMENU_IsFinish(((struct Obj03796 *)p)->f1C)) {
        if (APP_TASKMENU_GetCursorPos(((struct Obj03796 *)p)->f1C) == 0) {
            if (func_020076D0(((struct Obj03796 *)p)->f24, (int *)(p + 0x48), (int *)(p + 0x4c)) == 0)
                GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitMessageThenPrintThird, 0x60f);
            else
                GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateShowProgressMessage, 0x612);
        } else {
            GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x616);
        }
        GSYNC_MESSAGE_ClearStream(*(char * *)&((struct Obj03796 *)p)->f18);
        APP_TASKMENU_CloseMenu(((struct Obj03796 *)p)->f1C);
        *(unsigned short *)0x04001050 = 0;
        ((struct Obj03796 *)p)->f1C = 0;
    }
}
