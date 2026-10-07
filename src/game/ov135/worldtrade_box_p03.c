/*
 * file:     worldtrade_box_p03.c
 * unit:     yes
 * function: func_021F4BCC, func_021F4BE0, func_021F4BF8, func_021F4CE4, func_021F4D14
 * address:  0x021F4BCC
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
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027778 0x02027778 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021F5008 0x021F5008 thumb ov135
 *   str_02203B08 0x02203B08 data
 *   data_02202BC8 0x02202BC8 data a4
 *   func_02027858 0x02027858 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021F5060 0x021F5060 thumb ov135
 */
#include "../../matched/include/Obj02489.h"
#include "../../matched/include/Obj00045.h"

struct MsgBank;
struct R;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
struct TaskMenuState;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef void (*Fn)(void);

typedef struct { void *text; u32 b,c; } Item;

typedef struct { Item item[2]; } Items;

typedef struct { u32 heap; u8 count,pad[3]; Item *items; u32 mode; u8 a,b,c,d; } Menu;

extern void func_020434DC(u32 a, u32 b);
extern void func_02043598(u32 a, u32 b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *,u32,u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_021F5008(u32 x);
extern void func_02027858(struct TaskMenu *m);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_021F5060(void);
void func_021F4BCC(u8 *p);
void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
void func_021F4BF8(u8 *p,int b,int unused,int a,int c,u8 flag);
void func_021F4CE4(char *p);
int func_021F4D14(char *p);
extern const char str_02203B08[];
extern const Items data_02202BC8;


/*
 * Release the 0x10 channel on both hardware blocks.
 */
void func_021F4BCC(u8 *p)
{
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


/*
 * Forward four register arguments plus a zero and the u8 stack argument.
 */
void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_021F4BF8((u8 *)a, b, c, d, 0, e);
}

void func_021F4BF8(u8 *p,int b,int unused,int a,int c,u8 flag)
{
    Items items;
    Menu menu;
    int on;
    if (*(u32 *)&((struct Obj02489 *)p)->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)&((struct Obj02489 *)p)->fE08) func_02034714(str_02203B08,0,str_02203B08);
    ((struct Obj02489 *)p)->fE04=func_02027F60((u8)c,(u8)a,((struct Obj02489 *)p)->fFA0,((struct Obj02489 *)p)->fFAC,0x48);
    items=data_02202BC8;
    on=0;
    func_02082BCC(&menu,0,20);
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
    ((struct Obj02489 *)p)->fE08=func_02027778((struct TaskMenuTmpl *)(&menu),((struct Obj02489 *)p)->fE04);
    func_02045808(items.item[0].text);
    func_02045808(items.item[1].text);
    if (flag) {
        if(c<=3) on=1;
        func_021F5008(on);
    }
}

void func_021F4CE4(char *p) { if(((struct Obj00045 *)p)->fE08) { func_02027858(((struct Obj00045 *)p)->fE08); ((struct Obj00045 *)p)->fE08=0; } if(((struct Obj00045 *)p)->fE04) { func_02027FD8(((struct Obj00045 *)p)->fE04); ((struct Obj00045 *)p)->fE04=0; } }

int func_021F4D14(char *p) { int result; result=0; if(((struct Obj00045 *)p)->fE08) { func_02027974(((struct Obj00045 *)p)->fE08); if(func_020279E8(((struct Obj00045 *)p)->fE08)) { result=func_02027A04(((struct Obj00045 *)p)->fE08); if(result==0) result=1; else if(result==1) result=2; func_021F5060(); } } return result; }
