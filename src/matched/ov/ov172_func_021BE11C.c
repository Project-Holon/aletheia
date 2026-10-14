/*
 * function: COMM_TVT_SYS_OpenConfirmMenu
 * address: 0x021BE11C
 * packet: pkt_ov172_021BE11C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj08262.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 a,b,c,d; } Descriptor;
typedef struct { u32 handle; u16 value; u16 pad; u32 zero; } Item;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void STRBUF_Delete(struct U16Vec *vec);
u32 COMM_TVT_SYS_OpenConfirmMenu(u8 *p)
{
    Descriptor x={0};
    Item items[2]={0};
    u32 result;
    items[0].handle=(u32)func_02045EC0((struct MsgBank *)(((struct Obj08262 *)p)->f1CC),34);
    items[1].handle=(u32)func_02045EC0((struct MsgBank *)(((struct Obj08262 *)p)->f1CC),35);
    items[0].value=14819;
    items[1].value=14819;
    items[0].zero=0;
    items[1].zero=0;
    x.heap=((struct Obj08262 *)p)->f0;
    x.count=2;
    x.items=items;
    x.a=24;
    x.b=6;
    x.c=8;
    x.d=3;
    x.zero=0;
    result=(u32)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&x),(void *)(((struct Obj08262 *)p)->f1D4));
    STRBUF_Delete((struct U16Vec *)items[0].handle);
    STRBUF_Delete((struct U16Vec *)items[1].handle);
    return result;
}
