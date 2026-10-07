/*
 * file:     unit_027026DC_p02.c
 * unit:     yes
 * function: func_027028B0, func_027028E4
 * address:  0x027028B0
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
 *   func_020862B8  0x020862B8  code twl a2
 */
typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
u32 func_027028B0(void);
asm void func_027028E4(void);


u32 func_027028B0(void) {
    u32 base = func_027026DC();
    u32 r1 = 0;
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        func_020862B8(ptr, 2);
        r1 = *(u16 *)(ptr + 0x24);
    }
    return r1;
}

asm void func_027028E4(void) {
    stmdb sp!, {r0, r1, r2, r3}
}
