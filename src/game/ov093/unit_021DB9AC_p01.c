/*
 * file:     unit_021DB9AC_p01.c
 * unit:     yes
 * function: func_021DB9AC, func_021DB9B8
 * address:  0x021DB9AC
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
 *   d_021F06F8 0x021F06F8 data a4
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

int *func_021DB9AC(int *p);
/* 021DB9B8 shape F1: gate on func_021D775C(4) */ void func_021DB9B8(int a, int b, int c);
extern int d_021F06F8;

int *func_021DB9AC(int *p) { *p=1; return &d_021F06F8; }


/* 021DB9B8  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DB9CE; movs r0, #0x51; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DB9B8(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x51, 0);
}
