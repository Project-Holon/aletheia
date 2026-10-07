/*
 * file:     field_nogrid_mapper_p14.c
 * unit:     yes
 * function: func_021BB1C4, func_021BB1D0, func_021BB1DC, func_021BB1E8, func_021BB1F4, func_021BB240, func_021BB260, func_021BB278, func_021BB2F8, func_021BB348, func_021BB36C, func_021BB388, func_021BB394
 * address:  0x021BB1C4
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
 *   func_021B7884  0x021B7884  thumb  ov021
 *   func_0219EF44  0x0219EF44  thumb  ov021
 *   func_021BB088  0x021BB088  thumb  ov021
 *   d_021DE2D0     0x021DE2D0  data  a4
 *   func_021BB0A4  0x021BB0A4  thumb  ov021
 *   func_021B791C  0x021B791C  thumb  ov021
 *   func_0219EF6C  0x0219EF6C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021AB75C  0x021AB75C  thumb  ov021
 *   func_02049030  0x02049030  arm
 *   func_0219EF7C  0x0219EF7C  thumb  ov021
 *   func_0219F018  0x0219F018  thumb  ov021
 *   func_021B7934  0x021B7934  thumb  ov021
 *   func_021BB0B4  0x021BB0B4  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 *   func_020490A8  0x020490A8  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021B7954  0x021B7954  thumb  ov021
 *   func_0219EFFC  0x0219EFFC  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021BB11C  0x021BB11C  thumb  ov021
 *   func_021B79E4  0x021B79E4  thumb  ov021
 *   func_021B79F0  0x021B79F0  thumb  ov021
 *   func_021B7970  0x021B7970  thumb
 */
#include "../../matched/include/Obj09191.h"
#include "../../matched/include/Obj01663.h"
#include "../../matched/include/Obj18166.h"

struct Obj;
struct S;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[0xC];
    void *fC;
    int pad10;
    int f14;
} Obj_021BB260;

typedef struct {
    void *f0;
    char pad[0x10];
    int f14;
} Obj_021BB36C;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern struct Obj *func_021B7884(u16 heap, u32 n, int a2);
extern u8 *func_0219EF44(u32 heap);
extern void *func_021BB088(int a);
extern u32 func_020307B0(void *p);
extern void func_0219EF6C(u8 *p);
extern void func_021B791C(void **o);
extern void func_021BB0A4(u8 *p, u32 a1, u32 a2, u32 a3);
extern void func_021AB75C(u8 *p, u32 v);
extern u32 func_02049030(u32 a);
extern void func_0219EF7C(struct S *p, u32 b, u32 c);
extern u8 *func_0219F018(u8 *p);
extern int func_021B7934(u32 a, u32 b);
extern void func_021BB0B4(u32 *a, u32 b, u32 c);
extern void func_021AB840(u32, int, u32, u16);
extern u32 func_021AB880(u8 *p);
extern u32 func_021AB884(u8 *p);
extern u32 func_021AB888(u32);
extern void func_021AB634(u32, u32, u32, u32);
extern u32 func_020490A8(u32 a, u32 b);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern int func_0219EFFC(u32 a);
extern u32 func_021AB650(u32);
extern u32 func_021AB868(u32);
extern u32 func_021B7954(u32);
extern u32 func_021BB11C(u32);
extern void func_021B79E4(unsigned short *p);
extern int func_021B79F0(struct Obj_021BB36C *o, int flag);
extern void func_021B7970();
int func_021BB1C4(int x);
int func_021BB1D0(int x);
int func_021BB1DC(int x);
int func_021BB1E8(int x);
u32 *func_021BB1F4(u32 a, u32 b, u32 c, u32 d);
int func_021BB240(void *a, u32 b, u32 c, u32 d);
void func_021BB260(Obj_021BB260 *p, int b);
void func_021BB278(u32 *a, u16 *b, u32 c);
void func_021BB2F8(u32 a, u32 b, u32 c);
int func_021BB348(u32 a);
void func_021BB36C(Obj_021BB36C *p);
int func_021BB388(void **h);
void func_021BB394(u8 *p);
extern int d_021DE2D0;


int func_021BB1C4(int x)
{
    if (x == 167)
        return 1;
    return 0;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int func_021BB1D0(int x)
{
    if (x == 166)
        return 1;
    return 0;
}


int func_021BB1DC(int x)
{
    if (x == 168)
        return 1;
    return 0;
}


int func_021BB1E8(int x)
{
    if (x == 176)
        return 1;
    return 0;
}


u32 *func_021BB1F4(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = (u32 *)func_02030734((u16)a, 0x18, 1, (const char *)&d_021DE2D0, 0x47);

    p[0] = (u32)func_021B7884(a, 0x30, b);
    p[1] = (u32)func_0219EF44(a);
    p[3] = c;
    p[4] = d;
    p[2] = (u32)func_021BB088(a);
    return p;
}


int func_021BB240(void *a, u32 b, u32 c, u32 d)
{
func_021BB0A4((u8 *)(((struct Obj09191 *)((u8 *)(a)))->f8), b, c, d);
func_021B791C((void **)(((struct Obj09191 *)((u8 *)(a)))->f0));
func_0219EF6C((u8 *)(((struct Obj09191 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}


void func_021BB260(Obj_021BB260 *p, int b)
{
    if (b != 0) {
        p->f14 = 0;
    } else {
        p->f14 = 1;
    }
    func_021AB75C(p->fC, b);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BB278(u32 *a, u16 *b, u32 c)
{
    func_021BB348((u32)a);
    if (b[0] != 0xFFFF) {
        u32 n = func_02049030(0x4f);

        func_0219EF7C((struct S *)a[1], b[0], c);
        func_021B7934(a[0], (u32)func_0219F018((u8 *)a[1]));
        func_021BB0B4((u32 *)a[2], b[0] + (n >> 1), c);
    }
    if (b[1] != 0xFFFF) {
        u32 t, u, v;

        func_021AB840(a[4], 0, b[1], c);
        t = func_021AB880((u8 *)a[4]);
        u = func_021AB884((u8 *)a[4]);
        v = func_021AB888(a[4]);
        func_021AB634(a[3], t, u, v);
    }
}


void func_021BB2F8(u32 a, u32 b, u32 c)
{
    int n = func_020490A8(0x6d, b);
    void *p = func_02030734((u16)(((u16)c & 0x7FFF) | 0x8000), n, 1, (const char *)&d_021DE2D0, 0xdd);

    func_02048F4C(p, 0x6d, b);
    func_021BB278((u32 *)a, p, c);
    func_020307B0(p);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BB348(u32 a)
{
func_021AB650(((struct Obj01663 *)((u8 *)(a)))->fC);
func_021B7954(((struct Obj01663 *)((u8 *)(a)))->f0);
func_0219EFFC(((struct Obj01663 *)((u8 *)(a)))->f4);
func_021AB868(((struct Obj01663 *)((u8 *)(a)))->f10);
return func_021BB11C(((struct Obj01663 *)((u8 *)(a)))->f8);
}


void func_021BB36C(Obj_021BB36C *p)
{
    func_021B79E4(p->f0);
    if (p->f14 == 0) {
        func_021B79F0(p->f0, 0);
    }
}

int func_021BB388(void **h) { return func_021B79F0(*h, 1); }


/*
 * Tail-call thunk: the object's word at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB394(u8 *p)
{
    func_021B7970(((struct Obj18166 *)p)->f0);
}
