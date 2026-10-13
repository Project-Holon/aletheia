/*
 * function: MicexStopLimitedSampling
 * address:  0x02704088
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 0x03004500 is a fixed DSi main-RAM work buffer address used as a cast
 *   constant by the original source.  It is a literal pool word, not a
 *   relocation, and needs no witness.
 *
 * symbols:
 *   func_02088610  0x02088610  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;

extern s32 func_02088610(u32, u32, u32);

u32 MicexStopLimitedSampling(void) {
    u32 res = 0;
    if (func_02088610(9, 0x03004500, 0) >= 0) {
        res = 1;
    }
    return res;
}
