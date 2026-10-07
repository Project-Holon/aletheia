/*
 * file:     weather_task_p64.c
 * unit:     yes
 * function: func_021A5708, func_021A5728, func_021A572C, func_021A5738, func_021A575C, func_021A5764, func_021A5768, func_021A5778
 * address:  0x021A5708
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
 *   func_021A53A4  0x021A53A4  thumb  ov021
 *   func_021A5378  0x021A5378  thumb  ov021
 *   func_021A3998  0x021A3998  thumb  ov021
 *   func_021A3960  0x021A3960  thumb
 *   func_021A5390  0x021A5390  thumb  ov021
 *   func_021A550C  0x021A550C  thumb
 */
#include "../../matched/include/Obj02083.h"
#include "../../matched/include/Obj18050.h"
#include "../../matched/include/Obj09570.h"
#include "../../matched/include/Obj18051.h"
#include "../../matched/include/Obj12088.h"
#include "../../matched/include/Obj18052.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u8 pad[0x14];
    u16 saved;
    u8 flag;
} Obj021A5738;

extern int func_021A3998(u8 *a);
extern void func_021A5378(u32 *p, int on);
extern void func_021A53A4(u32 *p, int on);
extern void *func_021A3960(unsigned char *p);
int func_021A5390(u32 a);
extern void func_021A550C(u32 *p);
int func_021A5708(u32 a);
u32 func_021A5728(u8 *p);
void *func_021A572C(u8 *p);
void func_021A5738(Obj021A5738 *p, int a);
void func_021A575C(u32 *p);
u32 func_021A5764(u8 *p);
int func_021A5768(u32 a, u32 b);
int func_021A5778(u32 a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5708(u32 a)
{
((struct Obj02083 *)((u8 *)(a)))->f14 = 0;
((struct Obj02083 *)((u8 *)(a)))->f16 = 0;
func_021A53A4((u32 *)a, 0);
func_021A5378((u32 *)a, 0);
return func_021A3998((u8 *)(((struct Obj02083 *)((u8 *)(a)))->fC));
}


/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021A5728(u8 *p)
{
    return ((struct Obj18050 *)p)->fC;
}


/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void *func_021A572C(u8 *p)
{
    return func_021A3960(((struct Obj09570 *)p)->fC);
}


void func_021A5738(Obj021A5738 *p, int a)
{
    u16 s;

    if (func_021A5390((u32)p) == 1) {
        s = p->saved;
        func_021A5708((u32)p);
        if (a == 1) {
            p->saved = s;
            p->flag = 1;
        }
    }
}


/*
 * Tail-call thunk: forwards to func_021A550C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A575C(u32 *p)
{
    func_021A550C(p);
}


/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
u32 func_021A5764(u8 *p)
{
    return ((struct Obj18051 *)p)->f1C;
}


int func_021A5768(u32 a, u32 b)
{
if (b == 1) {
    ((struct Obj12088 *)((u8 *)(a)))->f1C = 1;
    return a;
}
((struct Obj12088 *)((u8 *)(a)))->f1C = 0;
return a;
}


int func_021A5778(u32 a)
{
if (((struct Obj18052 *)((u8 *)(a)))->f0 == 3) {
    return 1;
}
return 0;
}
