/*
 * file:     weather_task_p81.c
 * unit:     yes
 * function: func_021A6A8C, func_021A6AA0, func_021A6B08, func_021A6B30
 * address:  0x021A6A8C
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
 *   func_021A6908  0x021A6908  thumb
 *   func_021A6774  0x021A6774  thumb
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *   func_021A678C  0x021A678C  thumb  ov021
 *   func_021A6B9C  0x021A6B9C  thumb  ov021
 *   func_021A6C4C  0x021A6C4C  thumb  ov021
 *   func_021A6C64  0x021A6C64  thumb  ov021
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 */
#include "../../matched/include/Obj07501.h"

typedef struct S S;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    short h2;
} P;

extern u32 func_021A6908(u8 *p, u32 a1);
extern void func_021A6774(void *a);
extern int func_021A66F8(u8 *p, u32 m);
extern void func_021A678C(void *a);
extern void func_021A6B9C(u8 *p);
extern u32 func_021A6C4C(u8 *p, u32 v);
extern u32 func_021A6C64(u8 *p);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 *func_0216D550(u32 *p, u32 v);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, u32 v);
extern void func_021A3964(u8 *o, u32 v);
extern void func_020061E4(u32 a);
extern int func_02006148(u32 a0);
extern void func_020061F8(void);
int func_021A6A8C(S *a, int b, int c);
u32 func_021A6AA0(u8 *p, u32 a1);
void func_021A6B08(P *p, u8 v);
void func_021A6B30(P *p);


int func_021A6A8C(S *a, int b, int c)
{
    int r = func_021A6908((u8 *)a, b);
    func_021A6774(a);
    return r;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021A6AA0(u8 *p, u32 a1)
{
    u32 r5;

    if (!func_021A66F8(p, 0x40)) {
        func_021A678C(p);
        func_021A6B9C(p + 0xC);
    }
    r5 = (u16)func_021A6C4C(p + 0xC, a1);
    if (func_021A6C64(p + 0xC)) {
        func_0216D548(((struct Obj07501 *)p)->f1C, 0x18);
        func_0216D410(((struct Obj07501 *)p)->f1C, func_02197E7C(r5, 8));
        func_021A3964(*(u8 * *)&((struct Obj07501 *)p)->f14, 1);
        r5 = 9;
    } else {
        func_0216D550(((struct Obj07501 *)p)->f1C, 0x18);
    }
    return r5;
}


void func_021A6B08(P *p, u8 v)
{
    if (p->b0 != 1 || v != p->b1) {
        func_020061E4(0x6d1);
        p->b0 = 1;
        p->b1 = v;
        p->h2 = 0;
    }
}


void func_021A6B30(P *p)
{
    if (p->b0) {
        p->b0 = 0;
        p->h2 = 0;
        func_02006148(0x6d1);
        func_020061F8();
    }
}
