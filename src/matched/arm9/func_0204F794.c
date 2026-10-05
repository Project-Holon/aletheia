/*
 * function: func_0204F794
 * address:  0x0204F794
 * packet:   pkt_0204F684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Same as func_0204F764 one bit up: the caller's word goes into bit 11.
 *
 * symbols:
 *   none (no external calls, no data references)
 */
#include "../include/Obj08866.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 lo  : 11;
    u16 b11 : 1;
    u16 hi  : 4;
};

void func_0204F794(void *p, u32 idx, u32 *val)
{
    struct Rec *r = (struct Rec *)(*(u8 * *)&((struct Obj08866 *)p)->f8 + idx * 0x1c + 0x18);

    r->b11 = (u16)*val;
}
