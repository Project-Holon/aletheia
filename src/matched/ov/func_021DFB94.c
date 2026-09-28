/*
 * function: func_021DFB94
 * address:  0x021DFB94
 * packet:   pkt_021DFA3C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DFB94   0x021DFB94  thumb
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DFBAA; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DFB94  shape F1: gate on func_021D775C(2) */
void func_021DFB94(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x51, 1);
}

