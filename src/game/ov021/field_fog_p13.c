/*
 * file:     field_fog_p13.c
 * unit:     yes
 * function: func_021A03D0, func_021A0448, func_021A0458, func_021A0568, func_021A0590, func_021A05D8, func_021A0618, func_021A063C
 * address:  0x021A03D0
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
 *   func_02030734  0x02030734  arm
 *   func_021A0734  0x021A0734  thumb  ov021
 *   func_021A07B4  0x021A07B4  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   d_021DDE38  0x021DDE38  data  ov021
 *   func_021A07B0  0x021A07B0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021A07F8  0x021A07F8  thumb  ov021
 *   func_021A0974  0x021A0974  thumb  ov021
 *   func_021A0B14  0x021A0B14  thumb  ov021
 *   func_021A0B34  0x021A0B34  thumb  ov021
 *   func_021A0B4C  0x021A0B4C  thumb  ov021
 *   func_021A0C74  0x021A0C74  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021A066C  0x021A066C  thumb  ov021
 *   func_021A0748  0x021A0748  thumb  ov021
 *   func_021A0980  0x021A0980  thumb  ov021
 *   func_021A0C50  0x021A0C50  thumb  ov021
 *   func_021A0C60  0x021A0C60  thumb  ov021
 */
#include "../../matched/include/Obj04229.h"
#include "../../matched/include/Obj01497.h"
#include "../../matched/include/Obj07487.h"
#include "../../matched/include/Obj12698.h"
#include "../../matched/include/Obj09537.h"
#include "../../matched/include/Obj19694.h"
#include "../../matched/include/Obj19695.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern void func_021A0734(u8 *a, u32 b);
extern u32 func_021A07B4(u8 *p, int t);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_021A07B0(void);
extern u32 func_020307B0(void *p);
extern s32 func_021A07F8(u16 a, void *b);
extern void func_021A0974(u32 a1, u32 a2, u32 a3);
extern void func_021A0B14(void *a);
extern int func_021A0B34(u32 a);
extern void func_021A0B4C(const u8 *a, u8 *b);
extern s32 func_021A0C74(u16 *a, void *b, void *c, void *d);
extern void func_021A066C(u8 *p, u32 a, u32 b);
extern void func_021A0748(u8 *a, u32 b, u32 c);
extern void func_021A0980(u8 *a, u8 *b, u8 *c, u32 d);
extern int func_021A0C50(u32 a, u16 b, u32 c, u32 d);
extern void func_021A0C60(u16 *p, u16 a, u16 b);
u8 *func_021A03D0(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021A0448(u8 *p);
void func_021A0458(u8 *a, s32 b);
void func_021A0568(u8 *p, int force);
void func_021A0590(u8 *a, u32 b, u32 c, u32 d);
void func_021A05D8(u8 *a);
void func_021A0618(u8 *p, u32 a, u32 b, u32 c);
void func_021A063C(u8 *p, u16 a, u32 b);
extern u8 d_021DDE38[];


/*
 * Addresses are Black-image addresses.
 */
u8 *func_021A03D0(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    u8 *p;

    p = func_02030734(f, 0x490, 1, (const char *)d_021DDE38, 0x167);
    ((struct Obj04229 *)p)->f2 = c;
    func_021A0734(p, a);
    ((struct Obj04229 *)p)->f38A = 1;
    ((struct Obj04229 *)p)->f350 = func_021A07B4(p, b);
    func_02082D44(p + 0x10 + ((struct Obj04229 *)p)->f350 * 0x34, p + 0x356, 0x34);
    ((struct Obj04229 *)p)->f38C = 1;
    ((struct Obj04229 *)p)->f8 = d;
    ((struct Obj04229 *)p)->f4 = e;
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0448(u8 *p)
{
    func_021A07B0();
    func_020307B0(p);
}


void func_021A0458(u8 *a, s32 b)
{
    s32 prev;
    s32 cur;
    s32 t;
    s32 wrapped;
    s32 i;
    u32 m;

    if (((struct Obj01497 *)a)->fC == 0)
        return;
    switch (((struct Obj01497 *)a)->f0) {
    case 0:
        cur = func_021A07F8(((struct Obj01497 *)a)->f2, a + 0x10 + ((struct Obj01497 *)a)->f350 * 0x34);
        wrapped = 0;
        i = ((struct Obj01497 *)a)->f350 - 1;
        if (i < 0) {
            prev = 0;
            t = func_021A07F8(((struct Obj01497 *)a)->f2, a + 0x10 + (*(s32 *)&((struct Obj01497 *)a)->fC - 1) * 0x34);
            if (t <= b) {
                prev = t;
                wrapped = 1;
                cur += 86400;
            }
        } else {
            prev = func_021A07F8(((struct Obj01497 *)a)->f2, a + 0x10 + i * 0x34);
        }
        if ((prev > b || cur <= b) && wrapped == 0) {
            m = (*(u32 *)&((struct Obj01497 *)a)->f350 + 1) % ((struct Obj01497 *)a)->fC;
            *(u32 *)&((struct Obj01497 *)a)->f350 = m;
            func_021A0974((u32)(a + 0x390), (u32)(a + 0x356), (u32)(a + 0x10 + m * 0x34));
        }
        break;
    case 1:
        if (func_021A0C74((u16 *)(a + 0x484), a + 0x390, a + 0x356, a + 0x10 + ((struct Obj01497 *)a)->f350 * 0x34))
            ((struct Obj01497 *)a)->f0 = 0;
        break;
    }
    if (func_021A0B34((u32)(a + 0x390))) {
        func_021A0B14(a + 0x390);
        func_021A0B4C(a + 0x390, a + 0x356);
        ((struct Obj01497 *)a)->f38C = 1;
    }
    ((struct Obj01497 *)a)->f48C = b;
}


void func_021A0568(u8 *p, int force)
{
    if (((struct Obj07487 *)p)->f38C != 0 || force != 0) {
        func_021A066C(p, ((struct Obj07487 *)p)->f8, ((struct Obj07487 *)p)->f4);
        ((struct Obj07487 *)p)->f38C = 0;
    }
}


void func_021A0590(u8 *a, u32 b, u32 c, u32 d)
{
    u32 r;

    func_021A07B0();
    func_021A0748(a, b, c);
    r = func_021A07B4(a, ((struct Obj12698 *)a)->f48C);
    ((struct Obj12698 *)a)->f350 = r;
    func_021A0980(a + 0x390, a + 0x356, a + 0x10 + r * 0x34, d);
}


void func_021A05D8(u8 *a)
{
    u32 r;

    func_021A07B0();
    func_021A0734(a, ((struct Obj09537 *)a)->f354);
    r = func_021A07B4(a, ((struct Obj09537 *)a)->f48C);
    ((struct Obj09537 *)a)->f350 = r;
    func_021A0974((u32)(a + 0x390), (u32)(a + 0x356), (u32)(a + 0x10 + r * 0x34));
}


void func_021A0618(u8 *p, u32 a, u32 b, u32 c)
{
    func_021A0C50((u32)(p + 0x484), b, (u16)c, a);
    ((struct Obj19694 *)p)->f0 = 1;
}


void func_021A063C(u8 *p, u16 a, u32 b)
{
    func_021A0C60((u16 *)(p + 0x484), b, a);
    ((struct Obj19695 *)p)->f0 = 1;
}
