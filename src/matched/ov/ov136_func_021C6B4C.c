/*
 * function: func_021C6B4C
 * address: 0x021C6B4C
 * packet: pkt_ov136_021C6B4C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C7D68 0x021C7D68 data a4
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 */
#include "../include/Obj06530.h"
#include "../include/Obj23612.h"
#include "../include/Obj23613.h"
#include "../include/Obj23614.h"
#include "../include/Obj23615.h"
#include "../include/Obj23616.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Row { int (*a)(u8 *); int (*b)(u8 *); };
extern const struct Row d_021C7D68[];
extern void APP_TASKMENU_UpdateMenu(void *);
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
int func_021C6B4C(u8 *p)
{
    APP_TASKMENU_UpdateMenu(((struct Obj23612 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310);
    if (APP_TASKMENU_IsFinish(((struct Obj23613 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310) == 0) return 4;
    switch (APP_TASKMENU_GetCursorPos(*(u8 * *)&((struct Obj23614 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310)) {
    case 0:
        APP_TASKMENU_CloseMenu(((struct Obj23615 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310);
        return d_021C7D68[*(int *)(*(u8 **)(p + 8) + 0x1E0)].a(p);
    case 1:
        APP_TASKMENU_CloseMenu(((struct Obj23616 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310);
        return d_021C7D68[*(int *)(*(u8 **)(p + 8) + 0x1E0)].b(p);
    }
    return 4;
}
