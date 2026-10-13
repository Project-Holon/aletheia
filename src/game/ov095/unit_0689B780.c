/*
 * file:     unit_0689B780.c
 * unit:     yes
 * function: func_0689B780, func_0689B790, func_0689B7A8, func_0689B7FC
 * address:  0x0689B780
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_SERVER_FLOW_ProcSickDamage  0x021C4A64  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   func_021D6324  0x021D6324  thumb
 *   func_0220270C  0x0220270C  thumb  ov094
 *   func_02202DC4   0x02202DC4  thumb  ov094
 *   d_0689D934      0x0689D934  data   ov095
 *   d_0689DEBC      0x0689DEBC  data   ov095
 *   func_0689BF3C  0x0689BF3C  thumb  ov095
 *   func_0689B974  0x0689B974  thumb  ov095
 *   func_0689B9F4  0x0689B9F4  thumb  ov095
 *   func_0689BB7C  0x0689BB7C  thumb  ov095
 *   func_0689BC30  0x0689BC30  thumb  ov095
 *   func_0689BDE0  0x0689BDE0  thumb  ov095
 *   func_0689BEAC  0x0689BEAC  thumb  ov095
 */
#include "../../matched/include/Obj21900.h"
#include "../../matched/include/Obj21901.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0220270C(char *s, int mode, void *arg);
extern void func_02202DC4(void *, void *, void *);
extern u32 BTL_POKEPARAM_GetPokeId(u32 a);
extern void func_0689BF3C(u32 e, u32 a, u32 x, u32 b, u32 c);
extern int BTL_POKEPARAM_IsFainted(u32 a);
extern int func_021D6324(u32 a, u32 b);
extern void BTL_SERVER_FLOW_ProcSickDamage(u32 a, u32 b, u32 c, int d);
extern void func_0689B974(void *a, void *b, int c);
extern void func_0689B9F4(void *a, void *b, int c);
extern void func_0689BB7C(void *a, void *b, int c);
extern void func_0689BC30(u32 a, u32 b, u32 c);
extern void func_0689BDE0(void *a, void *b, int c);
extern void func_0689BEAC(void *a, void *b, int c);
void func_0689B780(void *p, void *q);
void func_0689B790(void *p);
void func_0689B7A8(void *a, u32 b, u32 c, int d);
void func_0689B7FC(void *a, void *b, u32 c, int t);
extern char d_0689D934[];
extern char d_0689DEBC[];


/*
 * Witness leaf for ov093 BTLV_CORE_ShowCounterValue (its tail-call pool word is 0x0689B781).
 * Tail-call forwarding thunk: (*(p+0xb0), 6, q) to func_0220270C (ov094).
 */
void func_0689B780(void *p, void *q)
{
    func_0220270C(((struct Obj21900 *)p)->fB0, 6, q);
}


/*
 * Tail-call forwarding thunk: passes *(p+0xb0) and the two pinned addresses
 * to func_02202DC4 (ov094).  The compiler emits the `ldr r3,pool; bx r3` form
 * because the call is the last statement.
 */
void func_0689B790(void *p)
{
    func_02202DC4(((struct Obj21901 *)p)->fB0, d_0689D934, d_0689DEBC);
}


/*
 * Handed at 0x0689B7AA (the second label after `push {r0-r3}` at 0x0689B7A8).
 * The fifth argument is read through &c ((&c)[2], the first stack slot):
 * taking the address of c is what pushes r0-r3 and makes c reload from its
 * home slot; a plain fifth parameter gives an ordinary push instead.
 */
void func_0689B7A8(void *a, u32 b, u32 c, int d)
{
    u32 x;

    x = BTL_POKEPARAM_GetPokeId((u32)a);
    if (d != 0)
        func_0689BF3C((&c)[2], (u32)a, x, b, c);
    else
        func_0689B7FC((void *)((&c)[2]), a, x, b);
}


void func_0689B7FC(void *a, void *b, u32 c, int t)
{
    int r;

    if (BTL_POKEPARAM_IsFainted((u32)b) != 0)
        return;
    r = func_021D6324((u32)b, t);
    if (r != 0)
        BTL_SERVER_FLOW_ProcSickDamage((u32)a, (u32)b, t, r);
    switch (t) {
    case 0x14:
        func_0689B974(a, b, c);
        break;
    case 0x12:
        func_0689B9F4((void *)a, (void *)b, c);
        break;
    case 0x15:
        func_0689BB7C((void *)a, (void *)b, c);
        break;
    case 8:
        func_0689BC30((u32)a, (u32)b, c);
        break;
    case 0x23:
        func_0689BDE0((void *)a, (void *)b, c);
        break;
    case 0x17:
        func_0689BEAC((void *)a, (void *)b, c);
        break;
    }
}
