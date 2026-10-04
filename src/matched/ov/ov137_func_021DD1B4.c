/*
 * function: func_021DD1B4
 * address:  0x021DD1B4
 * packet:   pkt_021DD1B4
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10615.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct PrintSys;
struct Tcbl;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);

void func_021DD1B4(u8 *p)
{
    if (((struct Obj10615 *)p)->fEC)
        func_0201C4E4(((struct Obj10615 *)p)->fEC);
    func_020310C4(((struct Obj10615 *)p)->fF4);
}
