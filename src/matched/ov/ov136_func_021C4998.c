/*
 * function: func_021C4998
 * address:  0x021C4998
 * packet:   pkt_ov136_021C4998
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4998 0x021C4998 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj06524.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct TaskMenu;
struct U16Vec;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void STRBUF_Delete(struct U16Vec *vec);
int func_021C4998(u8 *p)
{
    int r = -1;
    if (APP_TASKMENU_IsFinish(((struct Obj06524 *)p)->f10C)) {
        r = APP_TASKMENU_GetCursorPos(((struct Obj06524 *)p)->f10C);
        APP_TASKMENU_CloseMenu(((struct Obj06524 *)p)->f10C);
        STRBUF_Delete(((struct Obj06524 *)p)->f110);
        STRBUF_Delete(((struct Obj06524 *)p)->f11C);
    }
    return r;
}
