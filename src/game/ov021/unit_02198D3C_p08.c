/*
 * file:     unit_02198D3C_p08.c
 * unit:     yes
 * function: func_02199490, func_021994C0, func_021994F0, func_02199520, func_02199550, func_02199584, func_021995B8, func_021995E8, func_02199618, func_0219964C, func_02199680, func_021996B4, func_021996E8, func_0219971C, func_02199750, func_02199784, func_021997B8, func_021997EC, func_02199820, func_02199854, func_02199888, func_02199970, func_02199AEC
 * address:  0x02199490
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
 *   func_0219912C  0x0219912C  thumb  ov021
 *   d_021D4BBC     0x021D4BBC  data  a4
 *   d_021D4BB0     0x021D4BB0  data  a4
 *   d_021D4BA4     0x021D4BA4  data  a4
 *   d_021D4B98  0x021D4B98  data  a4
 *   d_021D4B8C  0x021D4B8C  data  a4
 *   d_021D4B80  0x021D4B80  data  a4
 *   d_021D4B74  0x021D4B74  data  a4
 *   d_021D4B68  0x021D4B68  data  a4
 *   d_021D4B5C  0x021D4B5C  data  a4
 *   d_021D4B50  0x021D4B50  data  a4
 *   d_021D45E8  0x021D45E8  data  a4
 *   d_021D4B38  0x021D4B38  data  a4
 *   d_021D4B2C  0x021D4B2C  data  a4
 *   d_021D4B20  0x021D4B20  data  a4
 *   d_021D4B14  0x021D4B14  data  a4
 *   d_021D4B08  0x021D4B08  data  a4
 *   d_021D4AFC  0x021D4AFC  data  a4
 *   d_021D4AF0  0x021D4AF0  data  a4
 *   d_021D4AE4  0x021D4AE4  data  a4
 *   d_021D4AD8  0x021D4AD8  data  a4
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D848  0x0216D848  thumb  ov010
 *   func_0216D860  0x0216D860  thumb  ov010
 *   func_0216D87C  0x0216D87C  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 */
#include "../../matched/include/Obj04222.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u8  count;
    u8  axis;
    u8  moveAxis;
    u8  negate;
    int speed;
    int accum;
    u16 angle;
    u16 step;
} State;

extern void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern void func_0216D5E0(int a0, int a1);
extern int func_0216D600(int a0, u16 a1);
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA70(void *a0);
extern int func_0216D83C(void *p);
extern u32 func_0216D80C(u32, u32);
extern int func_0216D854(void *p);
extern u32 func_0216D818(u32, u32);
extern int func_0216D86C(void *p);
extern u32 func_0216D824(u32, u32);
extern void func_0216D848(char *p, short v);
extern void func_0216D860(char *p, short v);
extern void func_0216D87C(char *p, short v);
extern u32 func_0216D7CC(u32);
extern void *func_0216D6D4(void *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_0216D89C(u32, Vec *);
extern void func_0216D8C0(u32, Vec *);
extern void *func_0216D568(void *p, u32 v);
extern int func_02163F10(int a0);
int func_02199490(u32 a);
int func_021994C0(u32 a);
int func_021994F0(u32 a);
int func_02199520(u32 a);
int func_02199550(u32 a);
int func_02199584(u32 a);
int func_021995B8(u32 a);
int func_021995E8(u32 a);
int func_02199618(u32 a);
int func_0219964C(u32 a);
int func_02199680(u32 a);
int func_021996B4(u32 a);
int func_021996E8(u32 a);
int func_0219971C(u32 a);
int func_02199750(u32 a);
int func_02199784(u32 a);
int func_021997B8(u32 a);
int func_021997EC(u32 a);
int func_02199820(u32 a);
int func_02199854(u32 a);
void func_02199888(u32 a, int b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u8 i);
int func_02199970(u32 a);
int func_02199AEC(u32 a);
extern const Vec d_021D4BBC;
extern const Vec d_021D4BB0;
extern const Vec d_021D4BA4;
extern const Vec d_021D4B98;
extern const Vec d_021D4B8C;
extern const Vec d_021D4B80;
extern const Vec d_021D4B74;
extern const Vec d_021D4B68;
extern const Vec d_021D4B5C;
extern const Vec d_021D4B50;
extern const Vec d_021D45E8;
extern const Vec d_021D4B38;
extern const Vec d_021D4B2C;
extern const Vec d_021D4B20;
extern const Vec d_021D4B14;
extern const Vec d_021D4B08;
extern const Vec d_021D4AFC;
extern const Vec d_021D4AF0;
extern const Vec d_021D4AE4;
extern const Vec d_021D4AD8;
extern int *d_021DDBD4[2];


/*
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the const
 * Vec initialiser is an ov021 data start that another overlay mapped over the
 * same window also starts an object at, so the symbols hint is contested and
 * no single-reference witness exists.  No C change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * Addresses are Black-image addresses.
 */
int func_02199490(u32 a)
{
    Vec t = d_021D4BBC;
    func_0219912C(a, &t, 1, 0, 4, 4);
    return 1;
}


int func_021994C0(u32 a)
{
    Vec t = d_021D4BB0;
    func_0219912C(a, &t, 0, 1, 4, 4);
    return 1;
}


int func_021994F0(u32 a)
{
    Vec t = d_021D4BA4;
    func_0219912C(a, &t, 3, 2, 4, 4);
    return 1;
}


int func_02199520(u32 a)
{
    Vec t = d_021D4B98;
    func_0219912C(a, &t, 2, 3, 4, 4);
    return 1;
}


int func_02199550(u32 a)
{
    Vec t = d_021D4B8C;
    func_0219912C(a, &t, 1, 0, 2, 5);
    return 1;
}


int func_02199584(u32 a)
{
    Vec t = d_021D4B80;
    func_0219912C(a, &t, 0, 1, 2, 5);
    return 1;
}


int func_021995B8(u32 a)
{
    Vec t = d_021D4B74;
    func_0219912C(a, &t, 3, 2, 2, 5);
    return 1;
}


int func_021995E8(u32 a)
{
    Vec t = d_021D4B68;
    func_0219912C(a, &t, 2, 3, 2, 5);
    return 1;
}


int func_02199618(u32 a)
{
    Vec t = d_021D4B5C;
    func_0219912C(a, &t, 2, 0, 4, 10);
    return 1;
}


int func_0219964C(u32 a)
{
    Vec t = d_021D4B50;
    func_0219912C(a, &t, 3, 1, 4, 10);
    return 1;
}


int func_02199680(u32 a)
{
    Vec t = d_021D45E8;
    func_0219912C(a, &t, 1, 2, 4, 10);
    return 1;
}


int func_021996B4(u32 a)
{
    Vec t = d_021D4B38;
    func_0219912C(a, &t, 0, 3, 4, 10);
    return 1;
}


int func_021996E8(u32 a)
{
    Vec t = d_021D4B2C;
    func_0219912C(a, &t, 3, 0, 4, 10);
    return 1;
}


int func_0219971C(u32 a)
{
    Vec t = d_021D4B20;
    func_0219912C(a, &t, 2, 1, 4, 10);
    return 1;
}


int func_02199750(u32 a)
{
    Vec t = d_021D4B14;
    func_0219912C(a, &t, 0, 2, 4, 10);
    return 1;
}


int func_02199784(u32 a)
{
    Vec t = d_021D4B08;
    func_0219912C(a, &t, 1, 2, 4, 10);
    return 1;
}


int func_021997B8(u32 a)
{
    Vec t = d_021D4AFC;
    func_0219912C(a, &t, 1, 0, 4, 10);
    return 1;
}


int func_021997EC(u32 a)
{
    Vec t = d_021D4AF0;
    func_0219912C(a, &t, 0, 1, 4, 10);
    return 1;
}


int func_02199820(u32 a)
{
    Vec t = d_021D4AE4;
    func_0219912C(a, &t, 3, 2, 4, 10);
    return 1;
}


int func_02199854(u32 a)
{
    Vec t = d_021D4AD8;
    func_0219912C(a, &t, 2, 3, 4, 10);
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_02199888(u32 a, int b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u8 i)
{
    u8 *q;
    int dir;

    dir = 1;
    q = func_0216D6BC(a, 16, c);
    q[0] = e;
    ((struct Obj04222 *)q)->f4 = b;
    q[2] = g;
    q[1] = h;
    q[3] = i;
    ((struct Obj04222 *)q)->fE = 0x1000 / q[0];
    func_0216D5E0(a, (u16)c);
    func_0216D600(a, (u16)d);
    func_0216D674((void *)a, f);
    func_0216DA70((void *)a);
    func_0216D80C(a, func_0216D83C((void *)a));
    func_0216D818(a, func_0216D854((void *)a));
    func_0216D824(a, func_0216D86C((void *)a));
    if (b != 0) {
        switch (g) {
        case 0:
            if (b < 0)
                dir = -1;
            func_0216D848((char *)a, dir);
            break;
        case 1:
            if (b < 0)
                dir = -1;
            func_0216D860((char *)a, dir * 2);
            break;
        case 2:
            if (b < 0)
                dir = -1;
            func_0216D87C((char *)a, dir);
            break;
        }
    }
    func_0216D7CC(a);
}


int func_02199970(u32 a)
{
    State *p;
    Vec v;
    int t;
    int s;

    p = func_0216D6D4((void *)a);
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    switch (p->moveAxis) {
    case 0:
        v.x += p->speed;
        break;
    case 1:
        v.y += p->speed;
        break;
    case 2:
        v.z += p->speed;
        break;
    }
    func_0216D89C(a, &v);
    t = p->speed;
    if (t < 0)
        t = -t;
    p->accum += t;
    p->angle += p->step;
    if (p->angle > 0xF00)
        p->angle = 0xF00;
    {
    Vec w = { 0, 0, 0 };
    s = d_021DDBD4[1][(u16)(p->angle / 256)];
    if (p->negate == 1)
        s = -s;
    switch (p->axis) {
    case 0:
        w.x = s;
        break;
    case 1:
        w.y = s;
        break;
    case 2:
        w.z = s;
        break;
    }
    func_0216D8C0(a, &w);
    }
    p->count--;
    if (p->accum >= 0x10000 && p->count != 0) {
        int b;
        int dir;

        p->accum -= 0x10000;
        dir = 1;
        b = p->speed;
        func_0216D80C(a, func_0216D83C((void *)a));
        func_0216D818(a, func_0216D854((void *)a));
        func_0216D824(a, func_0216D86C((void *)a));
        switch (p->moveAxis) {
        case 0:
            if (b < 0)
                dir = -1;
            func_0216D848((char *)a, dir);
            break;
        case 1:
            if (b < 0)
                dir = -1;
            func_0216D860((char *)a, dir * 2);
            break;
        case 2:
            if (b < 0)
                dir = -1;
            func_0216D87C((char *)a, dir);
            break;
        }
    }
    if (p->count != 0)
        return 0;
    {
        Vec z = { 0, 0, 0 };
        func_0216D8C0(a, &z);
    }
    func_0216D568((void *)a, 0x540);
    func_02163F10(a);
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}


int func_02199AEC(u32 a)
{
    func_02199888(a, 0x2000, 2, 0, 8, 3, 1, 1, 0);
    return 1;
}
