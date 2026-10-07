/*
 * file:     itemmenu_p07.c
 * unit:     yes
 * function: func_021B7F54, func_021B8080, func_021B809C, func_021B80BC
 * address:  0x021B7F54
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   sub_02007CC8   0x02007CC8  thumb
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_02020F14  0x02020F14  thumb
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   MATH_QSort     0x02081BE4  arm
 *   func_021B7F38  0x021B7F38  thumb  ov070
 *   d_021BBBC0     0x021BBBC0  data  ov070  a1
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_021B6138 0x021B6138 thumb ov070
 *   func_021BB5A4  0x021BB5A4  thumb  ov070
 */
#include "../../matched/include/Obj20665.h"
#include "../../matched/include/Obj20666.h"

struct Rec;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj {
    u8 pad000[0x18];
    void *save;
    u8 pad01C[0x544 - 0x1C];
    u16 heap;
    u8 pad546[0x80C - 0x546];
    u32 pocket;
} Obj;

typedef struct Item {
    u16 id;
    u16 count;
} Item;

typedef struct Ent {
    Item item;
    u32 key;
} Ent;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void sub_02007CC8(u8 *base, void *buf, u32 id, int save);
extern int func_021B61C8(u8 *p);
extern void *func_02020F14(u32 a);
extern int func_02020F20(int h, int id, u16 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern void func_02049238(int h);
extern void MATH_QSort(void *head, u32 num, u32 width, int (*comp)(Ent *, Ent *), void *buf);
extern int func_021B7F38(Ent *a, Ent *b);
extern void func_020061E4(unsigned int id);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B6138(char *p);
void func_021B7F54(Obj *o);
void func_021B8080(u8 *p);
void func_021B809C(u8 *p);
void func_021B80BC(void *p);
extern char d_021BBBC0[];


void func_021B7F54(Obj *o)
{
    int i;
    Ent *ents;
    Item *items;
    int n;
    int h;
    int rec;
    u32 x;
    Ent *e;

    ents = func_02030734(o->heap, 0x9B0, 0, d_021BBBC0, 0xB35);
    items = func_02030734(o->heap, 0x4D8, 0, d_021BBBC0, 0xB36);
    sub_02007CC8(o->save, items, o->pocket, 1);
    n = func_021B61C8((u8 *)o);
    h = (int)func_02020F14(o->heap);
    for (i = 0; i < n; i++) {
        rec = func_02020F20(h, items[i].id, o->heap);
        e = &ents[i];
        x = func_02021014((struct Rec *)rec, 0xF);
        e->key = (x << 28) + (func_02021014((struct Rec *)rec, 0x11) << 16) + items[i].id;
        e->item = items[i];
        func_020307B0((void *)rec);
    }
    func_02049238(h);
    MATH_QSort(ents, n, 8, func_021B7F38, 0);
    for (i = 0; i < n; i++) {
        items[i] = ents[i].item;
    }
    sub_02007CC8(o->save, items, o->pocket, 0);
    func_020307B0(items);
    func_020307B0(ents);
}

void func_021B8080(u8 *p) { func_020061E4(0x663); func_0204B878(((struct Obj20665 *)p)->f72C,2); }

void func_021B809C(u8 *p) { func_021B7F54((struct Obj *)p); ((struct Obj20666 *)p)->f818=0xFFFF; func_021B6138((char *)p); }

void func_021B80BC(void *p)
{
    void func_021BB5A4(char *p);
    func_021BB5A4(p);
}
