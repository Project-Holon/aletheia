/*
 * file:     unit_021E0A80.c
 * unit:     yes
 * function: func_021E0A80, func_021E0B68, func_021E0BA4, func_021E0BE8, func_021E0C6C
 * address:  0x021E0A80
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021F2D78 0x021F2D78 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D6D54 0x021D6D54 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D5750 0x021D5750 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021B9A24   0x021B9A24  thumb ov093
 *   func_021D62C4   0x021D62C4  thumb ov093
 *   func_021C830C   0x021C830C  thumb ov093
 *   func_021C8290   0x021C8290  thumb ov093
 *   func_021E03F8  0x021E03F8  thumb  ov093
 */
#include "../../matched/include/Obj06268.h"

struct QL;
struct QQ;
struct R5;
struct UtilWork;
struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D6D54(struct R5 *p);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021D67B8(u8 *p);
extern int func_021D5750(void *, int);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern u16 func_021D70A8(struct QQ *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *, u32);
extern int func_021C815C(int *p);
extern int func_021D76BC(int key, u32 val);
int func_021B9A24(unsigned int a, unsigned int b);
int func_021D62C4(struct Unk021D62A8 *p, int i);
unsigned int func_021C830C(u8 *p);
int func_021C8290(u8 *p, int a, int b, void *item);
extern void func_021E03F8(int a, int b);
void func_021E0A80(void *a, void *q, int id);
u32 *func_021E0B5C(u32 *p);
void func_021E0B68(int a, void *b, int c);
void func_021E0BA4(int unused, void *q, int id, int *f);
void func_021E0BE8(void *a, int b, int c);
void func_021E0C6C(void *a, int b, int c);
extern u32 data_021F2D78[];

/*
 * follower: 021E0B5C store-return stub included; consecutive guards spelled separately.
 */
void func_021E0A80(void *a, void *q, int id)
{
    void *m;
    void *t;
    int move;
    int other;
    int slot;
    int text;
    u8 *r;
    if (id == func_021D775C(3)) {
        m = func_021C7CF4(q, id);
        t = func_021C7CF4(q, (u8)func_021D775C(6));
        move = func_021D67A8(t);
        other = func_021D67B8(t);
        if (other != move) move = other;
        if (move == 0) return;
        if (move == 166) return;
        if (move == 165) return;
        text = 448;
        if (move == text || func_021D5750(m, move) != 0 || func_021D6D54(m) != 0) return;
        slot = func_021D5778(m, func_021D70A8(a));
        if (slot == 4) return;
        r = func_021C88A4(q, 37, id);
        r[4] = id;
        r[5] = slot;
        ((struct Obj06268 *)r)->f8 = move;
        r[6] = 0;
        r[7] = 1;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 4, id);
        text += 240;
        func_021C8838(r + 4, 2, text);
        func_021C8860((struct S *)(r + 4), id);
        func_021C8860((struct S *)(r + 4), move);
        func_021C88C8(q, r);
    }
}

u32 *func_021E0B5C(u32 *p)
{
    *p = 4;
    return data_021F2D78;
}


void func_021E0B68(int a, void *b, int c)
{
    int n = 34;

    if (func_021C815C(b) == 0 || func_021C815C(b) == 3) {
        if (c == func_021D775C(2) && func_021D775C(n) == 0)
            func_021D76BC(n, 26);
    }
}


void func_021E0BA4(int unused, void *q, int id, int *f)
{
    u8 *m;

    if (id == func_021D775C(3)) {
        m = (u8 *)func_021C88A4(q, 4, id);
        func_021C8838(m + 4, 2, 0x29e);
        func_021C8860((struct S *)(m + 4), id);
        func_021C88C8(q, m);
        f[6] = 1;
    }
}


void func_021E0BE8(void *a, int b, int c)
{
    void *r;
    u8 k;
    u16 t;

    if (func_021C815C((int *)b) == 0)
        return;
    if (func_021C815C((int *)b) == 3)
        return;
    k = (u8)func_021D775C(3);
    r = func_021C7CF4((int *)b, c);
    if (func_021B9A24(c, k) != 0)
        return;
    if (func_021D775C(0x12) == 0x1fb)
        return;
    if (func_021D62C4(r, 0x21) != 0)
        return;
    if (func_021C830C((u8 *)b) != 0)
        return;
    t = (u16)func_021D775C(0x12);
    if (func_021C8290((u8 *)b, k, c, (void *)t) != 0)
        return;
    func_021D76BC(4, c);
}


void func_021E0C6C(void *a, int b, int c)
{
    func_021E03F8(c, func_021D70A8(a));
}
