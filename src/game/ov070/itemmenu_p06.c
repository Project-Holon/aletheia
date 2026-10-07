/*
 * file:     itemmenu_p06.c
 * unit:     yes
 * function: func_021B7D9C, func_021B7DD0, func_021B7DF4, func_021B7F38
 * address:  0x021B7D9C
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
 *   func_021BB1C4 0x021BB1C4 thumb ov070
 *   func_021BB260 0x021BB260 thumb ov070
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020414EC 0x020414EC arm
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_02035BA4  0x02035BA4  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B878  0x0204B878  arm
 *   d_021BB960     0x021BB960  data  a1
 */
#include "../../matched/include/Obj00002.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Obj {
    u8 pad000[0x724];
    u32 winA;
    u32 winB;
    u8 pad72C[0x7F0 - 0x72C];
    int repeat;
    int num;
} Obj;

typedef struct Item {
    u16 id;
    u16 count;
} Item;

typedef struct HitRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} HitRect;

typedef struct HitTbl {
    HitRect r[3];
} HitTbl;

typedef struct Ent {
    u16 id;
    u16 count;
    u32 key;
} Ent;

extern void func_021BB1C4(void *p);
extern void func_021BB260(u8 *p, int val);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020414EC(u32 i);
extern int func_021B61B8(u8 *p);
extern void *func_021B616C(u8 *p, int i);
extern int func_02035BA4(const void *p);
extern unsigned int func_0203633C(void);
extern void func_020061E4(unsigned int id);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021B7D9C(u8 *p, int v);
void func_021B7DD0(u8 *p);
int func_021B7DF4(Obj *o);
int func_021B7F38(Ent *a, Ent *b);
extern HitTbl d_021BB960;

void func_021B7D9C(u8 *p, int v) { ((struct Obj00002 *)p)->f7EC=v; func_021BB1C4(p); func_021BB260(p,((struct Obj00002 *)p)->f7F4); func_0204B3DC(((struct Obj00002 *)p)->f724,1); func_0204B3DC(((struct Obj00002 *)p)->f728,1); }

void func_021B7DD0(u8 *p) { func_020414EC(3); func_0204B3DC(((struct Obj00002 *)p)->f724,0); func_0204B3DC(((struct Obj00002 *)p)->f728,0); }


/*
 * Quantity selector input: touch buttons (hit table d_021BB960, with
 * auto-repeat accelerating after 120 frames) or the d-pad step the count at
 * +0x7F4 by 1 or 10, wrap it between 1 and the item's count, and redraw on
 * change. Returns whether any input was taken.
 */
int func_021B7DF4(Obj *o)
{
    HitTbl tbl;
    Item *e;
    int saved;
    int hit;
    int changed;
    int dir;

    changed = 0;
    saved = o->num;
    e = func_021B616C((u8 *)o, func_021B61B8((u8 *)o));
    tbl = d_021BB960;
    hit = func_02035BA4(&tbl);
    if (hit != -1) {
        o->repeat++;
        changed = 1;
    } else {
        o->repeat = 0;
    }
    if (o->repeat == 1 || o->repeat > 30) {
        switch (hit) {
        case 0:
            if (o->repeat > 120)
                o->num += 10;
            else
                o->num += 1;
            dir = 0;
            break;
        case 1:
            if (o->repeat > 120)
                o->num -= 10;
            else
                o->num -= 1;
            dir = 1;
            break;
        }
    }
    if (hit == -1) {
        if (func_0203633C() & 0x40) {
            o->num += 1;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x80) {
            o->num -= 1;
            dir = 1;
            changed = 1;
        } else if (func_0203633C() & 0x10) {
            o->num += 10;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x20) {
            o->num -= 10;
            dir = 1;
            changed = 1;
        }
    }
    if (e->count < o->num)
        o->num = 1;
    else if (o->num < 1)
        o->num = e->count;
    if (o->num != saved) {
        func_020061E4(0x548);
        if (dir == 0)
            func_0204B878((struct Obj *)o->winA, 0xB);
        else
            func_0204B878((struct Obj *)o->winB, 0xA);
        func_021BB260((u8 *)o, o->num);
    }
    return changed;
}


int func_021B7F38(Ent *a, Ent *b)
{
    if (a->key == b->key)
        return 0;
    if (a->key > b->key)
        return 1;
    return -1;
}
