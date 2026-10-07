/*
 * file:     unit_02703A34_p01.c
 * unit:     yes
 * function: func_02703A34, func_02703A54
 * address:  0x02703A34
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_027026DC  0x027026DC  code twl a2
 */
typedef unsigned int u32;

extern u32 func_027026DC(void);
void func_02703A34(u32 a0, u32 a1);
void func_02703A54(u32 a0, u32 a1);


void func_02703A34(u32 a0, u32 a1) {
    u32 base = func_027026DC();
    *(u32 *)(base + (a0 << 2) + 0x2284) = a1;
}


void func_02703A54(u32 a0, u32 a1) {
    u32 base = func_027026DC();
    *(u32 *)(base + (a0 << 2) + 0x22D4) = a1;
}
