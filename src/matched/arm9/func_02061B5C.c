/*
 * function: func_02061B5C
 * address:  0x02061B5C
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the cursor fields.  No relocations; pure.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061B5C.c \
 *       --func func_02061B5C --addr 0x02061B5C --arm --cc 1.1p1
 */
#include "../include/Obj07006.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_02061B5C(u8 *p)
{
    ((struct Obj07006 *)p)->fA = 0;
    ((struct Obj07006 *)p)->f8 = 0;
    ((struct Obj07006 *)p)->fC = 0;
    ((struct Obj07006 *)p)->f10 = 0;
}
