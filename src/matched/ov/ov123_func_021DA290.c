/*
 * function: func_021DA290
 * address: 0x021DA290
 * packet: pkt_ov123_021DA290
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021D9634 0x021D9634 thumb ov123
 *   func_021DA268 0x021DA268 thumb ov123
 *   func_021DA054 0x021DA054 thumb ov123
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
extern void func_021DA034(char *p, int n, int unused);
extern void func_021D9634(char *p);
extern void func_021DA268(char *p);
extern void func_021DA054(char *p);
void func_021DA290(char *p)
{
    if (APP_TASKMENU_IsFinish(((struct Obj06471 *)p)->f14)) {
        if (!APP_TASKMENU_GetCursorPos(((struct Obj06471 *)p)->f14))
            func_021DA034(p, (int)func_021DA268, 0x18d);
        else
            func_021DA034(p, (int)func_021DA054, 0x190);
        func_021D9634(((struct Obj06471 *)p)->f10);
        APP_TASKMENU_CloseMenu(((struct Obj06471 *)p)->f14);
        *(int *)&((struct Obj06471 *)p)->f14 = 0;
    }
}
