/*
 * function: func_02704088
 * address:  0x02704088
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   data_03004500  0x03004500  data twl a2
 *   func_02088610  0x02088610  code twl a2
 */

typedef unsigned int u32;
typedef signed int s32;

extern u32 data_03004500[];
extern s32 func_02088610(u32, u32, u32);

u32 func_02704088(void) {
    u32 res = 0;
    if (func_02088610(9, (u32)data_03004500, 0) >= 0) {
        res = 1;
    }
    return res;
}
