/*
 * file:     unit_0219B508.c
 * unit:     yes
 * function: func_0219B508, func_0219B520, func_0219B59C, func_0219B6B0, func_0219B6E0, func_0219B75C, func_0219B8A8, func_0219B8BC, func_0219B8E8, func_0219B920, func_0219B924, func_0219B968, func_0219B984, func_0219B9B0, func_0219B9D8, func_0219BA0C, func_0219BA2C, func_0219BA6C, func_0219BAE0, func_0219BB08, func_0219BB38, func_0219BB3C, func_0219BB48, func_0219BB84, func_0219BBA4, func_0219BC48, func_0219BCC0, func_0219BCE4, func_0219BD30, func_0219BDC4, func_0219BE0C, func_0219BE18, func_0219BE24, func_0219BE30, func_0219BE3C, func_0219BE60, func_0219BE70, func_0219BEB4, func_0219BED0, func_0219BF00, func_0219BF3C, func_0219BF48, func_0219BF54, func_0219BF60, func_0219BF7C, func_0219BF88, func_0219BF94, func_0219BFA0, func_0219BFAC, func_0219BFB8, func_0219BFC4, func_0219BFD0, func_0219BFDC, func_0219C000, func_0219C034, func_0219C04C, func_0219C080, func_0219C0AC, func_0219C0D4, func_0219C0E8, func_0219C0F4, func_0219C100, func_0219C10C, func_0219C118, func_0219C13C, func_0219C150, func_0219C164, func_0219C180, func_0219C20C, func_0219C298, func_0219C2BC, func_0219C2E0, func_0219C314, func_0219C338
 * address:  0x0219B508
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
 *   func_0216D6A0  0x0216D6A0  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216D6B8  0x0216D6B8  thumb  ov010
 *   func_0219B494  0x0219B494  thumb  ov021
 *   func_0219B4C8  0x0219B4C8  thumb  ov021
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   d_021D5238     0x021D5238  data   ov021  a4
 *   d_021D5248     0x021D5248  data   ov021  a4
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   d_021D5258     0x021D5258  data   ov021  a4
 *   func_0203630C  0x0203630C  arm
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D5374  0x021D5374  data  a4
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   d_021D538C  0x021D538C  data  a4
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_021AE884  0x021AE884  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   d_021D5474     0x021D5474  data   ov021  a4
 *   d_021D537C  0x021D537C  data  a4
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021D5480     0x021D5480  data   ov021  a4
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021D046C  0x021D046C  thumb  ov021
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   d_021D53A0  0x021D53A0  data  a4
 *   func_0216D608  0x0216D608  thumb  ov010
 *   d_021D5394  0x021D5394  data  a4
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021D53B4  0x021D53B4  data  a4
 *   d_021D53D4  0x021D53D4  data  a4
 *   d_021D5414  0x021D5414  data  a4
 *   d_021D5434  0x021D5434  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   d_021D53F4  0x021D53F4  data  a4
 *   func_021639C0  0x021639C0  thumb  ov010
 *   d_021D5384     0x021D5384  data   a4
 *   d_021D5454     0x021D5454  data   ov021  a4
 *   func_021642A4  0x021642A4  thumb  ov010
 */
#include "../../matched/include/Obj17959.h"
#include "../../matched/include/Obj05008.h"
#include "../../matched/include/Obj05998.h"
#include "../../matched/include/Obj17960.h"
#include "../../matched/include/Obj03525.h"
#include "../../matched/include/Obj19649.h"
#include "../../matched/include/Obj05999.h"
#include "../../matched/include/Obj12076.h"
#include "../../matched/include/Obj19650.h"
#include "../../matched/include/Obj17961.h"
#include "../../matched/include/Obj17962.h"
#include "../../matched/include/Obj17963.h"
#include "../../matched/include/Obj17964.h"
#include "../../matched/include/Obj17965.h"
#include "../../matched/include/Obj17966.h"

struct Obj05999;
struct Ctx;
struct Rec;
struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct St_0219B520 {
    u8 state;
    s8 f1;
    s8 cur;
    s8 max;
} St_0219B520;

typedef struct Tbl4 { u32 w[4]; } Tbl4;

typedef struct Tbl22 { u32 w[2][2]; } Tbl22;

typedef struct St_0219B59C {
    u8 f0;
    u8 state;
    u8 f2;
    u8 f3;
    s8 f4;
    s8 f5;
    s8 f6;
    s8 f7;
    s8 f8;
} St_0219B59C;


typedef struct Tbl24 { u32 w[2][4]; } Tbl24;


typedef int (*Step)(u32, u8 *);

typedef struct { u32 a, b, c; } T12;

typedef struct { int x, y, z; } Vec;

extern void *func_0216D6A0(int a0, int a1);
extern int func_0216D63C(char *a0, int a1);
extern void *func_0216D6B8(void *p);
extern int func_0219B494(int a);
extern int func_0219B4C8(int a);
extern int func_0216DA5C(void *a0);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern u32 func_02197EDC(u8 *p);
extern u16 func_0216D5A8(u8 *p);
extern int func_02164168(int a);
extern u32 func_0216D5E0(int a0, int a1);
extern unsigned int func_0203630C(void);
extern void func_0216D674(void *p, u16 v);
extern void *func_0216D684();
extern void func_0216DA50(u8 *p);
extern u32 func_0216DAE0(u32, u32);
extern void *func_0216D69C();
extern void func_0216DA7C(u8 *p);
extern void func_0216DA44(u32 a);
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u16 func_0216D7C4(u8 *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern u16 func_0216D590(void *p);
extern int func_021AE884(u32 a);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern u32 func_0216D57C(void *p, u32 v);
extern int func_021641E8(int a);
extern u32 func_021641F8(u16);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D8C0(u32, void *);
extern void func_021AC154(u32);
extern u32 func_0216D534(void *p);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021D046C(u32, u32, u32);
extern int func_0216DB24(int a0);
u32 func_0219BF60();
u32 func_0219BF7C(u32 a);
u32 func_0219BF88(u32 a);
u32 func_0219BF94(u32 a);
u32 func_0219BFA0(u32 a);
u32 func_0219BFAC(u32 a);
u32 func_0219BFB8(u32 a);
u32 func_0219BFC4(u32 a);
u32 func_0219BFD0(u32 a);
extern u16 func_0216D608(void *p);
void func_0219C0D4();
void func_0219BFDC(u32 a);
int func_0219C000(char *a, u32 b, u32 c, u32 d);
int func_0219C034(u32 a, u32 b, u32 c, u32 d);
int func_0219C04C(u32 a, s8 *s);
int func_0219C080(char *a, u32 b, u32 c, u32 d);
int func_0219C0AC(u32 a, u32 b, u32 c, u32 d);
void func_0219C0E8(u32 a);
void func_0219C0F4(u32 a);
void func_0219C100(u32 a);
void func_0219C10C(u32 a);
extern int func_02163E34(u32, Vec *, u32 *);
extern int func_021AB11C(u32 attr);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021639C0(u32 a, u16 v);
extern u16 func_021642A4(int i);
void func_0219B508(u32 a);
int func_0219B520(int a);
int func_0219B59C(char *a);
void func_0219B6B0(u32 a);
int func_0219B6E0(int a);
int func_0219B75C(char *a);
int func_0219B8A8(void);
int func_0219B8BC(u32 a, u32 b, u32 c, u32 d);
void func_0219B8E8(u32 a);
void func_0219B920(void);
int func_0219B924(char *a, u8 *b);
int func_0219B968(u32 a, u32 b, u32 c, u32 d);
int func_0219B984(u32 a, u32 b);
void func_0219B9B0(u32 a, u8 *s);
int func_0219B9D8(u32 a, u8 *s);
void func_0219BA0C(u32 a, u8 *s);
int func_0219BA2C(int a);
int func_0219BA6C(char *a);
void func_0219BAE0(u32 a);
void func_0219BB08(u32 a);
void func_0219BB38(void);
void func_0219BB3C(void);
int func_0219BB48(char *a, u8 *s);
int func_0219BB84(u32 a, u32 b, u32 c, u32 d);
int func_0219BBA4(int a);
int func_0219BC48(int a, u8 *b);
int func_0219BCC0(int a, u8 *b, int c);
int func_0219BCE4(u32 a, u32 b);
int func_0219BD30(char *a, struct Obj05999 *b);
void func_0219BDC4(u32 a, u32 b);
void func_0219BE0C(u32 a);
void func_0219BE18(u32 a);
void func_0219BE24(u32 a);
void func_0219BE30(u32 a);
void func_0219BE3C(u32 a);
void func_0219BE60(u32 a);
void func_0219BE70(u32 a);
int func_0219BEB4(u32 a, u32 b);
int func_0219BED0(u32 a, u8 *s);
int func_0219BF00(u32 a, u32 b, u32 c, u32 d);
void func_0219BF3C(int a, u32 v);
int func_0219BF48(u32 a);
void func_0219BF54(int a0);
void func_0219C118(u32 a);
int func_0219C13C(u32 a, u8 *s);
int func_0219C150(char *a, u8 *s);
int func_0219C164(u32 a, u32 b, u32 c, u32 d);
int func_0219C180(u32 a, Vec *p, int b, int c);
int func_0219C20C(u32 a, Vec *p, int b, int c);
int func_0219C298(u32 a, int b, int c);
int func_0219C2BC(u32 a, int b, int c);
int func_0219C2E0(u32 a, int b, int c);
int func_0219C314(int a, int *s, u32 c);
int func_0219C338(char *a, u32 *s, u32 c);
extern Tbl4 d_021D5238;
extern Tbl22 d_021D5248;
extern Tbl24 d_021D5258;
extern Step d_021D5374[];
extern Step d_021D538C[];
extern T12 d_021D5474;
extern Step d_021D537C[];
extern T12 d_021D5480;
extern Step d_021D53A0[];
extern Step d_021D5394[];
extern int d_021D53B4[][2];
extern int d_021D53D4[][2];
extern int d_021D5414[][2];
extern int d_021D5434[][2];
extern int d_021D53F4[][2];
extern u32 d_021D5384[];
extern u32 d_021D5454[][2];



























void func_0219B508(u32 a)
{
    u8 *p = func_0216D6A0(a, 9);
    p[3] = func_0216D63C((char *)a, 1);
}



























int func_0219B520(int a)
{
    St_0219B520 *p;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0:
        if (func_0219B494(a) == 1) {
            p->state++;
        }
        break;
    case 1:
        if (func_0219B4C8(a) == 0) {
            break;
        }
        p->cur++;
        if (p->cur < p->max) {
            p->state = 0;
            break;
        }
        p->state++;
    case 2:
        if (func_0216DA5C((void *)a) == 1) {
            break;
        }
        p->state++;
        p->cur = 0;
        p->f1 = 0;
    case 3:
        return 1;
    }
    return 0;
}



























int func_0219B59C(char *a)
{
    St_0219B59C *p;
    int lim;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0: {
        Tbl4 t = d_021D5238;
        u16 v = func_0216D5F8((void *)a);
        p->f4 = v;
        p->f5 = t.w[v];
        p->state++;
    }
    case 1: {
        Tbl22 t = d_021D5248;
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)t.w[p->f5][p->f6], (u16)0)));
        p->state++;
    }
    case 2:
        if (func_02197EDC((u8 *)a) == 0) {
            return 1;
        }
        p->state++;
    case 3:
        lim = 8;
        if (func_0216D5A8((u8 *)a) == 14 && func_0219B8A8() == 1 && func_02164168((int)a) == 1) {
            lim = 4;
        }
        if (++p->f8 < lim) {
            return 1;
        }
        p->f8 = 0;
        if (++p->f7 < 4) {
            p->f6 = (p->f6 + 1) & 1;
            p->state = 1;
            return 1;
        }
        func_0216D5E0((int)a, p->f4);
        p->state++;
        p->f7 = 0;
        p->f0 = 0;
    }
    return 0;
}



























void func_0219B6B0(u32 a)
{
    u8 *p = func_0216D6A0(a, 9);
    u32 s;
    u8 v = 1;
    p[3] = func_0216D63C((char *)a, 1);
    s = func_0216D5A8((u8 *)a);
    if (s == 5 || s == 20 || s == 15) {
        v = 0;
    }
    p[5] = v;
}



























int func_0219B6E0(int a)
{
    St_0219B520 *p;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0:
        if (func_0219B494(a) == 1) {
            p->state++;
        }
        break;
    case 1:
        if (func_0219B4C8(a) == 0) {
            break;
        }
        p->cur++;
        if (p->cur < p->max) {
            p->state = 0;
            break;
        }
        p->state++;
    case 2:
        if (func_0216DA5C((void *)a) == 1) {
            break;
        }
        p->state++;
        p->cur = 0;
        p->f1 = 0;
    case 3:
        return 1;
    }
    return 0;
}



























int func_0219B75C(char *a)
{
    Tbl24 t = d_021D5258;
    St_0219B59C *p;
    int lim;
    int i;
    u16 v;
    u16 k;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0:
        v = func_0216D5F8((void *)a);
        for (i = 0; i < 4 && v != t.w[p->f5][i]; i++) {
        }
        i++;
        p->f4 = v;
        p->f6 = i % 4;
        p->state++;
    case 1:
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)t.w[p->f5][p->f6], (u16)0)));
        p->state++;
    case 2:
        if (func_02197EDC((u8 *)a) == 0) {
            return 1;
        }
        p->state++;
    case 3:
        lim = 8;
        k = func_0216D5A8((u8 *)a);
        if ((k == 15 || k == 16) && func_0219B8A8() == 1 && func_02164168((int)a) == 1) {
            lim = 4;
        }
        if (++p->f8 < lim) {
            return 1;
        }
        p->f8 = 0;
        if (++p->f7 < 4) {
            p->f6 = (p->f6 + 1) % 4;
            p->state = 1;
            return 1;
        }
        func_0216D5E0((int)a, p->f4);
        p->state++;
        p->f7 = 0;
        p->f0 = 0;
    }
    return 0;
}



























int func_0219B8A8(void)
{
    if (func_0203630C() & 2) {
        return 1;
    }
    return 0;
}


























/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219B8BC(u32 a, u32 b, u32 c, u32 d)
{
func_0219B984(a, (u32)func_0216D684(a, 8, c, d));
func_0216D674((void *)a, 0);
func_0216DA50((u8 *)a);
return func_0216DAE0(a, 0);
}

























void func_0219B8E8(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    if (func_0219B984(a, (u32)p)) {
        func_0216DAE0((u32)((unsigned int *)a), 0);
        while (d_021D5374[p[0]](a, p) == 1) {
        }
    }
}























void func_0219B920(void) {}


























int func_0219B924(char *a, u8 *b)
{
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    if (func_0219B9D8((u32)a, b) == 1) {
        func_0219BA0C((u32)a, b);
        if (func_0219BA6C(a) == 1) {
            func_0216DA44((u32)a);
            b[0]++;
            return 1;
        }
    }
    return 0;
}



























/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219B968(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50((u8 *)a);
    ((struct Obj17959 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}



























int func_0219B984(u32 a, u32 b)
{
if (func_0216DEE0((void *)func_0216D67C((void *)a)) == 0) {
    ((struct Obj05008 *)((u8 *)(b)))->f1 = 0;
    return 0;
}
if (((struct Obj05008 *)((u8 *)(b)))->f1 == 0) {
    func_0219B9B0(a, (u8 *)b);
}
return 1;
}



























void func_0219B9B0(u32 a, u8 *s)
{
    u32 o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    s[1] = 1;
    ((struct Obj05008 *)s)->f2 = func_0216D83C((void *)o);
    ((struct Obj05008 *)s)->f4 = func_0216D86C((void *)o);
    ((struct Obj05008 *)s)->f6 = 0xFF;
}



























int func_0219B9D8(u32 a, u8 *s)
{
    u32 o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    int x;
    int y;
    if (o != 0) {
        x = func_0216D83C((void *)o);
        y = func_0216D86C((void *)o);
        if (x != *(s16 *)&((struct Obj05998 *)s)->f2 || y != *(s16 *)&((struct Obj05998 *)s)->f4) {
            return 1;
        }
    }
    return 0;
}


























void func_0219BA0C(u32 a, u8 *s)
{
    u32 o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    ((struct Obj05998 *)s)->f2 = func_0216D83C((void *)o);
    ((struct Obj05998 *)s)->f4 = func_0216D86C((void *)o);
}


























int func_0219BA2C(int a)
{
    int v;

    func_0216DEE0(func_0216D67C((void *)a));
    v = func_0216D7C4((u8 *)a);
    switch (v) {
    case 0x58:
        return 0x10;
    case 0x59:
        return 0x11;
    case 0x5a:
        return 0x12;
    case 0x5b:
        return 0x13;
    }
    return v;
}


























int func_0219BA6C(char *a)
{
    int o;
    int x;
    int y;
    int tx;
    int ty;
    int k;

    o = (int)func_0216DEE0(func_0216D67C((void *)a));
    x = func_0216D83C((void *)a);
    y = func_0216D86C((void *)a);
    tx = func_0216D804((void *)o);
    ty = func_0216D81C((void *)o);
    if (x != tx || y != ty) {
        k = func_0219BA2C((int)a);
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)((int)func_021642B4(x, y, tx, ty)), (u16)k)));
        return 1;
    }
    return 0;
}

























void func_0219BAE0(u32 a)
{
    u8 *p = func_0216D684(a, 12);
    func_0219BC48(a, p);
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
    p[1] = 0;
}

























void func_0219BB08(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    if (func_0219BC48(a, p)) {
        while (d_021D538C[p[0]](a, p) == 1) {
        }
    }
}





















void func_0219BB38(void) {}























void func_0219BB3C(void)
{
    char *p = func_0216D69C();

    p[1] = 0;
}























int func_0219BB48(char *a, u8 *s)
{
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    if (func_0219BCE4((u32)a, (u32)s) == 1 && func_0219BD30(a, (struct Obj05999 *)s) == 1) {
        func_0216DA44((u32)a);
        s[0]++;
        return 1;
    }
    return 0;
}























int func_0219BB84(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 0) {
    return 0;
}
func_0216DA50((u8 *)a);
((struct Obj17960 *)((u8 *)(b)))->f0 = 0;
return 0;
}























int func_0219BBA4(int a)
{
    int out;
    u32 iter;
    u32 kind;
    int r7;
    int r6;
    int r5;

    iter = 0;
    kind = func_0216D5A8((u8 *)a);
    r7 = func_0216D590((void *)a);
    r6 = (int)func_0216D67C((void *)a);
    r5 = func_021AE884(a);
    switch (kind) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 20:
        while (func_0216DD1C((struct Ctx *)r6, (struct Rec **)(&out), &iter) == 1) {
            if (a != out && r7 == func_0216D590((void *)out) && r5 == func_021AE884(out)) {
                return out;
            }
        }
        break;
    }
    return 0;
}























int func_0219BC48(int a, u8 *b)
{
    u32 iter;
    int out;
    int r7;
    int r6;
    int t;

    t = (int)func_0216D67C((void *)a);
    iter = 0;
    r7 = func_0216D590((void *)a);
    r6 = func_021AE884(a);
    while (func_0216DD1C((struct Ctx *)t, (struct Rec **)(&out), &iter) == 1) {
        if (a != out && r7 == func_0216D590((void *)out) && r6 == func_021AE884(out)) {
            if (b[1] == 0) {
                func_0219BCC0(a, b, out);
            }
            return 1;
        }
    }
    b[1] = 0;
    return 0;
}























int func_0219BCC0(int a, u8 *b, int c)
{
((struct Obj03525 *)((u8 *)(b)))->f1 = 1;
((struct Obj03525 *)((u8 *)(b)))->f2 = func_0216D83C((void *)c);
((struct Obj03525 *)((u8 *)(b)))->f4 = func_0216D86C((void *)c);
((struct Obj03525 *)((u8 *)(b)))->f6 = 255;
((struct Obj03525 *)((u8 *)(b)))->f8 = c;
return 255;
}























int func_0219BCE4(u32 a, u32 b)
{
    u32 c = ((struct Obj19649 *)b)->f8;
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 p = func_0216D804((void *)c);
    u32 q = func_0216D81C((void *)c);
    if (x != p || y != q) {
        if (func_0216DA5C((void *)c) == 1 || func_0216D57C((void *)c, 0x1808) == 0) {
            return 1;
        }
    }
    return 0;
}























int func_0219BD30(char *a, struct Obj05999 *b)
{
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 px = func_0216D83C((void *)(b->f8));
    u32 py = func_0216D86C((void *)(b->f8));
    u32 pz = func_0216D804((void *)(b->f8));
    u32 pw = func_0216D81C((void *)(b->f8));
    u32 r;
    if (x == px && y == py) {
        return 0;
    }
    r = func_021642B4(x, y, pz, pw);
    x += (u32)func_021641E8((u16)r);
    y += func_021641F8(r);
    if (x != px || y != py) {
        func_0216D438(a, (u16)func_02197E7C(r & 0xFFFF, 12));
        return 1;
    }
    return 0;
}























void func_0219BDC4(u32 a, u32 b)
{
    T12 t;
    u32 k = 8;
    ((u8 *)func_0216D684(a, 8))[1] = b;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
    func_0216D568((void *)a, k << 12);
    t = d_021D5474;
    func_0216D8C0(a, &t);
}



















void func_0219BE0C(u32 a) { func_0219BDC4(a, 0); }


















void func_0219BE18(u32 a) { func_0219BDC4(a, 1); }

















void func_0219BE24(u32 a) { func_0219BDC4(a, 1); }
















void func_0219BE30(u32 a) { func_0219BDC4(a, 0); }




















void func_0219BE3C(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D537C[p[0]](a, p) == 1) {
    }
}




















void func_0219BE60(u32 a)
{
    u32 r = func_0219BF48(a);
    if (r != 0) {
        func_021AC154(r);
    }
}




















void func_0219BE70(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    T12 t;
    p[0] = 0;
    func_0219BF3C(a, 0);
    if (p[2] == 0) {
        t = d_021D5480;
        func_0216D8C0(a, &t);
        func_0216D568((void *)a, 2 << 14);
    }
}




















int func_0219BEB4(u32 a, u32 b)
{
return func_021D046C(func_02188CD0((u8 *)func_0216D534(func_0216D67C((void *)a))), a, b);
}




















int func_0219BED0(u32 a, u8 *s)
{
    if (s[2] == 0) {
        func_0219BF3C(a, func_0219BEB4(a, s[1]));
    }
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    s[0]++;
    return 0;
}




















int func_0219BF00(u32 a, u32 b, u32 c, u32 d)
{
if (((struct Obj12076 *)((u8 *)(b)))->f2 == 0) {
    if (func_0219BF48(a) == 0) {
        if (func_0216DB24(a) == 1) {
            func_0219BF3C(a, func_0219BEB4(a, ((struct Obj12076 *)((u8 *)(b)))->f1));
        }
    }
    func_0216D568((void *)a, (2 << 14));
}
return 0;
}




















void func_0219BF3C(int a, u32 v)
{
    ((struct Obj19650 *)((char *)func_0216D69C()))->f4 = v;
}


















int func_0219BF48(u32 a)
{
return ((struct Obj17961 *)((u8 *)(func_0216D69C((void *)a))))->f4;
}


















void func_0219BF54(int a0)
{
    char *p = func_0216D69C();

    p[2] = 1;
}


















u32 func_0219BF60(a, b, c, a3)
u32 a, b, c, a3;















{
    u8 *p = func_0216D684(a, 4, c, a3);
    p[1] = 9;
    p[2] = c;
    return func_0216D5E0(a, 0);
}

u32 func_0219BF7C(u32 a) { return func_0219BF60(a, 0, 0); }

u32 func_0219BF88(u32 a) { return func_0219BF60(a, 1, 0); }

u32 func_0219BF94(u32 a) { return func_0219BF60(a, 2, 0); }

u32 func_0219BFA0(u32 a) { return func_0219BF60(a, 3, 0); }

u32 func_0219BFAC(u32 a) { return func_0219BF60(a, 0, 1); }

u32 func_0219BFB8(u32 a) { return func_0219BF60(a, 1, 1); }

u32 func_0219BFC4(u32 a) { return func_0219BF60(a, 2, 1); }

u32 func_0219BFD0(u32 a) { return func_0219BF60(a, 3, 1); }





void func_0219BFDC(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D53A0[p[0]](a, p) == 1) {
    }
}





int func_0219C000(char *a, u32 b, u32 c, u32 d)
{
func_0216D438(a, (((u32)func_02197E7C((u32)(((u32)func_0216D5F8((void *)a) << 16) >> 16), (u32)0) << 16) >> 16));
func_0216DA50((u8 *)a);
func_0216DA7C((u8 *)a);
((struct Obj17962 *)((u8 *)(b)))->f0 = 1;
return 1;
}





int func_0219C034(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    ((struct Obj17963 *)((u8 *)(b)))->f0 = 2;
    return 1;
}
return 0;
}





int func_0219C04C(u32 a, s8 *s)
{
    u32 o;
    if (s[1] == 9) {
        o = (u32)func_0216DEE0(func_0216D67C((void *)a));
        if (o != 0) {
            s[1] = func_0216D608((void *)o);
        }
    }
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    s[0] = 3;
    return 1;
}




int func_0219C080(char *a, u32 b, u32 c, u32 d)
{
func_0216D438(a, (((u32)func_02197E7C((u32)func_0216D608(func_0216DEE0((void *)func_0216D67C((void *)a))), (u32)0) << 16) >> 16));
((struct Obj17964 *)((u8 *)(b)))->f0 = 4;
return 1;
}




int func_0219C0AC(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 0) {
    return 0;
}
func_0216DA50((u8 *)a);
func_0216DA7C((u8 *)a);
((struct Obj17965 *)((u8 *)(b)))->f0 = 2;
return 0;
}




void func_0219C0D4(a, b, c, a3)
u32 a, b, c, a3;






{
    u32 *p = func_0216D684(a, 12, c, a3);
    p[1] = b;
    p[2] = c;
}

void func_0219C0E8(u32 a) { func_0219C0D4(a, 0, 0); }

void func_0219C0F4(u32 a) { func_0219C0D4(a, 1, 1); }

void func_0219C100(u32 a) { func_0219C0D4(a, 2, 0); }

void func_0219C10C(u32 a) { func_0219C0D4(a, 2, 1); }





void func_0219C118(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D5394[p[0]](a, p) == 1) {
    }
}





int func_0219C13C(u32 a, u8 *s)
{
    func_0216DA50((u8 *)a);
    s[0]++;
    return 1;
}





int func_0219C150(char *a, u8 *s)
{
    func_0219C338(a, (u32 *)s, 12);
    s[0]++;
    return 1;
}





/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 ((u8 *)0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219C164(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50((u8 *)a);
    ((struct Obj17966 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}




/*
 * r = 0 is the first statement: its early live range pushes a to a stack
 * spill and leaves ip for &t.
 */
int func_0219C180(u32 a, Vec *p, int b, int c)
{
    int r;
    s16 x;
    s16 z;
    Vec t;
    u32 out;

    r = 0;
    t = *p;
    x = (p->x >> 4) / 4096;
    z = (p->z >> 4) / 4096;
    x += (s16)d_021D53B4[b][c];
    z += (s16)d_021D53D4[b][c];
    t.x = x << 16;
    t.z = z << 16;
    if (func_02163E34(a, &t, &out) == 1 && func_021AB11C(out) != 0) {
        r = 1;
    }
    return r;
}




int func_0219C20C(u32 a, Vec *p, int b, int c)
{
    int r;
    s16 x;
    s16 z;
    Vec t;
    u32 out;

    r = 0;
    t = *p;
    x = (p->x >> 4) / 4096;
    z = (p->z >> 4) / 4096;
    x += (s16)d_021D5414[b][c];
    z += (s16)d_021D5434[b][c];
    t.x = x << 16;
    t.z = z << 16;
    if (func_02163E34(a, &t, &out) == 1 && func_021AB11C(out) != 0) {
        r = 1;
    }
    return r;
}




int func_0219C298(u32 a, int b, int c)
{
    Vec v;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    return func_0219C180(a, &v, b, c);
}




int func_0219C2BC(u32 a, int b, int c)
{
    Vec v;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    return func_0219C20C(a, &v, b, c);
}




int func_0219C2E0(u32 a, int b, int c)
{
    if (func_0219C298(a, b, c) == 0) {
        if (func_0219C2BC(a, b, c) == 0) {
            return 9;
        }
        b = d_021D53F4[b][c];
    }
    return b;
}




int func_0219C314(int a, int *s, u32 c)
{
    int v = func_0219C2E0(a, *s, c);
    *s = v;
    if (v != 9) {
        return func_021639C0(a, v);
    }
    return 0;
}




int func_0219C338(char *a, u32 *s, u32 c)
{
    u32 t;
    u32 k;
    u32 v;
    int r;

    k = s[2];
    t = func_0216D608((void *)a);
    r = func_0219C314((int)a, (int *)(&t), k);
    if (t == 9) {
        t = func_0216D608((void *)a);
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
        return 0;
    }
    if (r == 0) {
        v = (u32)func_02197E7C((u16)t, (u16)c);
        func_0216DA44((int)a);
        func_0216D438(a, (u16)v);
        return 1;
    }
    if ((1 & r) && s[1] == 2) {
        t = func_021642A4(func_0216D608((void *)a));
        k = d_021D5384[k];
        s[2] = k;
        r = func_0219C314((int)a, (int *)(&t), k);
        if (t == 9) {
            t = func_0216D608((void *)a);
            func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
            return 0;
        }
        if (r == 0) {
            v = (u32)func_02197E7C((u16)t, (u16)c);
            func_0216DA44((int)a);
            func_0216D438(a, (u16)v);
            return 1;
        }
    }
    if (r & 2) {
        t = d_021D5454[t][k];
        r = func_0219C314((int)a, (int *)(&t), k);
        if (t == 9) {
            t = func_0216D608((void *)a);
            func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
            return 0;
        }
        if (r == 0) {
            v = (u32)func_02197E7C((u16)t, (u16)c);
            func_0216DA44((int)a);
            func_0216D438(a, (u16)v);
            return 1;
        }
    }
    t = func_0216D608((void *)a);
    func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
    return 0;
}
