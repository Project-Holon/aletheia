/*
 * function: MicexStartLimitedSampling
 * address:  0x02703F7C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02088610  0x02088610  arm twl
 */

typedef unsigned int u32;
typedef signed int s32;

extern s32 func_02088610(u32, u32, u32);

u32 MicexStartLimitedSampling(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (func_02088610(9, a3 | 0x02004400, 0) < 0) {
        return 0;
    }
    if (func_02088610(9, (a0 >> 16) | 0x10000, 0) < 0) {
        return 0;
    }
    if (func_02088610(9, (a0 & 0xFFFF) | 0x20000, 0) < 0) {
        return 0;
    }
    if (func_02088610(9, (a1 >> 16) | 0x30000, 0) < 0) {
        return 0;
    }
    if (func_02088610(9, (a1 & 0xFFFF) | 0x40000, 0) < 0) {
        return 0;
    }
    if (func_02088610(9, (a2 >> 16) | 0x50000, 0) < 0) {
        return 0;
    }
    if (func_02088610(9, (a2 & 0xFFFF) | 0x01060000, 0) < 0) {
        return 0;
    }
    return 1;
}
