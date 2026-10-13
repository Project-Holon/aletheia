/*
 * function: OPTION_MENU_UpdateMessageBox
 * address:  0x021BAE28
 * packet:   pkt_ov068_021BAE28
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OPTION_MENU_IsTextDone  0x021BA31C  thumb  ov068
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 */
#include "../include/Obj02417.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct TaskMenu;
extern int OPTION_MENU_IsTextDone(u8 *p);
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void  APP_TASKMENU_UpdateMenu(void *p);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8    APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

void OPTION_MENU_UpdateMessageBox(u8 *p)
{
    switch (((struct Obj02417 *)p)->f56) {
    case 0:
        if (OPTION_MENU_IsTextDone(p) != 0) {
            ((struct Obj02417 *)p)->f56 = 1;
        }
        break;
    case 1:
        ((struct Obj02417 *)p)->f38 = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(p + 0x58), ((struct Obj02417 *)p)->f6C);
        ((struct Obj02417 *)p)->f56 = 2;
        break;
    case 2:
        APP_TASKMENU_UpdateMenu(((struct Obj02417 *)p)->f38);
        if (APP_TASKMENU_IsFinish(((struct Obj02417 *)p)->f38) != 0) {
            ((struct Obj02417 *)p)->f54 = APP_TASKMENU_GetCursorPos(*(u8 * *)&((struct Obj02417 *)p)->f38) + 1;
            ((struct Obj02417 *)p)->f56 = 3;
            APP_TASKMENU_CloseMenu(((struct Obj02417 *)p)->f38);
        }
        break;
    }
}
