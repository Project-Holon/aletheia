/*
 * function: func_02702980
 * address:  0x02702980
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027026DC  0x027026DC  code twl a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_027026DC(void);

u32 func_02702980(void) {
    u32 base = func_027026DC();
    u32 ptr = *(u32 *)(base + 0x2278);
    return *(u16 *)(ptr + 0x9E);
}
