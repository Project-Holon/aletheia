/*
 * function: OEKAKI_PollYesNoMenu
 * address: 0x02186660
 * packet: pkt_ov023_02186660
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x02186692.
 * lever: naming the accessor result before clearing r preserves call/store scheduling.
 * symbols:
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   OEKAKI_CloseYesNoMenu 0x02186694 thumb ov023
 */
#include "../include/Obj03625.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
struct TaskMenu;
extern void APP_TASKMENU_UpdateMenu(struct Obj *);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void OEKAKI_CloseYesNoMenu(char *);
int OEKAKI_PollYesNoMenu(char *p)
{
    int r = 2;
    APP_TASKMENU_UpdateMenu(*(struct Obj * *)&((struct Obj03625 *)p)->f178);
    if (APP_TASKMENU_IsFinish(*(struct TaskMenu * *)&((struct Obj03625 *)p)->f178) != 0) {
        u8 v = APP_TASKMENU_GetCursorPos(*(const u8 * *)&((struct Obj03625 *)p)->f178);
        r = 0;
        if (v != 0) r = 1;
        OEKAKI_CloseYesNoMenu(p);
    }
    return r;
}
