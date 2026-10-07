/*
 * file:     unit_027026DC_p01.c
 * unit:     yes
 * function: func_027026DC, func_027026EC
 * address:  0x027026DC
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
 *   data_027341A4  0x027341A4  data twl a2
 *   func_020862B8  0x020862B8  code twl a2
 *   func_020862D4  0x020862D4  code twl a2
 */
typedef unsigned int u32;

typedef unsigned char u8;

extern void func_020862B8(u32, u32);
extern void func_020862D4(u32, u32);
u32 func_027026DC(void);
void func_027026EC(void);
extern u32 data_027341A4[];


u32 func_027026DC(void) {
    return data_027341A4[0];
}


void func_027026EC(void) {
    u8 val;
    u8 *r5;
    u32 r4;
    u32 base = data_027341A4[0];
    if (base != 0) {
        r5 = (u8 *)*(u32 *)(base + 0x2274);
        r4 = 1;
        func_020862B8((u32)r5, r4);
        val = r5[0];
        if (val & 1) {
            r5[0] = val & 0xFE;
            func_020862D4((u32)r5, r4);
        }
    }
}
