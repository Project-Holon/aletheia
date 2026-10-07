/*
 * file:     unit_021DC57C_p01.c
 * unit:     yes
 * function: func_021DC604, func_021DC614
 * address:  0x021DC604
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
 *   func_021D928C   0x021D928C  thumb
 *   func_021D92CC   0x021D92CC  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021DC604 shifted 4-arg wrapper -> func_021D928C(..., 0x2) */ void func_021DC604(int a, int b, int c, int d);
/* 021DC614 shifted 4-arg wrapper -> func_021D92CC(..., 0xcc) */ void func_021DC614(int a, int b, int c, int d);


/* 021DC604  shifted 4-arg wrapper -> func_021D928C(..., 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #2; bl func_021D928C; pop {r3, pc}.
 */
void func_021DC604(int a, int b, int c, int d)
{
    func_021D928C(b, c, d, 0x2);
}


/* 021DC614  shifted 4-arg wrapper -> func_021D92CC(..., 0xcc) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xcc; bl func_021D92CC; pop {r3, pc}.
 */
void func_021DC614(int a, int b, int c, int d)
{
    func_021D92CC(b, c, d, 0xcc);
}
