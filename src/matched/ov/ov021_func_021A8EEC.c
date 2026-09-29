/*
 * function: func_021A8EEC
 * address:  0x021A8EEC
 * packet:   pkt_ov021_021A8EEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_021A90A4  0x021A90A4  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021A8E80  0x021A8E80  thumb  ov021
 *   func_021A8E78  0x021A8E78  thumb  ov021
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[0x24 - 0x20];
    int f24;
    int f28;
    int f2C;
    u8 pad30[0x34 - 0x30];
    Item items[7];
    int fF8;
    u8 padFC[0x124 - 0xFC];
    u32 f124;
} Obj;

extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_021A90A4(Obj *p, int k);
extern void func_020061E4(u32 se);
extern void func_0204B3DC(u32, int);
extern u32 func_021A8E80(Obj *p, u32 dir);
extern int func_021A8E78(u32 a, u32 b);
extern void func_020355D8(int v);

void func_021A8EEC(Obj *p)
{
    u32 trg;
    u32 rep;

    trg = func_020362DC();
    rep = func_0203633C();
    if (p->f2C == 0 && (trg | rep) != 0) {
        if ((trg & 2) || (trg & 0x400)) {
            func_021A90A4(p, 1);
            return;
        }
        func_020061E4(0x548);
        p->f2C = 1;
        p->fF8 = 0;
        p->f24 = 1;
        func_0204B3DC(p->f124, 1);
        return;
    }
    if (rep & 0x40) {
        if (func_021A8E80(p, 0) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x80) {
        if (func_021A8E80(p, 1) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x20) {
        if (func_021A8E80(p, 2) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x10) {
        if (func_021A8E80(p, 3) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if ((trg & 2) || (trg & 0x400)) {
        func_021A90A4(p, 1);
    } else if (trg & 1) {
        if (p->items[func_021A8E78(p->f1E, p->f1F)].f08 != 7) {
            func_021A90A4(p, 0);
            func_020355D8(0);
        }
    }
}
