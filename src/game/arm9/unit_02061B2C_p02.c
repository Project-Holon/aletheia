/*
 * file:     unit_02061B2C_p02.c
 * unit:     yes
 * function: func_02061BB0, func_02061BC0
 * address:  0x02061BB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj11497.h"
#include "../../matched/include/Obj11498.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

u32 func_02061BB0(u8 *p);
u32 func_02061BC0(u8 *p);


/*
 * Returns the base pointer plus the +8 halfword shifted left four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061BB0.c \
 *       --func func_02061BB0 --addr 0x02061BB0 --arm --cc 1.1p1
 */
u32 func_02061BB0(u8 *p)
{
    return ((struct Obj11497 *)p)->f0 + ((u32)((struct Obj11497 *)p)->f8 << 4);
}


/*
 * Returns the base pointer plus the +0xa halfword shifted left four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061BC0.c \
 *       --func func_02061BC0 --addr 0x02061BC0 --arm --cc 1.1p1
 */
u32 func_02061BC0(u8 *p)
{
    return ((struct Obj11498 *)p)->f0 + ((u32)((struct Obj11498 *)p)->fA << 4);
}
