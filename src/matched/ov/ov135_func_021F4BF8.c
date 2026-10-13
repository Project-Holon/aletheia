/*
 * function: func_021F4BF8
 * address: 0x021F4BF8
 * packet: pkt_ov135_021F4BF8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_021F5008 0x021F5008 thumb ov135
 *   str_02203B08 0x02203B08 data
 *   data_02202BC8 0x02202BC8 data a4
 */
#include "../include/Obj02489.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *text; u32 b,c; } Item;
typedef struct { Item item[2]; } Items;
typedef struct { u32 heap; u8 count,pad[3]; Item *items; u32 mode; u8 a,b,c,d; } Menu;
extern const char str_02203B08[];
extern const Items data_02202BC8;
struct MsgBank;
struct R;
struct U16Vec;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuFill8(void *,u32,u32);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021F5008(u32 x);
void func_021F4BF8(u8 *p,int b,int unused,int a,int c,u8 flag)
{
    Items items;
    Menu menu;
    int on;
    if (*(u32 *)&((struct Obj02489 *)p)->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)&((struct Obj02489 *)p)->fE08) func_02034714(str_02203B08,0,str_02203B08);
    ((struct Obj02489 *)p)->fE04=APP_TASKMENU_RES_Create((u8)c,(u8)a,((struct Obj02489 *)p)->fFA0,((struct Obj02489 *)p)->fFAC,0x48);
    items=data_02202BC8;
    on=0;
    MI_CpuFill8(&menu,0,20);
    items.item[0].text=func_02045EC0(((struct Obj02489 *)p)->fB6C,63);
    items.item[1].text=func_02045EC0(((struct Obj02489 *)p)->fB6C,64);
    menu.heap=0x48;
    menu.count=2;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=8;
    menu.d=3;
    ((struct Obj02489 *)p)->fE08=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),((struct Obj02489 *)p)->fE04);
    STRBUF_Delete(items.item[0].text);
    STRBUF_Delete(items.item[1].text);
    if (flag) {
        if(c<=3) on=1;
        func_021F5008(on);
    }
}
