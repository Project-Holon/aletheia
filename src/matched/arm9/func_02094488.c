/*
 * function: MSL_C_LIB_SprintfWriteProc
 * address:  0x02094488
 * packet:   pkt_02094488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02092344  0x02092344  arm
 */
#include "../include/Obj07071.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_02092344(void *dest, const void *src, unsigned int n);

u32 MSL_C_LIB_SprintfWriteProc(u8 *p, const void *src, u32 n)
{
    u32 pos = ((struct Obj07071 *)p)->f8;
    u32 cap = ((struct Obj07071 *)p)->f4;

    if (pos + n > cap)
        n = cap - pos;
    func_02092344(*(u8 * *)&((struct Obj07071 *)p)->f0 + pos, src, n);
    ((struct Obj07071 *)p)->f8 += n;
    return 1;
}
