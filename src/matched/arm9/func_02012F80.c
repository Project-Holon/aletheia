/*
 * function: GAME_DATA_GetExternalWork
 * address:  0x02012F80
 * packet:   pkt_02012F80
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: reads the word at base + 0x6A8.  No
 * register-saving prologue, so disasm.py never traced a func_ label here;
 * matching it gives the overlay call sites a `matched` witness.
 *
 * symbols:
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 */
#include "../include/Obj15637.h"

int GAME_DATA_GetExternalWork(char *base)
{
    return ((struct Obj15637 *)base)->f6A8;
}
