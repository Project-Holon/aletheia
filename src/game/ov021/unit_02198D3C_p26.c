/*
 * file:     unit_02198D3C_p26.c
 * unit:     yes
 * function: func_0219B030, func_0219B060, func_0219B074, func_0219B0C4, func_0219B0D8, func_0219B0F0, func_0219B104, func_0219B120, func_0219B13C, func_0219B200, func_0219B2E8
 * address:  0x0219B030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0219B404  0x0219B404  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_020362DC  0x020362DC  arm
 *   func_020056EC  0x020056EC  thumb
 *   d_021D50F8  0x021D50F8  data  a4
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   d_021D4FEC  0x021D4FEC  data  a4
 *   func_02164168  0x02164168  thumb  ov010
 */
#include "../../matched/include/Obj17958.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 id; u32 *tbl; } Ent;

extern u32 func_0216DA50(u32);
extern u32 func_02197EDC(u8 *p);
extern int func_0219B358(u32 a);
extern void func_0219B404(u32 a, u8 *s);
extern unsigned int func_0203630C(void);
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern u16 func_0216D7C4(u8 *p);
extern u32 func_020362DC(void);
extern u32 func_020056EC(u32);
extern u16 func_0216D5A8(u8 *p);
extern u16 func_0216D5A0(void *p);
extern int func_0216D854(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D63C(char *a0, int a1);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern int func_02164168(int a);
int func_0219B030(u32 a, u32 b, u32 c, u32 d);
int func_0219B060(void);
int func_0219B074(int a);
int func_0219B0C4(void);
int func_0219B0D8(u32 *t, u32 v);
int func_0219B0F0(u32 a, u32 b);
u32 func_0219B104(u32 a, u32 b);
u32 *func_0219B120(u32 id);
int func_0219B13C(u32 a);
int func_0219B200(int a, int id, int end);
int func_0219B2E8(int a, u8 *b);
extern Ent d_021D50F8[];
extern u32 d_021D4FEC[];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219B030(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50(a);
    if (func_0219B358(a) == 1) {
        func_0219B404(a, (u8 *)(b + 8));
    }
    ((struct Obj17958 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}


int func_0219B060(void)
{
    if (func_0203630C() & 2) {
        return 1;
    }
    return 0;
}


int func_0219B074(int a)
{
    int t;

    t = (int)func_0216DEE0(func_0216D67C((void *)a));
    if (t != 0) {
        switch (func_0216D7C4((u8 *)t)) {
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0xa3:
        case 0xa4:
        case 0xa5:
        case 0xa6:
            return 1;
        }
    }
    return 0;
}


int func_0219B0C4(void)
{
    if (func_020362DC() & 2) {
        return 1;
    }
    return 0;
}

int func_0219B0D8(u32 *t, u32 v)
{
    int i;
    for (i = 0; v != t[i]; i++) {
    }
    return i;
}


int func_0219B0F0(u32 a, u32 b)
{
return *(u32 *)((u8 *)(a) + ((func_020056EC(func_0219B0D8((u32 *)a, b)) << 2)));
}


u32 func_0219B104(u32 a, u32 b)
{
    u32 *t = func_0219B120(a);
    return t[func_020056EC(func_0219B0D8(t, b))];
}


/*
 * The first key is the literal 0 held in a local (row 0 of the table has
 * key 0), then the walk reloads it at the loop bottom.
 */
u32 *func_0219B120(u32 id)
{
    Ent *p = d_021D50F8;
    u32 k = 0;
    do {
        if (k == id) {
            return p->tbl;
        }
        p++;
        k = p->id;
    } while (k != 0x27);
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_0219B13C(u32 a)
{
    int k;
    u32 v;
    u32 e;
    int i;
    u32 o;
    int ox, oy, ax, ay, r;
    int x0, x1, y0, y1;

    k = func_0216D5A8((u8 *)a);
    if (k != 1 && k != 2) {
        return 9;
    }
    if (func_0219B074(a) == 0) {
        return 9;
    }
    i = 0;
    v = func_0216D5A0((void *)a);
    do {
        e = d_021D4FEC[i++];
    } while (e != v && e != 0xFF);
    if (v != e) {
        return 9;
    }
    o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    if (o == 0) {
        return 9;
    }
    if (func_0216D854((void *)o) != func_0216D854((void *)a)) {
        return 9;
    }
    ox = func_0216D83C((void *)o);
    oy = func_0216D86C((void *)o);
    r = func_0216D63C((char *)a, 0);
    ax = func_0216D83C((void *)a);
    ay = func_0216D86C((void *)a);
    x0 = ax - r;
    x1 = ax + r;
    y0 = ay - r;
    y1 = ay + r;
    if (y0 <= oy && y1 >= oy && x0 <= ox && x1 >= ox) {
        return func_021642B4(ax, ay, ox, oy);
    }
    return 9;
}


int func_0219B200(int a, int id, int end)
{
    int *tbl;
    int n;
    int t;
    int i;
    int o;
    int ax;
    int ay;
    int ox;
    int oy;
    int dx;
    int dy;

    tbl = (int *)func_0219B120(id);
    n = func_0219B0D8((unsigned int *)tbl, end);
    if (n == 1) {
        return 9;
    }
    t = func_0219B13C(a);
    if (t != 9) {
        i = 0;
        do {
            if (t == tbl[i]) {
                return t;
            }
            i++;
        } while (i < n);
        o = (int)func_0216DEE0(func_0216D67C((void *)a));
        dx = 9;
        dy = 9;
        ax = func_0216D83C((void *)a);
        ay = func_0216D86C((void *)a);
        ox = func_0216D83C((void *)o);
        oy = func_0216D86C((void *)o);
        if (ax > ox) {
            dx = 2;
        } else if (ax < ox) {
            dx = 3;
        }
        if (ay > oy) {
            dy = 0;
        } else if (ay < oy) {
            dy = 1;
        }
        i = 0;
        if (dx == 9) {
            do {
                if (dy == tbl[i]) {
                    return dy;
                }
                i++;
            } while (i < n);
        } else if (dy == 9) {
            do {
                if (dx == tbl[i]) {
                    return dx;
                }
                i++;
            } while (i < n);
        } else {
            do {
                if (dx == tbl[i]) {
                    return dx;
                }
                if (dy == tbl[i]) {
                    return dy;
                }
                i++;
            } while (i < n);
        }
        return 9;
    }
    return t;
}


int func_0219B2E8(int a, u8 *b)
{
    if (func_0216D5A8((u8 *)a) != 12) {
        return 1;
    }
    if (b[0] == 0) {
        if (func_02164168(a) == 0) {
            return 0;
        }
        if (func_0219B0C4() == 0) {
            return 0;
        }
        b[0] = func_0216D63C((char *)a, 1);
    }
    if (b[0] != 0) {
        b[0]--;
    }
    return 1;
}
