/*
 * unit: yes
 * function: func_021C5AEC,func_021C5B30
 * address: 0x021C5AEC
 * packet: pkt_ov136_021C5AEC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 */
#include "../include/Obj10602.h"
#include "../include/Obj23522.h"
#include "../include/Obj23523.h"
#include "../include/Obj23524.h"
#include "../include/Obj23525.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 x,y,w,h; } Template;
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
void func_021C5AEC(u8 *p)
{
    Template t;
    t.heap = 102;
    t.count = 4;
    t.items = *(u8 * *)&((struct Obj10602 *)p)->f8 + 0x314;
    t.zero = 0;
    t.x = 20;
    t.y = 12;
    t.w = 12;
    t.h = 3;
    ((struct Obj23523 *)(*(u8 * *)&((struct Obj10602 *)p)->f8))->f310 = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t), ((struct Obj23522 *)(*(u8 * *)&((struct Obj10602 *)p)->f8))->f30C);
}
void func_021C5B30(u8 *p)
{
    APP_TASKMENU_CloseMenu(((struct Obj23525 *)(*(u8 * *)&((struct Obj23524 *)p)->f8))->f310);
}
