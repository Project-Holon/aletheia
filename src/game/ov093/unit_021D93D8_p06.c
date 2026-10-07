/*
 * file:     unit_021D93D8_p06.c
 * unit:     yes
 * function: func_021D99A4, func_021D99C8, func_021D99E0
 * address:  0x021D99A4
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
void func_021D99A4(int a,int b,int c);
/* 021D99C8 shape F1: gate on func_021D775C(4) */ void func_021D99C8(int a, int b, int c);
/* 021D99E0 shape F1: gate on func_021D775C(4) */ void func_021D99E0(int a, int b, int c);

void func_021D99A4(int a,int b,int c) { if(c==func_021D775C(4) && c!=func_021D775C(3)) func_021D76BC(0x41,1); }


/* 021D99C8  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D99DE; movs r0, #0x41; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D99C8(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x41, 1);
}


/* 021D99E0  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D99F6; movs r0, #0x47; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D99E0(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x47, 1);
}
