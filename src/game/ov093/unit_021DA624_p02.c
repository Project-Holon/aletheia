/*
 * file:     unit_021DA624_p02.c
 * unit:     yes
 * function: func_021DA7DC, func_021DA808
 * address:  0x021DA7DC
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);
void func_021DA7DC(int a, int b, int c);
/* 021DA808 shape F1: gate on func_021D775C(4) */ void func_021DA808(int a, int b, int c);


void func_021DA7DC(int a, int b, int c)
{
    if (c == func_021D775C(3)) {
        func_021D76BC(0x28, 6);
        return;
    }
    if (c == func_021D775C(4))
        func_021D76BC(0x27, 6);
}


/* 021DA808  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DA81E; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DA808(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x51, 1);
}
