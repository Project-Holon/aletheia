/*
 * function: func_021B9AD0
 * address:  0x021B9AD0
 * packet:   pkt_021B9AD0
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14771.h"

typedef unsigned int   u32;
struct PrintSys;
struct Tcbl;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);

void func_021B9AD0(char *p)
{
    func_0201C4E4((struct PrintSys *)(((struct Obj14771 *)p)->f10));
    func_020310C4((struct Tcbl *)(((struct Obj14771 *)p)->f4));
}
