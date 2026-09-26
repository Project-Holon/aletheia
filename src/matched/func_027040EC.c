/*
 * function: func_027040EC
 * address:  0x027040EC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02150FEC  0x02150FEC  data arm9 a1
 *   func_020879EC  0x020879EC  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02150FEC[];
extern u32 func_020879EC(void);

u32 func_027040EC(void) {
    if (func_020879EC() == 0x12) {
        return 0x80000000;
    }
    return data_02150FEC[1];
}
