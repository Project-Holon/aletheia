/*
 * function: func_0202C1D4
 * address:  0x0202C1D4
 * packet:   pkt_0202C1D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj15848.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0202C2D8(u32 *p);
extern u32  func_0202C2D0(u32 v);
extern int func_0202C29C(u32 *p, u32 v);
extern void func_0202C2DC(void *p);
extern void func_0202C2C0(void *p);

void func_0202C1D4(u8 *p)
{
    if (func_0202C2D8((u32 *)p) == 1) {
        return;
    }
    ((struct Obj15848 *)p)->f0 = 1;
    if (func_0202C29C((u32 *)p, func_0202C2D0(1)) != 1) {
        return;
    }
    func_0202C2DC(p);
    func_0202C2C0(p);
}
