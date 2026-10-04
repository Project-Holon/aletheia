/*
 * function: func_0202B834
 * address:  0x0202B834
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Compares the +8 field against func_0202B810() (the +4 field by way of
 * func_020127A4) and returns 1 when they differ, 0 when they match.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B834.c \
 *       --func func_0202B834 --addr 0x0202B834 --thumb --cc 1.1p1
 */
#include "../include/Obj15844.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

extern unsigned short func_0202B810(void);

u32 func_0202B834(struct Obj *o)
{
    if (((struct Obj15844 *)o)->f8 == func_0202B810()) {
        return 0;
    }
    return 1;
}
