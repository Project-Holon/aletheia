/*
 * function: func_021F4D50
 * address: 0x021F4D50
 * packet: pkt_ov135_021F4D50
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027F60 0x02027F60 thumb
 *   func_02027778 0x02027778 thumb
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021F5008 0x021F5008 thumb ov135
 *   str_02203B08 0x02203B08 data
 *   data_02202C2C 0x02202C2C data a4
 */
#include "../include/Obj00448.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a,b,c; } Item;
typedef struct { Item item[3]; } Items;
typedef struct { u32 heap; u8 count,pad[3]; Item *items; u32 mode; u8 a,b,c,d; } Menu;
extern const char str_02203B08[];
extern const Items data_02202C2C;
struct R;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *, u32, u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_021F5008(u32 x);
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
