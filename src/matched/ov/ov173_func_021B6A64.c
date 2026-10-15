/*
 * function: POKE_SUMMARY_MAIN_OpenMenu
 * address: 0x021B6A64
 * packet: pkt_ov173_021B6A64
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   POKE_SUMMARY_ACTOR_SetSubBrightness 0x021B81B0 thumb ov173
 */
#include "../include/Obj14313.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 a,b,c,d; } Descriptor;
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void POKE_SUMMARY_ACTOR_SetSubBrightness(int);
int POKE_SUMMARY_MAIN_OpenMenu(u8 *p)
{
    Descriptor x;
    x.heap = 79;
    x.count = 2;
    x.items = p + 0x1fc;
    x.zero = 0;
    x.a = 21;
    x.b = 8;
    x.c = 10;
    x.d = 3;
    ((struct Obj14313 *)p)->f1E0 = (unsigned int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&x), (void *)(((struct Obj14313 *)p)->f1DC));
    POKE_SUMMARY_ACTOR_SetSubBrightness(1);
    return 4;
}
