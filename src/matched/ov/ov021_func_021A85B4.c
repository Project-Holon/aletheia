/*
 * function: func_021A85B4
 * address:  0x021A85B4
 * packet:   pkt_ov021_021A85B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021A12D4  0x021A12D4  thumb  ov021
 *   func_021A9294  0x021A9294  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021A8588  0x021A8588  thumb  ov021
 *   func_021A87A8  0x021A87A8  thumb  ov021
 *   func_020221A4  0x020221A4  thumb
 *   func_021A8EEC  0x021A8EEC  thumb  ov021
 *   func_021A8FFC  0x021A8FFC  thumb  ov021
 *   func_021A90E0  0x021A90E0  thumb  ov021
 *   func_0204B98C  0x0204B98C  arm
 *   func_02040588  0x02040588  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021A9080  0x021A9080  thumb  ov021
 *   func_0204B878  0x0204B878  arm
 *   func_021A0FA0  0x021A0FA0  thumb  ov021
 *   func_0201C4E4  0x0201C4E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
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

typedef struct Sel {
    u8 pad00[0x14];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    int f18;
} Sel;

typedef struct Obj {
    u16 f00;
    u16 f02;
    void *f04;
    void *f08;
    int f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u16 f1C;
    u8 f1E;
    u8 f1F;
    u8 f20;
    u8 f21;
    u8 pad22[2];
    int f24;
    int f28;
    int f2C;
    int f30;
    Item items[7];
    Sel *fF8;
    s16 fFC;
    u8 padFE[2];
    int f100;
    u8 pad104[0x124 - 0x104];
    u32 f124;
    u32 f128;
    void *f12C;
    void *f130;
} Obj;

extern int func_0201C6B4(void *p);
extern void func_021A12D4(void *a, u16 b);
extern void func_021A9294(Obj *p, Item *it);
extern void func_020061E4(u32 se);
extern int func_021A8588();
extern void func_021A87A8(Obj *p);
extern int func_020221A4(void);
extern void func_021A8EEC(Obj *p);
extern void func_021A8FFC(Obj *p);
extern void func_021A90E0(Obj *p);
extern u32 func_0204B98C(u32 v);
extern u32 func_02040588(u32, u32);
extern void func_0204B3DC(u32, int);
extern void func_021A9080(Obj *p, u8 a, u8 b);
extern void func_0204B878(u32, u16);
extern void func_021A0FA0(void *p, int v);
extern int func_0201C4E4(void *p);

void func_021A85B4(Obj *p)
{
    u8 i;
    s16 v;
    Sel *s;

    switch (p->f0C) {
    case 1:
        if (func_0201C6B4(p->f12C) == 1) {
            func_021A12D4(p->f08, p->f02);
            for (i = 0; i < 7; i++) {
                func_021A9294(p, &p->items[i]);
            }
            if (p->fFC != 0) {
                func_020061E4(0x554);
                p->f0C = 0;
            } else {
                p->f0C = 2;
                func_021A8588();
            }
        }
        break;
    case 0:
        v = p->fFC;
        if (v < 0x40) {
            p->fFC = 0;
            p->f0C = 3;
            func_021A8588();
        } else {
            p->fFC = v - 0x40;
            func_021A87A8(p);
        }
        p->f100 = 1;
        break;
    case 2:
        if (func_020221A4() == 1) {
            func_021A12D4(p->f08, p->f02);
            p->f0C = 3;
        }
        break;
    case 3:
        func_021A8EEC(p);
        func_021A8FFC(p);
        func_021A90E0(p);
        break;
    case 4:
        if (func_0204B98C(p->f128) != 0) {
            break;
        }
        p->f0C = 5;
        func_02040588(5, 1);
        func_02040588(6, 1);
        func_02040588(7, 1);
        func_02040588(4, 1);
        break;
    case 5:
        if (p->f28 == 1 || p->f1F == 3) {
            p->f0C = 9;
            func_020061E4(0x556);
            func_02040588(4, 0);
            func_02040588(5, 1);
            func_02040588(6, 1);
            func_02040588(7, 1);
            func_0204B3DC(p->f128, 0);
        } else {
            s = p->fF8;
            if (s->f18 != 0) {
                p->f20 = 0;
                func_021A9080(p, s->f14, s->f15);
                func_0204B878(p->f124, 1);
                func_0204B3DC(p->f124, 1);
                p->f0C = 6;
                func_020061E4(0x54C);
            } else {
                p->f0C = 8;
            }
        }
        break;
    case 6:
        p->f20++;
        if (func_0204B98C(p->f124) == 0) {
            p->f0C = 8;
        }
        break;
    case 7:
        func_021A0FA0(p->f08, 4);
        p->f0C = 10;
        break;
    case 8:
        func_021A0FA0(p->f08, 3);
        p->f0C = 10;
        break;
    case 9:
        if (p->fFC + 0x40 > 0xC0) {
            p->fFC = 0xC0;
            p->f0C = 7;
        } else {
            p->fFC += 0x40;
            func_021A87A8(p);
        }
        p->f100 = 1;
        break;
    }
    func_0201C4E4(p->f12C);
}
