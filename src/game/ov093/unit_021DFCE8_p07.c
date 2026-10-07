/*
 * file:     unit_021DFCE8_p07.c
 * unit:     yes
 * function: func_021E0104, func_021E0114
 * address:  0x021E0104
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
 *   func_021E0284   0x021E0284  thumb
 *   func_021E01D4   0x021E01D4  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021E0104 stack-arg wrapper: func_021E0284(a, b, c, d, 0x7) */ void func_021E0104(int a, int b, int c, int d);
/* 021E0114 stack-arg wrapper: func_021E01D4(a, b, c, d, 0x7) */ void func_021E0114(int a, int b, int c, int d);


/* 021E0104  stack-arg wrapper: func_021E0284(a, b, c, d, 0x7) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl func_021E0284; add sp, #4; pop {r3, r4, pc}.
 */
void func_021E0104(int a, int b, int c, int d) { func_021E0284(a, b, c, d, 0x7); }


/* 021E0114  stack-arg wrapper: func_021E01D4(a, b, c, d, 0x7) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl func_021E01D4; add sp, #4; pop {r3, r4, pc}.
 */
void func_021E0114(int a, int b, int c, int d) { func_021E01D4(a, b, c, d, 0x7); }
