/*
 * function: func_02023AF4
 * address:  0x02023AF4
 * packet:   pkt_02023AF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Paints the run [min(lo,hi), max(lo,hi)) of the 0xC0-byte row table at
 * out+0xC0 with a two-tone pattern: the starting value is the descriptor's
 * +2 halfword when lo <= hi and its logical inverse when the bounds are
 * swapped, and the value flips once at split = (hi - lo) * num / den + lo.
 *
 * The notes' four-register rotation (near in r2 against the image's r7,
 * 13 bytes over eleven spellings and both compilers) came from writing the
 * flip with two HAND-HOISTED constant locals `one`/`zero` and a while
 * loop.  Written plainly -- `near = near == 0` in a for loop, the else
 * arm as `flag == 0` -- mwcc hoists the two constants itself, numbers
 * `near` after the loop's address temporary, and the whole function is
 * byte-exact.  The inline-helper spelling (`if (v == 0) return 1;
 * return 0;`) and `v ? 0 : 1` compile identically.  The bounds are still
 * unsigned (`bhi`), the lo <= hi arm still comes first, and the split is
 * still `q + lo` with q a named local.
 *
 * EXACT* only because the 82-byte body is followed by a two-byte pad.
 */
#include "../include/Obj06901.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_02023AF4(u8 *desc, u8 *out, s32 num, s32 den)
{
    u32 lo = desc[0];
    u32 hi = desc[1];
    s32 q = (s32)(hi - lo) * num / den;
    s32 split = q + lo;
    s32 i;
    s32 end;
    s32 near;

    if (lo <= hi) {
        i = lo;
        end = hi;
        near = ((struct Obj06901 *)desc)->f2;
    } else {
        i = hi;
        end = lo;
        near = ((struct Obj06901 *)desc)->f2 == 0;
    }

    for (; i < end; i++) {
        if (i == split)
            near = near == 0;
        out[0xc0 + i] = near;
    }
}
