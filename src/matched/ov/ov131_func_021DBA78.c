/*
 * function: func_021DBA78
 * address:  0x021DBA78
 * packet:   pkt_021DBA78
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14080.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

void func_021DBA78(u8 *p, int i)
{
    func_0204B878(((struct Obj14080 *)p)->f8, (u16)(p[0] + i * 5));
}
