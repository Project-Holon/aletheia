/*
 * file:     queue_p02.c
 * unit:     yes
 * function: func_021C09AC, func_021C09B0, func_021C09B4, func_021C09B8, func_021C09BC, func_021C09C4, func_021C09C8, func_021C09CC, func_021C09D0, func_021C09D8, func_021C09E0
 * address:  0x021C09AC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0D7C  0x021C0D7C  thumb  ov217
 *   func_021C0D38  0x021C0D38  thumb  ov217
 *   func_021C0D5C  0x021C0D5C  thumb  ov217
 */
#include "../../matched/include/Obj25976.h"
#include "../../matched/include/Obj25978.h"
#include "../../matched/include/Obj10963.h"
#include "../../matched/include/Obj25979.h"
#include "../../matched/include/Obj25980.h"
#include "../../matched/include/Obj25981.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_021C0D7C(u32 *p);
extern void func_021C0D38(u8 *p, u32 i);
extern void func_021C0D5C(u8 *p, u32 i);
u32 func_021C09AC(void *p);
u32 func_021C09B0(u32 *p);
u32 func_021C09B4(void *p);
void *func_021C09B8(void *p);
void func_021C09BC(void *p, u32 v);
void func_021C09C4(u8 *p, u32 v);
u32 func_021C09C8(void *p);
u32 func_021C09CC(void *p);
void func_021C09D0(u32 a0);
void func_021C09D8(u8 *p, u32 i);
void func_021C09E0(u32 a0);


/*
 * Field getter, u16 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09AC(void *p)
{
    return ((struct Obj25976 *)p)->f0;
}

u32 func_021C09B0(u32 *p)
{
    return p[1];
}


/*
 * Field getter, u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09B4(void *p)
{
    return ((struct Obj25978 *)p)->f8;
}


/*
 * Base pointer getter, +0xc.
 *
 * Addresses are Black-image addresses.
 */
void *func_021C09B8(void *p)
{
    return (char *)p + 0xc;
}


/*
 * Shift the two u32 fields at +0x30/+0x34 and store the new value at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09BC(void *p, u32 v)
{
    ((struct Obj10963 *)p)->f30 = ((struct Obj10963 *)p)->f34;
    ((struct Obj10963 *)p)->f34 = v;
}

/*
 * Field setter: store the word at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09C4(u8 *p, u32 v)
{
    ((struct Obj25979 *)p)->f38 = v;
}


/*
 * Field getter, u32 at +0x30.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09C8(void *p)
{
    return ((struct Obj25980 *)p)->f30;
}


/*
 * Field getter, u32 at +0x38.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09CC(void *p)
{
    return ((struct Obj25981 *)p)->f38;
}


/*
 * Tail-call veneer: forwards its first argument to func_021C0D7C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09D0(u32 a0)
{
    func_021C0D7C((u32 *)a0);
}


/*
 * Unlabelled 4-byte tail-call veneer in a .word run; pool 0x021C09DC names
 * func_021C0D38.  Top of the func_021BA31C blocker chain.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09D8(u8 *p, u32 i)
{
    func_021C0D38(p, i);
}


void func_021C09E0(u32 a0)
{
    func_021C0D5C((u8 *)a0, 0);
}
