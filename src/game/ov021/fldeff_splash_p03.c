/*
 * file:     fldeff_splash_p03.c
 * unit:     yes
 * function: func_021C4C54, func_021C4CDC, func_021C4D14
 * address:  0x021C4C54
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
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216DBE8  0x0216DBE8  thumb  ov010
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021C6844  0x021C6844  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_021C6828  0x021C6828  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202B928  0x0202B928  thumb
 *   func_0202B920  0x0202B920  thumb
 *   d_021DE48C     0x021DE48C  data  a4
 */
#include "../../matched/include/Obj06076.h"
#include "../../matched/include/Obj01507.h"

struct Actor;
struct VecFx32;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct { int x, y, z; } V3;

typedef struct {
    u32 *owner;
    u32 f4;
    u32 f8;
    u32 fC;
    u16 id;
} S;

extern int func_0216E1C4(int a0, int a1);
extern void func_021AC154(int a);
extern int func_0216DBE8(void *a0);
extern u32 func_021ABE18(u8 *p);
extern int func_021C6658(u32 a, u32 b);
extern int func_021C6844(int a, int b);
extern int func_021C66EC(u32 *a, int idx, int v);
extern void func_021C6828(int a, int b, int c);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_021AC1CC(int a, int *v);
extern void func_021AC1B8(void *a, V3 *v);
extern void func_021C67F4(u32 o, u16 id);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B57C(void *obj);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
extern int func_0202B928(int a, int b);
extern void func_0202B920(void *m, int i, int a, int b);
void func_021C4C54(int a, int *b);
void func_021C4CDC(void *a, S *s);
void *func_021C4D14(int a, int b, int c, int d, int e);
extern int d_021DE48C;



void func_021C4C54(int a, int *b)
{
    int v[3];
    int h;
    int r;

    if (func_0216E1C4(b[1], (int)(b + 2)) == 0) {
        func_021AC154(a);
        return;
    }
    if (func_0216DBE8((void *)b[1]) == 0) {
        func_021AC154(a);
        return;
    }
    h = ((struct Obj06076 *)b)->f10;
    r = func_021ABE18((u8 *)(*(int *)b[0]));
    func_021C6658(r, h);
    if (func_021C6844(r, h) == 0) {
        func_021C66EC((u32 *)r, h, 0x1000);
        func_021C6828(r, h, 1);
    }
    func_0216D88C((const struct Actor *)b[1], (struct VecFx32 *)v);
    v[2] += 0x8000;
    func_021AC1CC(a, v);
}



/*
 * Copies the owner's current position into map-object slot id.
 */
void func_021C4CDC(void *a, S *s)
{
    u16 id = s->id;
    u32 o = func_021ABE18((u8 *)(*s->owner));
    V3 *dst = (V3 *)func_021C6658(o, id);
    V3 t;

    func_021AC1B8(a, &t);
    *dst = t;
    func_021C67F4(o, id);
}


void *func_021C4D14(int a, int b, int c, int d, int e)
{
    int n = func_02188C84((u8 *)a);
    int r;
    int *p;

    r = func_0202B57C((void *)func_02012134((u32 *)func_02188C80((void *)a)));
    p = (int *)func_02030734(n, 0x18, 0, (const char *)&d_021DE48C, 0x3c);
    ((struct Obj01507 *)p)->f0 = n;
    p[1] = a;
    p[2] = r;
    p[3] = c;
    p[4] = 0;
    p[5] = b;
    if (func_0202B928(r, c) == 0) {
        func_0202B920((void *)r, c, d, e);
    }
    return p;
}
