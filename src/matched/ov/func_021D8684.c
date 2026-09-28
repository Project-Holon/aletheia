/*
 * function: func_021D8684
 * address:  0x021D8684
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8684   0x021D8684  thumb
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D869A; movs r0, #0x41; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D8684  shape F1: gate on func_021D775C(4) */
void func_021D8684(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x41, 1);
}

