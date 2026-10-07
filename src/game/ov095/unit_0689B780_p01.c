/*
 * file:     unit_0689B780_p01.c
 * unit:     yes
 * function: func_0689B780, func_0689B790
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
 */
#include "../../matched/include/Obj21900.h"
#include "../../matched/include/Obj21901.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0220270C(char *s, int mode, void *arg);
extern void func_02202DC4(void *, void *, void *);
void func_0689B780(void *p, void *q);
void func_0689B790(void *p);
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
