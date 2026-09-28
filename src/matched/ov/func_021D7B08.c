/*
 * function: func_021D7B08
 * address:  0x021D7B08
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D7B08   0x021D7B08  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: cmp r0, r1; bge loc_021D7B0E; adds r0, r1, #0; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D7B08  cmp r0,r1; bge; adds r0,r1,#0 */
int func_021D7B08(int a, int b)
{
    if (a < b)
        a = b;
    return a;
}

