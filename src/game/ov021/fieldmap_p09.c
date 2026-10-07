/*
 * file:     fieldmap_p09.c
 * unit:     yes
 * function: func_02188DB0, func_02188DF0, func_02188E30, func_02188E38
 * address:  0x02188DB0
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
 *   func_02051E74  0x02051E74  arm
 *   func_0207D59C  0x0207D59C  arm
 *   func_0204044C  0x0204044C  arm
 *   func_02190270  0x02190270  thumb
 *   func_0219027C  0x0219027C  thumb
 *   func_0204363C  0x0204363C  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_02046788  0x02046788  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */
#include "../../matched/include/Obj19493.h"
#include "../../matched/include/Obj19494.h"
#include "../../matched/include/Obj17885.h"

struct Mtx22;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(u32 a, void *buf, u32 b, u32 c, u32 d, u32 e);
extern void func_0204044C(u32 a);
extern void func_02190270(u32 a);
extern void func_0219027C(u8 *a);
extern u32 func_0203F9B4(u32);
extern u32 func_0204363C(u32, u32, u32, u32);
extern u32 func_02046788(u32);
extern u32 func_0206DB80(u32);
void func_02188DB0(u8 *a);
void func_02188DF0(u8 *a);
u32 func_02188E30(u8 *p);
int func_02188E38(u32 a, u32 b, u32 c, u32 d);


/*
 * Addresses are Black-image addresses.
 */
void func_02188DB0(u8 *a)
{
    u32 buf[4];

    func_02051E74((struct Mtx22 *)buf, 0, (const void *)0x1000, (const void *)0x1000, 0);
    func_0207D59C(0x04000020, buf, 0, 0, 0, 0);
    func_0204044C(3);
    func_02190270(((struct Obj19493 *)a)->f28);
}


void func_02188DF0(u8 *a)
{
    u32 buf[4];

    func_02051E74((struct Mtx22 *)buf, 0, (const void *)0x1000, (const void *)0x1000, 0);
    func_0207D59C(0x04000020, buf, 0, 0, 0, 0);
    func_0204044C(3);
    func_0219027C((u8 *)(((struct Obj19494 *)a)->f28));
}


/*
 * Loads the 32-bit word at byte +0x14c of the object.
 */
u32 func_02188E30(u8 *p)
{
    return ((struct Obj17885 *)p)->f14C;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02188E38(u32 a, u32 b, u32 c, u32 d)
{
return func_0203F9B4(func_02046788(func_0206DB80(func_0204363C(1, b, c, d))));
}
