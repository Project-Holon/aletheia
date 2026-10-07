/*
 * file:     field_flash_p11.c
 * unit:     yes
 * function: func_021C7E90, func_021C7EEC, func_021C7EF0, func_021C7EF4, func_021C7EF8, func_021C7EFC, func_021C7F18, func_021C7F44, func_021C7F70, func_021C7F9C, func_021C7FAC
 * address:  0x021C7E90
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
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021C7E70  0x021C7E70  thumb  ov021
 *   d_021DE50C  0x021DE50C  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_021C7FC0  0x021C7FC0  thumb  ov021
 *   func_021C7FF0  0x021C7FF0  thumb  ov021
 *   func_021C8000  0x021C8000  thumb  ov021
 */
#include "../../matched/include/Obj18326.h"
#include "../../matched/include/Obj18327.h"
#include "../../matched/include/Obj18328.h"
#include "../../matched/include/Obj18329.h"
#include "../../matched/include/Obj18330.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021C7E90;

typedef struct {
    int f0;
    u8 f4;
    u8 pad5;
    u16 f6;
    u16 f8;
    u8 padA[2];
    int fC;
    int f10;
    s16_021C7E90 f14;
    s16_021C7E90 f16;
} Obj;

typedef unsigned int   u32;

typedef signed short   s16_021C7EFC;

typedef signed char    s8;

typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;

typedef signed int     s32;

extern u32 func_0207C768(u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern int func_021C7E70(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1);
extern void func_020061E4(u32 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021C7FC0(M **pp, u32 flags, u32 heap);
extern void func_021C7FF0(void *p);
extern void func_021C8000(u8 *p);
int func_021C7E90(Obj *p);
u32 func_021C7EEC(u8 *p);
void func_021C7EF0(u8 *p, u32 v);
u8 func_021C7EF4(u8 *p);
u8 *func_021C7EF8(u8 *p, u8 v);
int func_021C7EFC(u32 a, u32 b, u32 c, u32 d);
void func_021C7F18(M *m);
void func_021C7F44(M *m);
void func_021C7F5C(M *m);
M **func_021C7F70(u32 flags, u32 heap);
void func_021C7F9C(u8 *p);
void func_021C7FAC(u32 a);
extern char d_021DE50C[];


/*
 * Addresses are Black-image addresses.
 */
int func_021C7E90(Obj *p)
{
    if (p->f6 < p->f8) {
        p->f6 = p->f6 + 1;
        p->f0 = p->fC + func_0207C768((int)(((long long)p->f10 * (p->f6 << 12) + 0x800) >> 12), p->f8 << 12);
        p->f4 = p->f14 + p->f16 * p->f6 / p->f8;
        return 0;
    }
    return 1;
}


u32 func_021C7EEC(u8 *p)
{
    return ((struct Obj18326 *)p)->f0;
}


/*
 * Field setter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7EF0(u8 *p, u32 v)
{
    ((struct Obj18327 *)p)->f0 = v;
}


/*
 * Loads the byte at +0x4 of the object.
 */
u8 func_021C7EF4(u8 *p)
{
    return ((struct Obj18328 *)p)->f4;
}


u8 *func_021C7EF8(u8 *p, u8 v)
{
    ((struct Obj18329 *)p)->f4 = v;
    return p;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C7EFC(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj18330 *)((u8 *)(a)))->f1C = 1;
func_021C7EF0((u8 *)(a + 4), (3 << 12));
return (int)func_021C7EF8((u8 *)(a + 4), 31);
}

void func_021C7F18(M *m)
{
    m->f1C = 2;
    func_021C7E70((u32)m->sub, 0x3000, 0xaa00, 0x1f, 0x1f, 0xf);
    func_020061E4(0x767);
}

void func_021C7F44(M *m)
{
    m->f1C = 3;
    func_021C7EF0(m->sub, 0xaa00);
    func_021C7EF8(m->sub, 0x1f);
}


void func_021C7F5C(M *m)
{
    m->f1C = 0;
    func_021C7EF0(m->sub, 0);
}

M **func_021C7F70(u32 flags, u32 heap)
{
    M **pp = func_02030734(heap, 4, 1, d_021DE50C, 0x49);
    func_021C7FC0(pp, flags, heap);
    return pp;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7F9C(u8 *p)
{
    func_021C7FF0(p);
    func_020307B0(p);
}


/*
 * Tail-call thunk: forwards to func_021C8000 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7FAC(u32 a)
{
    func_021C8000((u8 *)a);
}
