/*
 * file:     field_msgbg_p49.c
 * unit:     yes
 * function: func_021900C4, func_02190110, func_0219014C, func_021901E4
 * address:  0x021900C4
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
 *   func_0218F19C  0x0218F19C  thumb  ov021
 *   func_0218F18C  0x0218F18C  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0218ED5C  0x0218ED5C  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_021901E8  0x021901E8  thumb
 *   func_0218ED34  0x0218ED34  thumb
 *   func_0218ED48  0x0218ED48  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *   func_0218EC90  0x0218EC90  thumb
 *   func_0218ECD4  0x0218ECD4  thumb
 *   func_021C7058  0x021C7058  thumb  ov021
 *   func_021C701C  0x021C701C  thumb  ov021
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7C10  0x021C7C10  thumb  ov021
 *   func_021C7AE4  0x021C7AE4  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 */
#include "../../matched/include/Obj19579.h"
#include "../../matched/include/Obj09472.h"
#include "../../matched/include/Obj19581.h"
#include "../../matched/include/Obj17919.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

typedef struct {
    u16 h0;
    u16 h2;
    u32 w4;
    Vec3 v8;
    Vec3 v14;
} Params;

extern void func_0218F19C(u32 a, void *b);
extern void func_0218F18C(u32 a, void *b);
extern void func_0207CA00(void *a, void *b, void *c);
extern int func_0218ED5C(u32 a, u32 b, u32 c, u32 d);
extern void func_0218ECC4(u32 a, void *b);
extern u32 func_021901E8(u8 *p);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218EC90(void *a, const Vec3 *p);
extern void func_0218ECD4(void *a, const Vec3 *p);
extern u32 func_021C7058(u32 a, u32 b, u32 c);
extern u32 func_021C701C(u32 a, u32 b, u32 c);
extern u32 func_021C6F00(u32 a, u16 b, u32 c);
extern u32 func_021C7C10(u32 a, u16 b, void *c, void *d);
extern u32 func_021C7AE4(u32 a, u32 b, void *c);
extern u32 func_02188D38(u8 *p);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
void func_021900C4(u32 a, u8 *b);
void func_02190110(u8 *a);
void func_0219014C(u32 *a);
u32 func_021901E4(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021900C4(u32 a, u8 *b)
{
    u8 v1[12];
    u8 v0[12];
    u8 v2[12];

    func_0218F19C(a, v0);
    func_0218F18C(a, v1);
    func_0207CA00(v0, v1, v2);
    func_0218ED5C((u32)v2, (u32)b, (u32)(b + 2), (u32)(b + 4));
    func_0218F18C(a, b + 8);
    func_0218ECC4(a, b + 0x14);
}


void func_02190110(u8 *a)
{
    void *x = ((struct Obj19579 *)a)->f4;
    Params *p = (Params *)(func_021901E8(a) + 0x24);
    func_0218ED34(x, p->h0);
    func_0218ED48(x, p->h2);
    func_0218ED58(x, p->w4);
    func_0218EC90(x, &p->v8);
    func_0218ECD4(x, &p->v14);
}


void func_0219014C(u32 *a)
{
    u32 h = *a;
    u8 *o = (u8 *)func_021901E8((u8 *)a);
    u32 k = ((struct Obj19581 *)o)->f0;
    u8 *q = o + 0x24;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v0 = func_021C7058(h, k, ((struct Obj09472 *)q)->f0);
    v1 = func_021C701C(h, k, ((struct Obj09472 *)q)->f2);
    v2 = func_021C6F00(h, k, ((struct Obj09472 *)q)->f4);
    v3 = func_021C7C10(h, k, o + 0xc, q + 8);
    v4 = func_021C7AE4(h, k, q + 0x14);
    h = func_02188D38((u8 *)h);
    func_021C6DE0((u8 *)h, (u32 *)v0, 0);
    func_021C6DE0((u8 *)h, (u32 *)v1, 0);
    func_021C6DE0((u8 *)h, (u32 *)v2, 0);
    func_021C6DE0((u8 *)h, (u32 *)v3, 0);
    func_021C6DE0((u8 *)h, (u32 *)v4, 0);
}


/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021901E4(u8 *p)
{
    return ((struct Obj17919 *)p)->f4;
}
