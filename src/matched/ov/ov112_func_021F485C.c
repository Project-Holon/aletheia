/*
 * function: MUSICAL_SHOT_INFO_OpenYesNoMenu
 * address: 0x021F485C
 * packet: pkt_ov112_021F485C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 */
#include "../include/Obj06406.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Item { void *data; u16 value; u16 pad; int zero; } Item;
typedef struct Menu { u32 heap; u8 count; u8 pad[3]; Item *items; int zero; u8 a,b,c,d; } Menu;
struct MsgBank;
struct TaskMenu;
struct TaskMenuTmpl;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
void MUSICAL_SHOT_INFO_OpenYesNoMenu(u8 *p)
{
    Item items[2];
    Menu menu;
    items[0].data=func_02045EC0((struct MsgBank *)(((struct Obj06406 *)p)->f28),4);
    items[1].data=func_02045EC0((struct MsgBank *)(((struct Obj06406 *)p)->f28),5);
    items[0].value=0x39e0;
    items[1].value=0x39e0;
    items[0].zero=0;
    items[1].zero=0;
    menu.heap=((struct Obj06406 *)p)->f0;
    menu.count=2;
    menu.items=items;
    menu.zero=0;
    menu.a=24;
    menu.b=6;
    menu.c=8;
    menu.d=3;
    ((struct Obj06406 *)p)->f3C=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),(void *)(((struct Obj06406 *)p)->f40));
    STRBUF_Delete(items[0].data);
    STRBUF_Delete(items[1].data);
}
