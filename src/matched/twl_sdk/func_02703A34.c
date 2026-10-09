/*
 * function: func_02703A34
 * address:  0x02703A34
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027026DC  0x027026DC  arm twl a2
 */

typedef unsigned int u32;

extern u32 func_027026DC(void);

void func_02703A34(u32 a0, u32 a1) {
    u32 base = func_027026DC();
    *(u32 *)(base + (a0 << 2) + 0x2284) = a1;
}
