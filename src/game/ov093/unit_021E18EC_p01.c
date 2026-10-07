/*
 * file:     unit_021E18EC_p01.c
 * unit:     yes
 * function: func_021E1938, func_021E1948
 * address:  0x021E1938
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E19F8   0x021E19F8  thumb
 *   func_021E1A2C   0x021E1A2C  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021E1938 shifted 4-arg wrapper -> func_021E19F8(..., 0x1) */ void func_021E1938(int a, int b, int c, int d);
/* 021E1948 shifted 4-arg wrapper -> func_021E1A2C(..., 0x1) */ void func_021E1948(int a, int b, int c, int d);


/* 021E1938  shifted 4-arg wrapper -> func_021E19F8(..., 0x1) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #1; bl func_021E19F8; pop {r3, pc}.
 */
void func_021E1938(int a, int b, int c, int d)
{
    func_021E19F8(b, c, d, 0x1);
}


/* 021E1948  shifted 4-arg wrapper -> func_021E1A2C(..., 0x1) */
void func_021E1948(int a, int b, int c, int d)
{
    func_021E1A2C(b, c, d, 0x1);
}
