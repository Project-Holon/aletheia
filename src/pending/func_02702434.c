/*
 * function: func_02702434
 * address:  0x02702434
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_027026B4  0x027026B4  code twl a2
 *   func_02702468  0x02702468  code twl a2
 */

typedef unsigned int u32;

extern u32 func_027026B4(void);
extern u32 func_02702468(u32, u32, u32);

u32 func_02702434(u32 a0, u32 a1, u32 a2) {
    if (func_027026B4() == 0) {
        return 4;
    }
    return func_02702468(a0, a1, a2);
}
