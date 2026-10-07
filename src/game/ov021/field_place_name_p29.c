/*
 * file:     field_place_name_p29.c
 * unit:     yes
 * function: func_021BE184, func_021BE194, func_021BE1A0, func_021BE1B0, func_021BE1C4, func_021BE1DC, func_021BE218
 * address:  0x021BE184
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
 *   func_021BE180  0x021BE180  thumb  ov021
 *   func_02162370  0x02162370  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   d_021D9D98     0x021D9D98  data  a4
 *   d_021D9CBC     0x021D9CBC  data  a4
 *   func_02034A5C  0x02034A5C  arm
 *   d_021D9BE0     0x021D9BE0  data  ov021  a4
 */
#include "../../matched/include/Obj18254.h"
#include "../../matched/include/Obj18255.h"
#include "../../matched/include/Obj18256.h"
#include "../../matched/include/Obj09202.h"
#include "../../matched/include/Obj18257.h"

struct Big;
struct Ctx;
struct Rec94;
typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    char pad[0x58];
    Vec v58;
} Obj;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern u8 *func_021BE180(u8 *p);
extern u32 func_02162370(u32);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern int func_02034AC4(int);
extern void func_02034A5C(int handle);
void func_021BE184(Obj *p, const Vec *v);
int func_021BE194(u32 a);
int func_021BE1A0(u32 a);
int func_021BE1B0(u32 a);
int func_021BE1C4(u32 a);
void func_021BE1DC(void *arg);
void func_021BE218(void *arg);
extern void *d_021D9D98[];


void func_021BE184(Obj *p, const Vec *v)
{
    p->v58 = *v;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE194(u32 a)
{
return ((struct Obj18254 *)((u8 *)(func_021BE180((u8 *)a))))->f0;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02162370 (0x02162370) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE1A0(u32 a)
{
return func_02162370(((struct Obj18255 *)((u8 *)(func_021BE180((u8 *)a))))->f0);
}


int func_021BE1B0(u32 a)
{
if (((struct Obj18256 *)((u8 *)(func_021BE180((u8 *)a))))->f8 == 0) {
    return 1;
}
return 0;
}


int func_021BE1C4(u32 a)
{
if (((struct Obj18257 *)((u8 *)(func_021BE180((u8 *)a))))->f4 == 0) {
    return ((struct Obj09202 *)((u8 *)(a)))->f68;
}
return ((struct Obj09202 *)((u8 *)(a)))->f6C;
}

extern void (*d_021D9CBC[])(void *);


void func_021BE1DC(void *arg)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(arg))));
    if (i != -1) {
        if (d_021D9D98[i] != 0) {
            func_02034AC4((int)d_021D9D98[i]);
        }
        d_021D9CBC[i](arg);
    }
}


extern void (*d_021D9BE0[])(void *);


void func_021BE218(void *arg)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(arg))));
    if (i != -1) {
        if (d_021D9BE0[i] != 0) {
            d_021D9BE0[i](arg);
        }
        if (d_021D9D98[i] != 0) {
            func_02034A5C((int)d_021D9D98[i]);
        }
    }
}
