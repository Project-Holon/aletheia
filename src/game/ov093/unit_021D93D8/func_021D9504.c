/*
 * function: func_021D9504
 * address:  0x021D9504
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D9504   0x021D9504  thumb
 *   func_021D9648   0x021D9648  thumb
 * Leaf with no calls and no pool; 8 instructions, 18 bytes: push {r4, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #4; adds r4, r3, #0; bl func_021D9648; str r0, [r4]; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D9504  shape F5: out-param store of func_021D9648(..., 4) */
void func_021D9504(int a, int b, int c, u32 *out)
{
    *out = func_021D9648(b, c, 4);
}

