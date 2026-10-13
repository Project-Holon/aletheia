/*
 * function: OEKAKI_OpenYesNoMenu
 * address:  0x021865B4
 * packet:   pkt_ov023_021865B4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   gOekakiMenuItemInit     0x02186ABC  data
 */
#include "../include/Obj02742.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a;
    u8  b;
    u32 c;
    u32 d;
    u8  e[4];
} Arg;

typedef struct {
    u32 a;
    u32 b;
} Ent;

extern Ent gOekakiMenuItemInit[];
struct MsgBank;
struct R;
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);

int OEKAKI_OpenYesNoMenu(char *p)
{
    int i;
    int r;
    char *e;
    Ent *t;
    Arg s;

    ((struct Obj02742 *)p)->f174 = (u32)APP_TASKMENU_RES_Create(0, 2, ((struct Obj02742 *)p)->fC, ((struct Obj02742 *)p)->f168, 0x28);
    for (i = 0; i < 2; i++) {
        t = &gOekakiMenuItemInit[i];
        *(u32 *)(p + i * 12 + 0x17C) = (u32)func_02045EC0((struct MsgBank *)(((struct Obj02742 *)p)->f14), gOekakiMenuItemInit[i].a);
        *(u16 *)(p + i * 12 + 0x180) = 0x39E3;
        *(u32 *)(p + i * 12 + 0x184) = t->b;
    }
    s.a = 0x28;
    s.b = 2;
    s.c = (u32)(p + 0x17C);
    s.d = 0;
    s.e[0] = 0x15;
    s.e[1] = 7;
    s.e[2] = 10;
    s.e[3] = 3;
    r = (int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj02742 *)p)->f174));
    ((struct Obj02742 *)p)->f9E70 = 1;
    return r;
}
