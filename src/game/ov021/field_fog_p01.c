/*
 * file:     field_fog_p01.c
 * unit:     yes
 * function: func_0219F058, func_0219F0B0, func_0219F0F8, func_0219F114, func_0219F128, func_0219F17C, func_0219F188, func_0219F22C, func_0219F248, func_0219F25C, func_0219F2B0, func_0219F354, func_0219F3F0, func_0219F484, func_0219F490
 * address:  0x0219F058
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
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_02050848  0x02050848  arm
 *   func_02050880  0x02050880  arm
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 *   func_0216D6D8  0x0216D6D8  thumb  ov010
 *   func_0219FE9C  0x0219FE9C  thumb  ov021
 *   func_0219C814  0x0219C814  thumb  ov021
 *   func_0219C8D4  0x0219C8D4  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0219FEB0  0x0219FEB0  thumb  ov021
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 */
#include "../../matched/include/Obj17977.h"
#include "../../matched/include/Obj17978.h"
#include "../../matched/include/Obj02378.h"
#include "../../matched/include/Obj17979.h"
#include "../../matched/include/Obj05015.h"
#include "../../matched/include/Obj03121.h"
#include "../../matched/include/Obj17980.h"
#include "../../matched/include/Obj01851.h"

struct Trip;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct {
    u16 id;
    u8 pad[2];
    u8 f4;
    u8 f5;
    u8 f6;
} St;

extern u8 *func_0216E3C4(u32);
extern void *func_0216D6F0(void *p);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u8 *p);
extern u16 func_02050848(u8 *p, int i);
extern u16 func_02050880(u8 *p, int i);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_0205085C(void *p, int idx, u32 v);
extern void *func_0216D6D8(int a0, int a1);
extern void func_0219FE9C(u8 *);
extern int func_0219C814(u32 a, u16 *b);
extern u32 func_0219C8D4(u32, u32);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_0219FFBC(u32 a, u32 *p);
extern u32 func_02050080(u32 *p);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern void func_0219FEB0(u8 *s, u32 a, u32 r, u16 id);
extern u16 func_0216D678(void *p);
extern u32 func_0219FFD4(u32);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern u16 func_0216D598(void *p);
void func_0219F058(u32 a, u16 *o1, u16 *o2);
void func_0219F0B0(u32 a, u32 b, u32 c);
void func_0219F0F8(u32 a);
int func_0219F114(u32 a, u32 b, u32 c, u32 d);
void func_0219F128(u32 a);
int func_0219F17C(u32 a, u32 b, u32 c, u32 d);
void func_0219F188(u32 a);
void func_0219F22C(u32 a);
int func_0219F248(u32 a, u32 b, u32 c, u32 d);
void func_0219F25C(u32 a);
void func_0219F2B0(u32 a);
void func_0219F354(u32 a);
void func_0219F3F0(u32 a);
int func_0219F484(u32 a, u32 b, u32 c, u32 d);
void func_0219F490(u32 a);


void func_0219F058(u32 a, u16 *o1, u16 *o2)
{
    u16 *q;
    u32 r;
    if (func_0216E3C4(a)[2] == 1) {
        q = func_0216D6F0((void *)a);
        if (*q != 0xFFFF) {
            r = func_0219C9DC((u8 *)func_0216D910(a));
            *o1 = func_02050848((u8 *)r, *q);
            *o2 = func_02050880((u8 *)r, *q);
        } else {
            *o1 = 0;
            *o2 = 0;
        }
    } else {
        *o1 = 0;
        *o2 = 0;
    }
}


/*
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_0205082C:
 *   void func_0205082C(u8 *p, int i, u16 v)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 40;
 *       *(u16 *)(e + 0xe) = v;
 *       func_020500A0(e);   // 0x020500A0: extern void (u8 *), arm
 *   }
 *
 * Addresses are Black-image addresses.
 */
void func_0219F0B0(u32 a, u32 b, u32 c)
{
    u16 *q;
    u32 r;
    if (func_0216E3C4(a)[2] == 1) {
        q = func_0216D6F0((void *)a);
        if (*q != 0xFFFF) {
            r = func_0219C9DC((u8 *)func_0216D910(a));
            func_0205082C((void *)r, *q, b);
            func_0205085C((void *)r, *q, c);
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_0219F0F8(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    func_0219FE9C(q + 4);
    func_0219C814(a, (u16 *)q);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219F114(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17977 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}


/*
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_02050080:
 *   u32 func_02050080(u8 *p) { return *(u32 *)(p + 4); }
 *
 * Addresses are Black-image addresses.
 */
void func_0219F128(u32 a)
{
    s32 buf[3];
    u16 *q;
    u32 r;
    q = func_0216D6F0((void *)a);
    if (*q != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        func_0219FEB0((u8 *)(q + 2), a, r, *q);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, *q, (struct Trip *)buf);
    }
}


int func_0219F17C(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17978 *)((u8 *)(func_0216D6F0((void *)a))))->f0;
}


/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * Addresses are Black-image addresses.
 */
void func_0219F188(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 flag;
    u32 r;
    u32 x;
    u32 y;
    flag = 0;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj02378 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0219FFD4(a);
        y = func_0216D678((void *)a);
        if (q[4] != x) {
            q[4] = x;
            q[5] = y;
            func_0205082C((void *)r, ((struct Obj02378 *)q)->f0, x);
            flag = 1;
        } else if (q[5] != y) {
            func_0205082C((void *)r, ((struct Obj02378 *)q)->f0, x);
            func_0205085C((void *)r, ((struct Obj02378 *)q)->f0, flag);
            q[5] = y;
        }
        func_021A000C(a, r, ((struct Obj02378 *)q)->f0, flag, 0);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj02378 *)q)->f0, (struct Trip *)buf);
    }
}


void func_0219F22C(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    func_0219FE9C(q + 4);
    func_0219C814(a, (u16 *)q);
}


int func_0219F248(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17979 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}


void func_0219F25C(u32 a)
{
    s32 buf[3];
    u16 *q;
    u32 r;
    q = func_0216D6F0((void *)a);
    if (*q != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        func_0219FEB0((u8 *)(q + 2), a, r, *q);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, *q, (struct Trip *)buf);
    }
}


/*
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_0205082C:
 *   void func_0205082C(u8 *p, int i, u16 v)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 40;
 *       *(u16 *)(e + 0xe) = v;
 *       func_020500A0(e);   // 0x020500A0: extern void (u8 *), arm
 *   }
 *   func_02050080:
 *   u32 func_02050080(u8 *p) { return *(u32 *)(p + 4); }
 *
 * Addresses are Black-image addresses.
 */
void func_0219F2B0(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 flag;
    u32 r;
    u32 f;
    u32 x;
    u32 k;
    u32 w;
    flag = 0;
    f = 0;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj05015 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0219FFD4(a);
        if (func_0216D598((void *)a) == 0xCC) {
            f = 1;
        }
        k = func_0216E3C4(a)[3];
        if (k == 0xF) {
            k = 4;
        } else if (k == 5) {
            k = 8;
        } else {
            k = 0x10;
        }
        w = (u16)(k + x);
        if (q[4] != x) {
            q[4] = x;
            func_0205082C((void *)r, ((struct Obj05015 *)q)->f0, w);
            flag = 1;
        }
        func_021A000C(a, r, ((struct Obj05015 *)q)->f0, flag, f);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj05015 *)q)->f0, (struct Trip *)buf);
    }
}


void func_0219F354(u32 a)
{
    St *p;
    u32 h;
    u32 n;
    u32 v;
    u8 flag;
    u32 buf[3];

    p = func_0216D6F0((void *)a);
    if (p->id != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        n = func_0216D678((void *)a);
        if (n >= 10) {
            flag = 0;
            v = func_0219FFD4(a);
            if (n != p->f5) {
                flag = 1;
                p->f4 = v;
                p->f5 = n;
                p->f6 = 0;
                func_0205082C((void *)h, p->id, (u16)(n + 30));
            }
            func_021A000C(a, h, p->id, flag, 0);
        } else {
            func_0219FEB0(&p->f4, a, h, p->id);
        }
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), p->id, (struct Trip *)buf);
    }
}


void func_0219F3F0(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 r;
    u32 x;
    u32 y;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj03121 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0216D678((void *)a);
        if (x >= 10) {
            y = func_0219FFD4(a);
            if (x != q[5]) {
                q[4] = y;
                q[5] = x;
                q[6] = 0;
                func_0205082C((void *)r, ((struct Obj03121 *)q)->f0, (u16)(x + 0x1e));
            }
            func_021A000C(a, r, ((struct Obj03121 *)q)->f0, 1, 0);
        } else {
            func_0219FEB0((u8 *)((u16 *)(q + 4)), a, r, ((struct Obj03121 *)q)->f0);
        }
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj03121 *)q)->f0, (struct Trip *)buf);
    }
}


int func_0219F484(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17980 *)((u8 *)(func_0216D6F0((void *)a))))->f0;
}


void func_0219F490(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 x;
    u32 r;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj01851 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0216D678((void *)a);
        if (q[5] >= 2) {
            q[5] = 0;
            func_0205082C((void *)r, ((struct Obj01851 *)q)->f0, q[5]);
            func_0205085C((void *)r, ((struct Obj01851 *)q)->f0, 0);
        }
        if (x < 2 && q[5] != x) {
            q[5] = x;
            func_0205082C((void *)r, ((struct Obj01851 *)q)->f0, q[5]);
            func_0205085C((void *)r, ((struct Obj01851 *)q)->f0, 0);
        }
        func_021A000C(a, r, ((struct Obj01851 *)q)->f0, 0, 0);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj01851 *)q)->f0, (struct Trip *)buf);
    }
}
