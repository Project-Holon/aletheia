/*
 * function: MAILSYS_OpenConfirmMenu
 * address: 0x021C48FC
 * packet: pkt_ov136_021C48FC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_WIN_ClearScreen  0x0202843C  thumb  arm9
 *   PALANM_BlendChannel  0x02021FD8  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 */
#include "../include/Obj00275.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 x,y,w,h; } Template;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
struct Chan02021FD8;
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void APP_TASKMENU_WIN_ClearScreen(u8 *p);
void MAILSYS_OpenConfirmMenu(u8 *p)
{
    Template t;
    ((struct Obj00275 *)p)->f110 = (u32)func_02045EC0(((struct Obj00275 *)p)->f20, 4);
    ((struct Obj00275 *)p)->f114 = 0x39E3;
    ((struct Obj00275 *)p)->f118 = 0;
    ((struct Obj00275 *)p)->f11C = (u32)func_02045EC0(((struct Obj00275 *)p)->f20, 5);
    ((struct Obj00275 *)p)->f120 = 0x39E3;
    ((struct Obj00275 *)p)->f124 = 0;
    t.heap = ((struct Obj00275 *)p)->f0;
    t.count = 2;
    t.items = p + 0x110;
    t.zero = 0;
    t.x = 23;
    t.y = 6;
    t.w = 8;
    t.h = 3;
    ((struct Obj00275 *)p)->f10C = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t), ((struct Obj00275 *)p)->f108);
    PALANM_BlendChannel(((struct Obj00275 *)p)->f38, 0, 0, 48, 10, 0);
    APP_TASKMENU_WIN_ClearScreen(((struct Obj00275 *)p)->f128);
    APP_TASKMENU_WIN_ClearScreen(((struct Obj00275 *)p)->f12C);
}
