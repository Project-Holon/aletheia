/*
 * function: PDWACC_STATE_StateConfirmMenuSelect
 * address: 0x021DA290
 * packet: pkt_ov123_021DA290
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 *   PDWACC_MESSAGE_ClearStream 0x021D9634 thumb ov123
 *   PDWACC_STATE_StateTimeIconMessage 0x021DA268 thumb ov123
 *   PDWACC_STATE_StateFadeOutBgm 0x021DA054 thumb ov123
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 */
#include "../include/Obj06471.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void PDWACC_STATE_ChangeState(char *p, int n, int unused);
extern void PDWACC_MESSAGE_ClearStream(char *p);
extern void PDWACC_STATE_StateTimeIconMessage(char *p);
extern void PDWACC_STATE_StateFadeOutBgm(char *p);
void PDWACC_STATE_StateConfirmMenuSelect(char *p)
{
    if (APP_TASKMENU_IsFinish(((struct Obj06471 *)p)->f14)) {
        if (!APP_TASKMENU_GetCursorPos(((struct Obj06471 *)p)->f14))
            PDWACC_STATE_ChangeState(p, (int)PDWACC_STATE_StateTimeIconMessage, 0x18d);
        else
            PDWACC_STATE_ChangeState(p, (int)PDWACC_STATE_StateFadeOutBgm, 0x190);
        PDWACC_MESSAGE_ClearStream(((struct Obj06471 *)p)->f10);
        APP_TASKMENU_CloseMenu(((struct Obj06471 *)p)->f14);
        *(int *)&((struct Obj06471 *)p)->f14 = 0;
    }
}
