/*
 * file:     field_fog_p05.c
 * unit:     yes
 * function: func_0219FB48, func_0219FB5C, func_0219FC5C, func_0219FC68, func_0219FCC0, func_0219FD1C, func_0219FD94, func_0219FE20
 * address:  0x0219FB48
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
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0219C8D4  0x0219C8D4  thumb  ov021
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0205082C  0x0205082C  arm
 *   func_02050848  0x02050848  arm
 *   func_02050880  0x02050880  arm
 *   func_020508EC  0x020508EC  arm
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 */
#include "../../matched/include/Obj17983.h"
#include "../../matched/include/Obj01496.h"
#include "../../matched/include/Obj17984.h"

struct Trip;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern void *func_0216D6F0(void *p);
extern u32 func_0219C8D4(u32, u32);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u8 *p);
extern u16 func_0216D598(void *p);
extern u16 func_0216D678(void *p);
extern u32 func_0219FFD4(u32);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_0219FFBC(u32 a, u32 *p);
extern u32 func_02050080(u32 *p);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern u16 func_02050848(u8 *p, int i);
extern u16 func_02050880(u8 *p, int i);
extern int func_0216D7A8(void *p, unsigned int v);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
int func_0219FB48(u32 a, u32 b, u32 c, u32 d);
void func_0219FB5C(u32 a);
int func_0219FC5C(u32 a, u32 b, u32 c, u32 d);
int func_0219FC68(u32 a, u16 *o1, u16 *o2);
int func_0219FCC0(u32 a, u16 *o1, u16 *o2);
void func_0219FD1C(u32 a);
void func_0219FD94(u32 a);
u32 func_0219FE20(u32 a, u32 a1, u32 a2, u32 a3);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219FB48(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17983 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}


/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * Addresses are Black-image addresses.
 */
void func_0219FB5C(u32 a)
{
    s32 buf[3];
    u32 flag;
    u32 r;
    u32 x;
    u8 *q;
    u32 t;
    u32 y;
    u32 m;

    flag = 0;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj01496 *)q)->f0 == 0xFFFF)
        return;
    r = func_0219C9DC((u8 *)func_0216D910(a));
    t = func_0216D598((void *)a);
    x = func_0216D678((void *)a);
    if (t == 0xd3 || t == 0xd5 || t == 0x79) {
        m = 0;
        if (x == q[5])
            goto tail;
        switch (x) {
        case 10:
            m = 1;
            break;
        case 11:
            m = 2;
            break;
        case 12:
            m = 3;
            break;
        }
        q[5] = x;
        func_0205082C((void *)r, ((struct Obj01496 *)q)->f0, m);
        flag = 1;
    } else if (t == 0xd4 || t == 0xd6) {
        y = func_0219FFD4(a);
        m = 0;
        if (x < 10) {
            if (y == q[4] && x == q[5])
                goto tail;
            if (y == 0)
                m = 0;
            else if (y == 1)
                m = 1;
            q[4] = y;
        } else {
            if (x == q[5])
                goto tail;
            switch (x) {
            case 10:
                m = 2;
                break;
            case 11:
                m = 3;
                break;
            }
        }
        q[5] = x;
        func_0205082C((void *)r, ((struct Obj01496 *)q)->f0, m);
        flag = 1;
    } else {
        if (x == q[5])
            goto tail;
        q[5] = x;
        func_0205082C((void *)r, ((struct Obj01496 *)q)->f0, flag);
        flag = 1;
    }
tail:
    func_021A000C(a, r, ((struct Obj01496 *)q)->f0, flag, 1);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    func_0204F638((u8 *)func_02050080((u32 *)r), ((struct Obj01496 *)q)->f0, (struct Trip *)buf);
}


int func_0219FC5C(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17984 *)((u8 *)(func_0216D6F0((void *)a))))->f0;
}


/*
 * Blocked at MATCH: func_02050848 (0x02050848), func_02050880 (0x02050880) is an unlabelled arm9 leaf
 * (Ilias's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u16 func_02050848(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0xe); }  (EXACT, verified)
 *   u16 func_02050880(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }  (EXACT, verified)
 *
 * Addresses are Black-image addresses.
 */
int func_0219FC68(u32 a, u16 *o1, u16 *o2)
{
    u32 t;
    u16 *p;
    u32 h;

    t = func_0216D598((void *)a);
    if (t == 0xD3 || t == 0xD5) {
        p = func_0216D6F0((void *)a);
        if (*p != 0xFFFF) {
            h = func_0219C9DC((u8 *)func_0216D910(a));
            *o1 = func_02050848((u8 *)h, *p);
            *o2 = func_02050880((u8 *)h, *p);
            return 1;
        }
        return 0;
    }
    *o1 = 0;
    *o2 = 0;
    return 1;
}


int func_0219FCC0(u32 a, u16 *o1, u16 *o2)
{
    u16 *p;
    u32 h;

    if ((u16)(func_0216D598((void *)a) + 0xFF23) <= 1) {
        p = func_0216D6F0((void *)a);
        if (*p != 0xFFFF) {
            h = func_0219C9DC((u8 *)func_0216D910(a));
            *o1 = func_02050848((u8 *)h, *p);
            *o2 = func_02050880((u8 *)h, *p);
            return 1;
        }
        return 0;
    }
    *o1 = 0;
    *o2 = 0;
    return 1;
}


void func_0219FD1C(u32 a)
{
    u32 flag;
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;

    flag = 0;
    p = func_0216D6F0((void *)a);
    if (*p != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        v = func_0216D678((void *)a);
        if (v != ((u8 *)p)[5] && v < 2) {
            ((u8 *)p)[5] = v;
            func_0205082C((void *)h, *p, v);
            flag = 1;
        }
        func_021A000C(a, h, *p, flag, 0);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), *p, (struct Trip *)buf);
    }
}


void func_0219FD94(u32 a)
{
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;
    u32 flag;

    flag = 0;
    p = func_0216D6F0((void *)a);
    if (*p != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        v = func_0216D678((void *)a);
        if (v != ((u8 *)p)[5]) {
            switch (v) {
            case 10: flag = 1; break;
            case 11: flag = 2; break;
            case 12: flag = 3; break;
            }
            ((u8 *)p)[5] = v;
            func_0205082C((void *)h, *p, flag);
            flag = 1;
        }
        func_021A000C(a, h, *p, flag, 0);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), *p, (struct Trip *)buf);
    }
}


/*
 * Blocked at MATCH: func_020508EC (0x020508EC) is an unlabelled arm9 leaf
 * (Ilias's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u32 func_020508EC(u8 *p, int i, u16 *out) reads a u16 at record+0x1C, stores it, returns a range test; see the pending ov021 files that already name it
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219FE20(u32 a, u32 a1, u32 a2, u32 a3)
{
    u32 t;
    u16 out;

    if (func_0216D598((void *)a) != 0x7B) {
        return 1;
    }
    t = (u16)func_0216D7A8((void *)a, 0);
    if (t != 0xFFFF) {
        if (func_020508EC((u8 *)func_0219C9DC((u8 *)func_0216D910(a)), t, &out) == 1) {
            return 1;
        }
    }
    return 0;
}
