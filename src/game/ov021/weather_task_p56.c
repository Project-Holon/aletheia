/*
 * file:     weather_task_p56.c
 * unit:     yes
 * function: func_021A4ED8, func_021A4F04, func_021A4F0C, func_021A4F50, func_021A4F58, func_021A4FA8, func_021A5010, func_021A5014, func_021A5044, func_021A50BC, func_021A50E0, func_021A511C, func_021A5148, func_021A51A4, func_021A51A8, func_021A51D8, func_021A5204, func_021A5228, func_021A5264, func_021A5304, func_021A530C, func_021A5318, func_021A5328, func_021A5334, func_021A5340, func_021A5354, func_021A5360, func_021A536C
 * address:  0x021A4ED8
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
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021A5630  0x021A5630  thumb  ov021
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DCE8  0x0216DCE8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_021A5788  0x021A5788  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB41C  0x021AB41C  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_021A57C0  0x021A57C0  thumb  ov021
 *   func_021A5810  0x021A5810  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02163994  0x02163994  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB2DC  0x021AB2DC  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E5B0  0x0216E5B0  thumb  ov010
 */
#include "../../matched/include/Obj19792.h"
#include "../../matched/include/Obj19794.h"
#include "../../matched/include/Obj19795.h"
#include "../../matched/include/Obj00262.h"
#include "../../matched/include/Obj19797.h"
#include "../../matched/include/Obj06012.h"
#include "../../matched/include/Obj19798.h"
#include "../../matched/include/Obj19799.h"
#include "../../matched/include/Obj19800.h"
#include "../../matched/include/Obj07499.h"
#include "../../matched/include/Obj19801.h"
#include "../../matched/include/Obj07218.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A4F58;

typedef struct { int x, y, z; } VecFx32;

typedef signed short   s16;

typedef signed char    s8;

u16 func_0216D5F8(void *p);
int func_02197E7C(int k, int a);
void func_0216D410(int b, int v);
void func_021A3964(u8 *p, u32 v);
void func_020061E4(u32 a);
extern u32 func_021A5630(u32);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DCE8(void *a0, int a1);
extern void *func_0216D568(void *p, u32 v);
void *func_021A3960(unsigned char *p);
void func_0216D88C(const struct Actor *h, struct VecFx32 *v);
void func_02163E58(void *h, Vec021A4F58 *v, int *lim);
char *func_0216D570(char *p, u32 v);
void func_0216D89C(void *h, Vec021A4F58 *v);
extern int func_021A5788(u32, u32, u32 *);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB41C(u16 id);
extern u32 func_02188CD0(u8 *p);
extern void func_021AC528(u32, u32);
extern int func_021A57C0(u8 *p, int dir);
int func_021A5810(u8 *p, int dir);
extern int func_0216D83C(void *);
extern int func_0216D854(void *);
extern int func_0216D86C(void *);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern int func_02163994(void *, int, int, int, u32);
extern void func_02164208(int dir, int *p, int amt);
extern int func_02163E34(void *, VecFx32 *, int *);
extern int func_021AB2DC(u16 id);
extern void *func_0216D67C(void *);
extern int func_0216E5B0(void *map, const struct VecFx32 *pos);
void func_021A4ED8(u32 *p, int b, u8 *c);
void func_021A4F04(u32 *a, void *a1, u32 a2);
void func_021A4F0C(u32 a, void *b, u32 c);
void func_021A4F50(u32 *a, void *a1, u32 a2);
int func_021A4F58(u32 *p, void *a1, u32 a2);
void func_021A4FA8(u32 a, u32 b, u32 c);
void func_021A5010(u32 a, u32 b, u32 c);
void func_021A5014(u32 *p, int b, u8 *c);
void func_021A5044(u32 *a, u32 b, u32 *c);
void func_021A50BC(u32 *p, int b, u8 *c);
void func_021A50E0(u32 *p, int b, u8 *c);
void func_021A511C(u32 *p, int b, u8 *c);
void func_021A5148(u32 a, u32 b, u32 c);
void func_021A51A4(u32 a, u32 b, u32 c);
void func_021A51A8(u32 *p, int b, u8 *c);
void func_021A51D8(u32 *p, int b, u8 *c);
void func_021A5204(u32 *p, int b, u8 *c);
void func_021A5228(u32 *p, int b, u8 *c);
int func_021A5264(u8 *a, void *b, u32 c, int *d);
int func_021A5304(u32 a, u32 b);
int func_021A530C(u32 a, u32 b);
int func_021A5318(u32 *p, u32 m);
void func_021A5328(u32 a);
void func_021A5334(u32 a);
int func_021A5340(u32 *p);
void func_021A5354(u32 a);
void func_021A5360(u32 a);
void func_021A536C(u32 a);


void func_021A4ED8(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19792 *)c)->f8, 0x38));
    p[0] = 1;
    func_021A3964((u8 *)p[3], 1);
    func_020061E4(0x55E);
}


/*
 * Unlabelled leaf (no lr save), filed because it blocks the caller's MATCH.
 *
 * Addresses are Black-image addresses.
 */
void func_021A4F04(u32 *a, void *a1, u32 a2)
{
    *a = 4;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A4F0C(u32 a, void *b, u32 c)
{
    u32 x = ((struct Obj19795 *)c)->f8;
    if (x == 9) {
        x = func_021A5630(a);
    }
    func_0216D410((u32)b, func_02197E7C(x, 0x34));
    func_0216DB4C(b, 1);
    func_0216DCE8((void *)b, 1);
    func_0216D568((void *)b, 0x8000);
    ((struct Obj19794 *)a)->f0 = 5;
}


void func_021A4F50(u32 *a, void *a1, u32 a2)
{
    *a = 6;
}


/*
 * The function returns int: v.y when the height is already at or under the
 * limit, 7 (the new state) otherwise. The only caller (func_021A4CF4, case 9)
 * discards the value. Returning v.y on the early path ties the cross-block
 * v.y value to r0 (the return register), so the block-2 constant 0x8000 goes
 * to r1 and the subtract reads `subs r0, r0, r1`; the void form colours the
 * constant first into r0 and gives `subs r0, r1, r0` (three earlier rounds,
 * dozens of spellings). Leaving the final `return 7` out recolours the 7 to r1.
 * See docs/idioms/a-value-returned-on-the-early-path-precolours-its-register-to-r0.md.
 */
int func_021A4F58(u32 *p, void *a1, u32 a2)
{
    void *h = func_021A3960(*(unsigned char * *)&((struct Obj00262 *)p)->fC);
    Vec021A4F58 v;
    int lim;

    func_0216D88C(h, (struct VecFx32 *)&v);
    func_02163E58(h, &v, &lim);
    if (v.y > lim) {
        v.y -= 0x8000;
        if (v.y < lim) {
            v.y = lim;
            func_0216D570(h, 0x8000);
            p[7] = 1;
        }
        func_0216D89C(h, &v);
        p[0] = 7;
        return 7;
    }
    return v.y;
}


void func_021A4FA8(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: func_021A5010(a, (u32)x, c); return;
    case 1: func_021A5014((u32 *)a, (int)x, (u8 *)c); return;
    case 2: func_021A5044((u32 *)a, (u32)x, (u32 *)c); return;
    case 3: func_021A50BC((u32 *)a, (int)x, (u8 *)c); return;
    case 4: func_021A50E0((u32 *)a, (int)x, (u8 *)c); return;
    case 5: func_021A511C((u32 *)a, (int)x, (u8 *)c); break;
    }
}


void func_021A5010(u32 a, u32 b, u32 c)
{
}


void func_021A5014(u32 *p, int b, u8 *c)
{
    int k = ((struct Obj19797 *)c)->f8;

    if (k == 9)
        k = func_0216D5F8((void *)b);
    func_0216D410(b, func_02197E7C(k, 0));
    p[0] = 0;
    func_021A3964((u8 *)p[3], 0);
}


void func_021A5044(u32 *a, u32 b, u32 *c)
{
    u32 v;
    u32 r;
    int f = 1;
    if (c[4] == 1) {
        r = 0x14;
        f = 0;
    } else {
        r = 0x14;
        if (func_021A5788((u32)a, 9, &v) == 1) {
            if (func_021AB41C(func_021AB0F0(v)) == 1) {
                r = 0x9b;
                func_021AC528(b, func_02188CD0((u8 *)a[4]));
            }
        }
    }
    if (f == 1) {
        if (func_021A57C0((u8 *)((u32)a), ((struct Obj06012 *)c)->f8) == 1) {
            if (r == 0x14) {
                r = 0x10;
            }
        }
    }
    func_0216D410(b, func_02197E7C(((struct Obj06012 *)c)->f8, r));
    a[0] = 1;
    func_021A3964((u8 *)a[3], 1);
}


void func_021A50BC(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19798 *)c)->f8, 0x24));
    p[0] = 2;
    func_021A3964((u8 *)p[3], 2);
}


void func_021A50E0(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj06012 *)c)->f8, 0x1C));
    p[0] = 3;
    func_021A3964((u8 *)p[3], 0);
    if (func_021A5810((u8 *)p, ((struct Obj06012 *)c)->f8) == 0)
        func_020061E4(0x55A);
}


void func_021A511C(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19799 *)c)->f8, 0x38));
    p[0] = 1;
    func_021A3964((u8 *)p[3], 1);
    func_020061E4(0x55E);
}


void func_021A5148(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: func_021A51A4(a, (u32)x, c); return;
    case 1: func_021A51A8((u32 *)a, (int)x, (u8 *)c); return;
    case 2: func_021A51D8((u32 *)a, (int)x, (u8 *)c); return;
    case 3: func_021A5204((u32 *)a, (int)x, (u8 *)c); return;
    case 4: func_021A5228((u32 *)a, (int)x, (u8 *)c); break;
    }
}


void func_021A51A4(u32 a, u32 b, u32 c)
{
}


void func_021A51A8(u32 *p, int b, u8 *c)
{
    int k = ((struct Obj19800 *)c)->f8;

    if (k == 9)
        k = func_0216D5F8((void *)b);
    func_0216D410(b, func_02197E7C(k, 0));
    p[0] = 0;
    func_021A3964((u8 *)p[3], 0);
}


void func_021A51D8(u32 *p, int b, u8 *c)
{
    int a = (((struct Obj07499 *)c)->f10 == 1) ? 0x14 : 0x10;

    func_0216D410(b, func_02197E7C(((struct Obj07499 *)c)->f8, a));
    p[0] = 1;
    func_021A3964((u8 *)p[3], 1);
}


void func_021A5204(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19801 *)c)->f8, 0x24));
    p[0] = 2;
    func_021A3964((u8 *)p[3], 2);
}


void func_021A5228(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj07499 *)c)->f8, 0x1C));
    p[0] = 3;
    func_021A3964((u8 *)p[3], 0);
    if (func_021A5810((u8 *)p, ((struct Obj07499 *)c)->f8) == 0)
        func_020061E4(0x55A);
}


int func_021A5264(u8 *a, void *b, u32 c, int *d)
{
    VecFx32 buf;
    int s2;
    int s1;
    int r4;
    int r3;
    r4 = func_0216D83C(b);
    s1 = func_0216D854(b);
    s2 = func_0216D86C(b);
    r4 = (short)(r4 + func_021641E8(c));
    r3 = (short)(s2 + func_021641F8(c));
    r4 = func_02163994(b, r4, s1, r3, c);
    func_0216D88C(b, (struct VecFx32 *)&buf);
    func_02164208(c, (int *)(&buf), 0x10000);
    if (func_02163E34(b, &buf, d) == 0) {
        *d = -1;
    }
    if (r4 & 2) {
        if (func_021AB2DC(func_021AB0F0(*d)) == 1) {
            if (func_0216E5B0(func_0216D67C(b), (const struct VecFx32 *)(&buf)) == 1) {
                r4 &= ~2;
            }
        }
    }
    return r4;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5304(u32 a, u32 b)
{
((struct Obj07218 *)((u8 *)(a)))->f8 = (b | ((struct Obj07218 *)((u8 *)(a)))->f8);
return a;
}


int func_021A530C(u32 a, u32 b)
{
((struct Obj07218 *)((u8 *)(a)))->f8 = ((~b) & ((struct Obj07218 *)((u8 *)(a)))->f8);
return a;
}


int func_021A5318(u32 *p, u32 m)
{
    if (p[2] & m)
        return 1;
    return 0;
}


/*
 * Tail-call thunk: pins the second argument to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5328(u32 a)
{
    func_021A5304(a, 1);
}


void func_021A5334(u32 a)
{
    func_021A530C(a, 1);
}


int func_021A5340(u32 *p)
{
    int r = 1;

    if (func_021A5318(p, 1) == 0)
        r = 0;
    return r;
}


/*
 * Tail-call thunk: pins the second argument to 2.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5354(u32 a)
{
    func_021A5304(a, 2);
}


void func_021A5360(u32 a)
{
    func_021A530C(a, 2);
}


/*
 * Tail-call thunk: pins the second argument to 4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A536C(u32 a)
{
    func_021A530C(a, 4);
}
