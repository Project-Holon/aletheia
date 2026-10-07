/*
 * file:     unit_021ECE60_p11.c
 * unit:     yes
 * function: func_021EDA04, func_021EDA3C, func_021EDA5C, func_021EDA94, func_021EDAB0, func_021EDAE0, func_021EDB00, func_021EDB20
 * address:  0x021EDA04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021F803C  0x021F803C  thumb  ov094
 *   func_021B9AE0  0x021B9AE0  thumb  ov093
 *   func_021B8BD0  0x021B8BD0  thumb  ov093
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021F8B28  0x021F8B28  thumb  ov094
 *   func_021EDC28  0x021EDC28  thumb  ov093
 *   func_021EDCA8  0x021EDCA8  thumb  ov093
 *   func_021EDF4C  0x021EDF4C  thumb  ov093
 *   func_021EDF78  0x021EDF78  thumb  ov093
 *   func_021EDF7C  0x021EDF7C  thumb  ov093
 *   func_021EDFC4  0x021EDFC4  thumb  ov093
 */
#include "../../matched/include/Obj21607.h"
#include "../../matched/include/Obj21608.h"
#include "../../matched/include/Obj21609.h"
#include "../../matched/include/Obj21610.h"
#include "../../matched/include/Obj21611.h"
#include "../../matched/include/Obj21612.h"
#include "../../matched/include/Obj21613.h"
#include "../../matched/include/Obj21614.h"

struct W;
typedef unsigned char u8;

typedef unsigned int u32;

struct E { u8 *a0; u8 *owner; u8 k8; u8 v9; u8 fa; u8 fb; };

typedef enum { B_FALSE, B_TRUE } Bool;

extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D5B68(void *m);
extern void func_021F803C(u32 a, void *m, u32 c);
extern u8 func_021B9AE0(u32);
extern int func_021B8BD0(u8 *, u8);
extern void func_021F8504(u32, u32, u32);
extern int func_021F8B28(void);
extern void func_021EDC28(struct W *w, u8 a1, int flag);
extern int func_021EDCA8(u8 *);
extern void func_021EDF4C(struct W *w);
extern int func_021EDF78(u8 *);
extern void func_021EDF7C(u8 *, u8);
extern int func_021EDFC4(u8 *);
void func_021EDA04(struct E *e);
Bool func_021EDA3C(u8 *p, u32 x);
void func_021EDA5C(u8 *p, u8 a, int b);
void func_021EDA94(u8 *p, u32 x);
void func_021EDAB0(u8 *p, u32 x);
void func_021EDAE0(u8 *p, u32 x);
void func_021EDB00(u8 *p, u8 a);
void func_021EDB20(u8 *p, u32 x);

void func_021EDA04(struct E *e)
{
    if (e->fb != 0) {
        e->a0 = func_021B98AC(*(char *const * *)&((struct Obj21607 *)(e->owner))->f138, e->k8);
        if (func_021D5B68(e->a0) == 0) {
            func_021F803C(((struct Obj21608 *)(e->owner))->f134, e->a0, e->v9);
            e->fa = 1;
        }
    }
}

/*
 * The 0/1 return uses enum constants: with int constants the compiler folds the two returns
 * into a boolean and lays the one first (bne). See
 * docs/idioms/a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md.
 */
Bool func_021EDA3C(u8 *p, u32 x)
{
    if (func_021B8BD0(p, func_021B9AE0(x)) != 0)
        return B_FALSE;
    return B_TRUE;
}

void func_021EDA5C(u8 *p, u8 a, int b)
{
    int r = func_021EDA3C(*(u8 * *)&((struct Obj21609 *)p)->f134, a);
    if (r == 0)
        func_021F8504(0, 0, 0);
    func_021F8B28();
    func_021EDC28((struct W *)(p + 0x90 + r * 0x24), a, b);
}

void func_021EDA94(u8 *p, u32 x)
{
    func_021EDCA8(p + 0x90 + func_021EDA3C(*(u8 * *)&((struct Obj21610 *)p)->f134, x) * 0x24);
}

void func_021EDAB0(u8 *p, u32 x)
{
    u8 k = func_021EDA3C(*(u8 * *)&((struct Obj21611 *)p)->f134, x);
    func_021EDF4C((struct W *)(p + 0x90 + k * 0x24));
    if (k == 0)
        func_021F8504(0, 1, 0);
}

void func_021EDAE0(u8 *p, u32 x)
{
    u8 k = func_021EDA3C(*(u8 * *)&((struct Obj21612 *)p)->f134, x);
    func_021EDF78(p + 0x90 + k * 0x24);
}

void func_021EDB00(u8 *p, u8 a)
{
    func_021EDF7C(p + 0x90 + func_021EDA3C(*(u8 * *)&((struct Obj21613 *)p)->f134, a) * 0x24, a);
}

void func_021EDB20(u8 *p, u32 x)
{
    func_021EDFC4(p + 0x90 + func_021EDA3C(*(u8 * *)&((struct Obj21614 *)p)->f134, x) * 0x24);
}
