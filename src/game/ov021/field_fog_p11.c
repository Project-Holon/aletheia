/*
 * file:     field_fog_p11.c
 * unit:     yes
 * function: func_021A0250, func_021A0260, func_021A0280, func_021A0290, func_021A02A8, func_021A02C4, func_021A02F4, func_021A030C
 * address:  0x021A0250
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
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DDE28     0x021DDE28  data
 *   func_02049238  0x02049238  arm
 *   func_021A0358  0x021A0358  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0204A380  0x0204A380  arm
 */
#include "../../matched/include/Obj12082.h"
#include "../../matched/include/Obj07213.h"
#include "../../matched/include/Obj12697.h"
#include "../../matched/include/Obj17987.h"
#include "../../matched/include/Obj04228.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u16 f0;
    u16 f2;
    u32 f4;
    int f8;
    u32 fc;
    int f10;
} Lerp;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_020307B0(void *p);
extern void func_02049238(u32 arc);
extern u32 func_021A0358(u32);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
int func_021A0250(u32 a);
void func_021A0260(Lerp *s, u32 a, u32 b, u16 c, u16 d, u16 e);
int func_021A0280(u32 a);
u32 func_021A0290(Lerp *s);
u16 func_021A02A8(Lerp *s);
u8 *func_021A02C4(u16 heap);
int func_021A02F4(void *a);
void func_021A030C(u8 *p, u32 a);
extern char d_021DDE28[];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0250(u32 a)
{
if (((struct Obj12082 *)((u8 *)(a)))->f0 < ((struct Obj12082 *)((u8 *)(a)))->f2) {
    return 1;
}
return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A0260(Lerp *s, u32 a, u32 b, u16 c, u16 d, u16 e)
{
    s->f0 = 0;
    s->f2 = e;
    s->f4 = a;
    s->f8 = b - a;
    s->fc = c;
    s->f10 = d - c;
}


int func_021A0280(u32 a)
{
if (((struct Obj07213 *)((u8 *)(a)))->f0 < ((struct Obj07213 *)((u8 *)(a)))->f2) {
    ((struct Obj07213 *)((u8 *)(a)))->f0 = (((struct Obj07213 *)((u8 *)(a)))->f0 + 1);
}
return a;
}


u32 func_021A0290(Lerp *s)
{
    int q = s->f8 * s->f0 / s->f2;
    return q + s->f4;
}


u16 func_021A02A8(Lerp *s)
{
    int q = s->f10 * s->f0 / s->f2;
    return q + s->fc;
}


u8 *func_021A02C4(u16 heap)
{
    u8 *p = (u8 *)func_02030734(heap, 0x10, 1, d_021DDE28, 0x51);
    ((struct Obj12697 *)p)->f8 = 0x0FFFFFFF;
    ((struct Obj12697 *)p)->fC = func_020490F4(0x51, heap);
    return p;
}


int func_021A02F4(void *a)
{
func_02049238(((struct Obj17987 *)((u8 *)(a)))->fC);
func_021A0358((u32)a);
return func_020307B0(a);
}


void func_021A030C(u8 *p, u32 a)
{
    if (p[0] == 1) {
        ((s8 *)p)[1]--;
        if (((s8 *)p)[1] <= 0) {
            ((struct Obj04228 *)p)->f4 = (unsigned int)func_0204A380((void *)(((struct Obj04228 *)p)->fC), ((struct Obj04228 *)p)->f2, 0, a);
            p[0] = 0;
        }
    }
}
