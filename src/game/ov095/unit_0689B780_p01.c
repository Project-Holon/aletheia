/*
 * file:     unit_0689B780_p01.c
 * unit:     yes
 * function: func_0689B780, func_0689B790, func_0689B7A8
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
 *   func_0220270C  0x0220270C  thumb  ov094
 *   func_02202DC4   0x02202DC4  thumb  ov094
 *   d_0689D934      0x0689D934  data   ov095
 *   d_0689DEBC      0x0689DEBC  data   ov095
 *   func_0689B7EC  0x0689B7EC  thumb  ov095
 *   func_0689BF3C  0x0689BF3C  thumb  ov095
 *   func_0689B7FC  0x0689B7FC  thumb  ov095
 */
#include "../../matched/include/Obj21900.h"
#include "../../matched/include/Obj21901.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0220270C(char *s, int mode, void *arg);
extern void func_02202DC4(void *, void *, void *);
extern u32 func_0689B7EC(u32 a);
extern void func_0689BF3C(u32 e, u32 a, u32 x, u32 b, u32 c);
extern void func_0689B7FC(void *a, void *b, u32 c, int t);
void func_0689B780(void *p, void *q);
void func_0689B790(void *p);
void func_0689B7A8(void *a, u32 b, u32 c, int d);
extern char d_0689D934[];
extern char d_0689DEBC[];



/*
 * Witness leaf for ov093 func_021EAEA8 (its tail-call pool word is 0x0689B781).
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

    x = func_0689B7EC((u32)a);
    if (d != 0)
        func_0689BF3C((&c)[2], (u32)a, x, b, c);
    else
        func_0689B7FC((void *)((&c)[2]), a, x, b);
}
