/*
 * unit:     no
 * function: func_02060764
 * address:  0x02060764
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Block extent: writes the two ends of a heap block into a two-word result.
 * out[0] is the block's own start, recovered from the size of the preceding
 * block, which the header packs into the top seven bits of the flag halfword
 * as (flags >> 8) & 0x7f.  out[1] is the block's end: the block plus the
 * 0x10-byte header plus the free-space word at +4.
 *
 * The flag halfword is loaded zero-extended but shifted arithmetically, which
 * is what an int temporary gives: the mask forces the top byte down to seven
 * bits, and re-narrowing the result to u16 is the lsl/lsr pair the sub then
 * folds into its operand.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060764.c \
 *       --func func_02060764 --addr 0x02060764 --cc 1.1p1 --arm
 */
#include "../include/Obj00512.h"

typedef unsigned short u16;

void func_02060764(int *out, int *blk)
{
    int f = ((struct Obj00512 *)blk)->f2;

    out[0] = (int)blk - (u16)((f >> 8) & 0x7f);
    out[1] = blk[1] + (int)(blk + 4);
}
