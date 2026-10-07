/*
 * file:     queue_p07.c
 * unit:     yes
 * function: func_021C0DBC, func_021C0DC4, func_021C0DDC, func_021C0DE4, func_021C0DF0, func_021C0DF4, func_021C0DF8, func_021C0DFC, func_021C0E00, func_021C0E04, func_021C0E08
 * address:  0x021C0DBC
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
 *   d_021C4050  0x021C4050  data  a4
 *   func_02030734  0x02030734  arm
 *   func_021C0E6C  0x021C0E6C  thumb  ov217
 *   func_021C0E78  0x021C0E78  thumb  ov217
 */
#include "../../matched/include/Obj10965.h"
#include "../../matched/include/Obj25997.h"
#include "../../matched/include/Obj25998.h"
#include "../../matched/include/Obj25999.h"
#include "../../matched/include/Obj26000.h"
#include "../../matched/include/Obj26001.h"
#include "../../matched/include/Obj26002.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_021C0E6C(void *p);
extern void func_021C0E78(u32 a0, u32 a1, u32 a2);
u32 func_021C0DBC(void *p, u32 i);
u32 func_021C0DC4(u32 a0);
void func_021C0DDC(void *a0);
void func_021C0DE4(void *p);
u32 func_021C0DF0(void *p);
u32 func_021C0DF4(void *p);
u32 func_021C0DF8(void *p);
void func_021C0DFC(void *p, u8 v);
void func_021C0E00(void *p, u32 v);
void func_021C0E04(void *p, u32 v);
int func_021C0E08(int a0, int a1);
extern const int d_021C4050[];


/*
 * Indexed u32 read: element i of the table at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DBC(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x20);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DC4(u32 a0)
{
    return (u32)func_02030734(a0, 12, 1, (const char *)0x21C4034, 32);
}


void func_021C0DDC(void *a0)
{
    func_020307B0(a0);
}


void func_021C0DE4(void *p)
{
    ((struct Obj10965 *)p)->f0 = 0;
    ((struct Obj10965 *)p)->f4 = 0;
    ((struct Obj10965 *)p)->f8 = -0x18;
}


/*
 * Field getter, u8 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DF0(void *p)
{
    return ((struct Obj25997 *)p)->f0;
}


/*
 * Field getter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DF4(void *p)
{
    return ((struct Obj25998 *)p)->f4;
}


/*
 * Field getter, u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DF8(void *p)
{
    return ((struct Obj25999 *)p)->f8;
}


/*
 * Field setter, u8 at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0DFC(void *p, u8 v)
{
    ((struct Obj26000 *)p)->f0 = v;
}


/*
 * Field setter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E00(void *p, u32 v)
{
    ((struct Obj26001 *)p)->f4 = v;
}


/*
 * Field setter, u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E04(void *p, u32 v)
{
    ((struct Obj26002 *)p)->f8 = v;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021C0E08(int a0, int a1)
{
    int h;
    h = (int)func_02030734(a1, 0x10, 0, (const char *)d_021C4050, 0x3C);
    func_021C0E6C((void *)h);
    func_021C0E78(h, a0, a1);
    return h;
}
