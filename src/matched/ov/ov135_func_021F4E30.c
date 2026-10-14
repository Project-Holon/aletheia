/*
 * function: WORLDTRADE_UpdateTaskMenuList
 * address:  0x021F4E30
 * packet:   pkt_021F4E30
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
  *
 * symbols:
 *   WORLDTRADE_ClearBlendRegs  0x021F5060  thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 */
#include "../include/Obj00045.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void APP_TASKMENU_UpdateMenu(void *m);
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void WORLDTRADE_ClearBlendRegs(void);

u32 WORLDTRADE_UpdateTaskMenuList(u8 *p)
{
    u32 r = (u32)-1;

    if (((struct Obj00045 *)p)->fE08 != 0) {
        APP_TASKMENU_UpdateMenu(((struct Obj00045 *)p)->fE08);
        if (APP_TASKMENU_IsFinish(((struct Obj00045 *)p)->fE08) != 0) {
            r = APP_TASKMENU_GetCursorPos(((struct Obj00045 *)p)->fE08) + 1;
            WORLDTRADE_ClearBlendRegs();
        }
    }
    return r;
}
