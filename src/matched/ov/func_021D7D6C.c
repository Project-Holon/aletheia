/*
 * function: BTL_CALC_HasDefaultSickCont
 * address:  0x021D7D6C
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CALC_HasDefaultSickCont   0x021D7D6C  thumb
 *
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: cmp r0, #6; bge loc_021D7D74; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D7D6C  cmp r0,#6; bge; movs r0,#1; bx lr; movs r0,#0; bx lr */
int BTL_CALC_HasDefaultSickCont(int x)
{
    if (x < 6)
        return 1;
    return 0;
}

