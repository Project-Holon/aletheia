/*
 * function: func_021BE49C
 * address:  0x021BE49C
 * packet:   pkt_021BE49C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14680.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Cfg;
struct Descriptor;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);

void func_021BE49C(u8 *p)
{
    func_02045374((struct Cfg *)(((struct Obj14680 *)p)->f0));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj14680 *)p)->f0)));
}

