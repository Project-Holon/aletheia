/*
 * file:     pokemontrade_demo_up_p04.c
 * unit:     yes
 * function: func_021D5694, func_021D56E0, func_021D56E4, func_021D56F0, func_021D56FC, func_021D572C
 * address:  0x021D5694
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj01724.h"
#include "../../matched/include/Obj22670.h"
#include "../../matched/include/Obj22671.h"
#include "../../matched/include/Obj22672.h"
#include "../../matched/include/Obj22673.h"
#include "../../matched/include/Obj22674.h"
#include "../../matched/include/Obj10351.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_021E3034(u32 *p, int a1);
extern void func_021E2F2C(void *);
extern u32 func_020307B0(void *p);
extern void func_021D8E84(void *, int);
extern void func_021DFDA0(void *p);
void func_021D5694(void *p);
void func_021D56E0(void);
void func_021D56E4(u8 *p, u32 v);
void func_021D56F0(u8 *p);
void func_021D56FC(void *p);
void func_021D572C(u8 *p, int idx);


/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * func_021D5694 callers' targets; this is the first callee of func_021D6C78.
 *
 * Addresses are Black-image addresses.
 */
void func_021D5694(void *p)
{
    u8 *b = p;

    if (((struct Obj22670 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0 != 0)
        func_0204B3B4(((struct Obj22671 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0);
    if (((struct Obj01724 *)b)->f8A8 != 0) {
        func_0204A8D4((u32)(((struct Obj01724 *)b)->f8A8));
        func_0204ADA4((u32)(((struct Obj01724 *)b)->f88C));
        func_0204AFD8((u32)(((struct Obj01724 *)b)->f8BC));
    }
    ((struct Obj01724 *)b)->f8A8 = 0;
    ((struct Obj01724 *)b)->f88C = 0;
    ((struct Obj01724 *)b)->f8BC = 0;
    ((struct Obj22672 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0 = 0;
}


void func_021D56E0(void) { }


void func_021D56E4(u8 *p, u32 v) { ((struct Obj22673 *)p)->fF2C = v; }


void func_021D56F0(u8 *p) { ((struct Obj22674 *)p)->f1094 = 1; }


void func_021D56FC(void *p)
{
    func_021D5694(p);
    func_021E3034(((struct Obj01724 *)p)->fC, 6);
    func_021E2F2C(((struct Obj01724 *)p)->fC);
    func_020307B0(((struct Obj01724 *)p)->fC);
    ((struct Obj01724 *)p)->fC = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D572C(u8 *p, int idx)
{
    if (((struct Obj10351 *)p)->f85C != 0) {
        func_020307B0((void *)(((struct Obj10351 *)p)->f85C));
        ((struct Obj10351 *)p)->f85C = 0;
    }
}
