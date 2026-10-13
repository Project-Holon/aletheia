/*
 * function: func_021F4E64
 * address:  0x021F4E64
 * packet:   pkt_021F4E64
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
 * symbols:
 *   func_021F5060  0x021F5060  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 */
#include "../include/Obj00045.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct TaskMenu;
struct TaskMenuState;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void func_021F5060(void);

void func_021F4E64(u8 *p)
{
    if (((struct Obj00045 *)p)->fE08 != 0) {
        APP_TASKMENU_CloseMenu(((struct Obj00045 *)p)->fE08);
        ((struct Obj00045 *)p)->fE08 = 0;
    }
    if (((struct Obj00045 *)p)->fE04 != 0) {
        APP_TASKMENU_RES_Delete(((struct Obj00045 *)p)->fE04);
        ((struct Obj00045 *)p)->fE04 = 0;
    }
    func_021F5060();
}
