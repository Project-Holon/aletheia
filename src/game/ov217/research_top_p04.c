/*
 * file:     research_top_p04.c
 * unit:     yes
 * function: func_021BA158, func_021BA180, func_021BA190, func_021BA194, func_021BA19C, func_021BA1C0, func_021BA1CC
 * address:  0x021BA158
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
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *   func_021C09C8  0x021C09C8  thumb  ov217
 *   func_021C09CC  0x021C09CC  thumb  ov217
 *   func_021C09C4  0x021C09C4  thumb  ov217
 */
#include "../../matched/include/Obj00511.h"
#include "../../matched/include/Obj25810.h"
#include "../../matched/include/Obj25812.h"
#include "../../matched/include/Obj25813.h"
#include "../../matched/include/Obj25814.h"

struct Ring;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern u32 func_021C0E54(struct Ring *r);
extern u32 func_021C0E64();
extern u32 func_021C09C8(void *p);
extern u32 func_021C09CC(void *p);
extern void func_021C09C4(u8 *p, u32 v);
void func_021BA158(u32 a0);
void func_021BA180(void *p, u32 v);
u32 func_021BA190(void *p);
void func_021BA194(void *p);
u32 func_021BA19C(u8 *a0);
void func_021BA1C0(u8 *a0, u32 a1);
void func_021BA1CC(void *p, u32 v);

void func_021BA158(u32 a0)
{
    if (((struct Obj00511 *)((u8*)a0))->f80 != 0) {
    if (func_021C0E64(((struct Obj00511 *)(((u8*)a0)))->f14) == 0) {
    func_021BA180((void *)a0, func_021C0E54((struct Ring *)(((struct Obj00511 *)(((u8*)a0)))->f14)));
    }
    }
}


/*
 * Set +0x18, clear +0x1c, +0x20 and +0x80.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA180(void *p, u32 v)
{
    ((struct Obj00511 *)p)->f18 = v;
    ((struct Obj00511 *)p)->f1C = 0;
    ((struct Obj00511 *)p)->f20 = 0;
    ((struct Obj00511 *)p)->f80 = 0;
}


u32 func_021BA190(void *p)
{
    return ((struct Obj25810 *)p)->f1C;
}


void func_021BA194(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x1c);
    *c += 1;
}

u32 func_021BA19C(u8 *a0)
{
    u32 v = ((struct Obj25812 *)a0)->f0;
    u32 a = func_021C09C8((void *)v);
    u32 b = func_021C09CC((void *)v);
    if (a != 0 && b == 0) {
    return 2;
    }
    return 1;
}


void func_021BA1C0(u8 *a0, u32 a1)
{
    func_021C09C4(*(u8 * *)&((struct Obj25813 *)a0)->f0, a1);
}


void func_021BA1CC(void *p, u32 v)
{
    ((struct Obj25814 *)p)->f8C = v;
}
