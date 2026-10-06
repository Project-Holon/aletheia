/*
 * function: func_021B7DF4
 * address:  0x021B7DF4
 * packet:   pkt_ov070_021B7DF4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Quantity selector input: touch buttons (hit table d_021BB960, with
 * auto-repeat accelerating after 120 frames) or the d-pad step the count at
 * +0x7F4 by 1 or 10, wrap it between 1 and the item's count, and redraw on
 * change. Returns whether any input was taken.
 *
 * symbols:
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_02035BA4  0x02035BA4  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021BB260  0x021BB260  thumb  ov070
 *   d_021BB960     0x021BB960  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

extern HitTbl d_021BB960;

extern int func_021B61B8(u8 *p);
extern void *func_021B616C(u8 *p, int i);
extern int func_02035BA4(const void *p);
extern unsigned int func_0203633C(void);
extern void func_020061E4(unsigned int id);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021BB260(u8 *p, int val);

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
