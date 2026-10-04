/*
 * function: func_021626B8
 * address:  0x021626B8
 * packet:   pkt_021626B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: ABS32 target of func_0218AECC (ov021) +0004.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 */
#include "../include/Obj07295.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_021626B8(char *a0, int a1)
{
    if ((a1 == 0 && ((struct Obj07295 *)a0)->f4 == 2) ||
        (a1 == 1 && ((struct Obj07295 *)a0)->f4 == 1) ||
        (a1 == 2 && ((struct Obj07295 *)a0)->f4 == 4) ||
        (a1 == 3 && ((struct Obj07295 *)a0)->f4 == 3))
        return 1;
    return 0;
}
