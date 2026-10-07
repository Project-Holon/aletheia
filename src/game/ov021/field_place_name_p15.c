/*
 * file:     field_place_name_p15.c
 * unit:     yes
 * function: func_021BD2BC, func_021BD2C0, func_021BD2C4, func_021BD2C8, func_021BD2D0, func_021BD2D8, func_021BD2DC, func_021BD2E8, func_021BD2F4, func_021BD2FC, func_021BD304, func_021BD308, func_021BD30C
 * address:  0x021BD2BC
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
 *   func_0209C494  0x0209C494  arm
 *   func_021BD2B8  0x021BD2B8  thumb  ov021
 *   func_021BD604  0x021BD604  thumb  ov021
 */
#include "../../matched/include/Obj18218.h"
#include "../../matched/include/Obj18219.h"
#include "../../matched/include/Obj18220.h"
#include "../../matched/include/Obj18221.h"
#include "../../matched/include/Obj18222.h"
#include "../../matched/include/Obj18223.h"
#include "../../matched/include/Obj18226.h"
#include "../../matched/include/Obj18227.h"
#include "../../matched/include/Obj18228.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_0209C494(u32 v);
extern u16 func_021BD2B8(u8 *p);
extern void func_021BD604(void *a, void *b, void *c, void *d, void *e);
void func_021BD2BC(u8 *p, int v);
u32 func_021BD2C0(u8 *p);
void func_021BD2C4(u8 *p, u32 v);
u16 func_021BD2C8(u8 *p);
void func_021BD2D0(u8 *p, u16 v);
u32 func_021BD2D8(u8 *p);
void func_021BD2DC(u32 *p);
void func_021BD2E8(u32 *p);
u8 func_021BD2F4(u8 *p);
u8 func_021BD2FC(u8 *p);
u8 *func_021BD304(u8 *p);
int func_021BD308(u8 *p);
void func_021BD30C(char *p);


/*
 * Field setter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2BC(u8 *p, int v)
{
    ((struct Obj18218 *)p)->f0 = v;
}


/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021BD2C0(u8 *p)
{
    return ((struct Obj18219 *)p)->f4;
}


void func_021BD2C4(u8 *p, u32 v)
{
    ((struct Obj18220 *)p)->f4 = v;
}


/*
 * Loads the halfword at byte +0x48 of the object.
 */
u16 func_021BD2C8(u8 *p)
{
    return ((struct Obj18221 *)p)->f48;
}


/*
 * Field setter at +0x48 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2D0(u8 *p, u16 v)
{
    ((struct Obj18222 *)p)->f48 = v;
}


/*
 * Loads the 32-bit word at byte +0x44 of the object.
 */
u32 func_021BD2D8(u8 *p)
{
    return ((struct Obj18223 *)p)->f44;
}


/*
 * Unlabelled tail-call thunk on the word at +0x10; callee of func_021BD1FC.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2DC(u32 *p)
{
    func_0209C494(p[4]);
}


/*
 * Unlabelled tail-call thunk on the word at +0x14; callee of func_021BD204.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2E8(u32 *p)
{
    func_0209C494(p[5]);
}


u8 func_021BD2F4(u8 *p)
{
    return ((struct Obj18226 *)p)->f40;
}


/*
 * Unlabelled leaf byte getter at +0x41.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021BD2FC(u8 *p)
{
    return ((struct Obj18227 *)p)->f41;
}


/*
 * Returns the object pointer advanced by 0x10 bytes.
 */
u8 *func_021BD304(u8 *p)
{
    return p + 0x10;
}


int func_021BD308(u8 *p)
{
    return ((struct Obj18228 *)p)->f8;
}


void func_021BD30C(char *p)
{
    void *a;
    void *b;

    a = (void *)func_021BD2C0((u8 *)p);
    b = (void *)func_021BD2C8((u8 *)p);
    func_021BD604(a, b, (void *)func_021BD2B8((u8 *)p), p + 0x40, p + 0x41);
}
