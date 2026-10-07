/*
 * file:     worldtrade_box_p04.c
 * unit:     yes
 * function: func_021F4D50, func_021F4E30, func_021F4E64, func_021F4E98, func_021F4EA0
 * address:  0x021F4D50
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02027F60 0x02027F60 thumb
 *   func_02027778 0x02027778 thumb
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021F5008 0x021F5008 thumb ov135
 *   str_02203B08 0x02203B08 data
 *   data_02202C2C 0x02202C2C data a4
 *   func_021F5060  0x021F5060  thumb
 *   func_0204B404  0x0204B404  arm
 */
#include "../../matched/include/Obj00448.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj00018.h"

struct R;
struct TaskMenu;
struct TaskMenuTmpl;
struct TaskMenuState;
struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a,b,c; } Item;

typedef struct { Item item[3]; } Items;

typedef struct { u32 heap; u8 count,pad[3]; Item *items; u32 mode; u8 a,b,c,d; } Menu;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *, u32, u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_021F5008(u32 x);
extern void func_02027974(void *m);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021F5060(void);
extern void func_02027858(struct TaskMenu *m);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021F4D50(u8 *p, u16 a, int count, int b);
u32 func_021F4E30(u8 *p);
void func_021F4E64(u8 *p);
void func_021F4E98(u8 *p, u32 a, u32 b);
void func_021F4EA0(u32 a, u16 b, u16 c);
extern const char str_02203B08[];
extern const Items data_02202C2C;

void func_021F4D50(u8 *p, u16 a, int count, int b)
{
    Items items;
    Menu menu;
    int i;
    if (*(u32 *)&((struct Obj00448 *)p)->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)&((struct Obj00448 *)p)->fE08) func_02034714(str_02203B08,0,str_02203B08);
    ((struct Obj00448 *)p)->fE04=func_02027F60(a,10,((struct Obj00448 *)p)->fFA0,((struct Obj00448 *)p)->fFAC,0x48);
    items=data_02202C2C;
    func_02082BCC(&menu,0,20);
    if ((u32)count>3) func_02034714(str_02203B08,0,str_02203B08);
    for(i=0;i<count;i++) items.item[i].a=*(u32 *)(*(u32 *)&((struct Obj00448 *)p)->fDE8+i*8);
    menu.heap=0x48;
    menu.count=count;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=13;
    menu.d=3;
    ((struct Obj00448 *)p)->fE08=func_02027778((struct TaskMenuTmpl *)(&menu),((struct Obj00448 *)p)->fE04);
    func_021F5008(1);
}


u32 func_021F4E30(u8 *p)
{
    u32 r = (u32)-1;

    if (((struct Obj00045 *)p)->fE08 != 0) {
        func_02027974(((struct Obj00045 *)p)->fE08);
        if (func_020279E8(((struct Obj00045 *)p)->fE08) != 0) {
            r = func_02027A04(((struct Obj00045 *)p)->fE08) + 1;
            func_021F5060();
        }
    }
    return r;
}


void func_021F4E64(u8 *p)
{
    if (((struct Obj00045 *)p)->fE08 != 0) {
        func_02027858(((struct Obj00045 *)p)->fE08);
        ((struct Obj00045 *)p)->fE08 = 0;
    }
    if (((struct Obj00045 *)p)->fE04 != 0) {
        func_02027FD8(((struct Obj00045 *)p)->fE04);
        ((struct Obj00045 *)p)->fE04 = 0;
    }
    func_021F5060();
}

void func_021F4E98(u8 *p, u32 a, u32 b)
{
    ((struct Obj00018 *)p)->f28 = a;
    ((struct Obj00018 *)p)->f2C = b;
}


/*
 * Send a one-entry u16 table {b, c} to func_0204B404.
 */
void func_021F4EA0(u32 a, u16 b, u16 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    func_0204B404((struct Obj *)a, (const struct Vec2 *)t, 1);
}
