/*
 * function: func_0216D63C
 * address:  0x0216D63C
 * packet:   pkt_0216D63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: dependency of func_0217C294 (ov018 tail-call
 * thunk), which unblocks func_0216AC90 and func_0216ACCC.
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_0216D63C(char *a0, int a1)
{
    switch (a1) {
    case 0:
        return ((struct Obj00113 *)a0)->f20;
    case 1:
        return ((struct Obj00113 *)a0)->f22;
    case 2:
        return ((struct Obj00113 *)a0)->f24;
    default:
        return 0;
    }
}
