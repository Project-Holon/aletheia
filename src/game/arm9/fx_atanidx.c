/*
 * file:     fx_atanidx.c
 * function: FX_Atan2Idx
 * address:  0x0207CFB8
 * packet:   pkt_0207CFB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfx fx_atanidx.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Four-quadrant arctangent as a 16-bit angle index: folds (y, x) into one
 * octant by sign and magnitude, looks the ratio up in FX_AtanIdxTable_ and
 * adds or subtracts it from the octant's base angle; the diagonals and axes
 * return their angle directly.
 *
 * symbols:
 *   FX_Div            0x0207C768  arm
 *   FX_AtanIdxTable_  0x020A5B38  data
 */

#include "../types.h"

#include "fx_cp.h"
extern const s16 FX_AtanIdxTable_[129];

u16 FX_Atan2Idx(fx32 y, fx32 x)
{
    fx32 a;
    fx32 b;
    int c;
    int sgn;

    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                a = y;
                b = x;
                c = 0;
                sgn = 1;
            } else if (x < y) {
                a = x;
                b = y;
                c = 0x4000;
                sgn = 0;
            } else {
                return 0x2000;
            }
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                a = x;
                b = y;
                c = 0x4000;
                sgn = 1;
            } else if (x > y) {
                a = y;
                b = x;
                c = 0x8000;
                sgn = 0;
            } else {
                return 0x6000;
            }
        } else {
            return 0x4000;
        }
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                a = y;
                b = x;
                c = -0x8000;
                sgn = 1;
            } else if (x < y) {
                a = x;
                b = y;
                c = -0x4000;
                sgn = 0;
            } else {
                return 0xa000;
            }
        } else if (x > 0) {
            if (x < y) {
                a = x;
                b = y;
                c = -0x4000;
                sgn = 1;
            } else if (x > y) {
                a = y;
                b = x;
                c = 0;
                sgn = 0;
            } else {
                return 0xe000;
            }
        } else {
            return 0xc000;
        }
    } else {
        if (x >= 0) {
            return 0;
        } else {
            return 0x8000;
        }
    }

    if (b == 0) {
        return 0;
    }
    if (sgn) {
        return (u16)(c + FX_AtanIdxTable_[FX_Div(a, b) >> 5]);
    } else {
        return (u16)(c - FX_AtanIdxTable_[FX_Div(a, b) >> 5]);
    }
}
