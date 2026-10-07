/*
 * file:     field_msgbg_p34.c
 * unit:     yes
 * function: func_0218E0E4, func_0218E104, func_0218E124, func_0218E138, func_0218E13C, func_0218E160, func_0218E17C
 * address:  0x0218E0E4
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
 *   func_0218EFD4  0x0218EFD4  thumb
 *   func_0218E58C  0x0218E58C  thumb
 *   d_021DDA0C  0x021DDA0C  data  ov021  a4
 *   d_021DDA00  0x021DDA00  data  ov021  a4
 *   func_0218E18C  0x0218E18C  thumb  ov021
 */
#include "../../matched/include/Obj04202.h"
#include "../../matched/include/Obj01653.h"
#include "../../matched/include/Obj19556.h"
#include "../../matched/include/Obj17905.h"
#include "../../matched/include/Obj19557.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef void (*StateFunc)(void *a);

extern void func_02049238(u32 a);
extern void func_0218EFD4(u8 *a);
extern u32 func_020307B0(void *p);
extern void func_0218E58C(u8 *a, u32 b);
extern u32 func_0218E18C(u32, u32);
void func_0218E0E4(u8 *a);
void func_0218E104(u8 *a, u32 b);
void func_0218E124(u8 *a, u32 s);
u32 func_0218E138(u8 *p);
void func_0218E13C(u8 *a, u32 s);
int func_0218E160(u32 a);
void func_0218E17C(u32 *p, u32 v);
extern StateFunc d_021DDA0C[];
extern StateFunc d_021DDA00[];


void func_0218E0E4(u8 *a)
{
    func_02049238(((struct Obj04202 *)a)->f4);
    func_02049238(((struct Obj04202 *)a)->f8);
    func_0218EFD4(a);
    func_020307B0(a);
}


void func_0218E104(u8 *a, u32 b)
{
    void (*fp)(void *, u32) = *(void (**)(void *, u32))(a + 0x1ac);
    if (fp != 0)
        fp(a, ((struct Obj01653 *)a)->f1A8);
    func_0218E58C(a, b);
}


void func_0218E124(u8 *a, u32 s)
{
    ((struct Obj19556 *)a)->f14 = s;
    d_021DDA0C[s](a);
}


/*
 * Loads the 32-bit word at byte +0x14 of the object.
 */
u32 func_0218E138(u8 *p)
{
    return ((struct Obj17905 *)p)->f14;
}


void func_0218E13C(u8 *a, u32 s)
{
    if (((struct Obj19557 *)a)->f14 != s) {
        d_021DDA00[s](a);
        func_0218E124(a, s);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218E160(u32 a)
{
func_0218E124((u8 *)a, 0);
func_0218E18C(a, ((struct Obj01653 *)((u8 *)(a)))->f18);
*(u8 *)((u8 *)((a + 233))) = 1;
return 1;
}


/*
 * Stores the word at +0x10, then tail calls with both arguments.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E17C(u32 *p, u32 v)
{
    p[4] = v;
    func_0218E160((u32)p);
}
