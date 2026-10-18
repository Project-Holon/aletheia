/*
 * function: PLIST_MENU_Open
 * address:  0x021BBAF8
 * packet:   pkt_ov091_021BBAF8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLIST_MENU_BuildCommandList  0x021BBC04  thumb  ov091
 *   UI_SetInputMode  0x020355D8  arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 */
#include "../include/Obj09933.h"
#include "../include/Obj13254.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Req {
    u32 heap;
    u8 v;
    u8 *p;
    u32 one;
    u8 c[4];
} Req;

extern void PLIST_MENU_BuildCommandList(u8 *a, u8 *b, int *items);
extern void UI_SetInputMode(u32 a);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);

void PLIST_MENU_Open(u8 *a, u8 *b, int *items)
{
    Req r;

    PLIST_MENU_BuildCommandList(a, b, items);
    r.heap = ((struct Obj09933 *)a)->f0;
    r.v = b[0];
    r.p = b + 0x14;
    r.one = 1;
    r.c[0] = 0x20;
    r.c[1] = 0x18;
    r.c[2] = 0xd;
    r.c[3] = 3;
    UI_SetInputMode(((struct Obj09933 *)a)->f8);
    ((struct Obj13254 *)b)->f74 = (int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&r), (void *)(((struct Obj09933 *)a)->f254));
}
