/*
 * function: func_021E7974
 * address:  0x021E7974
 * packet:   pkt_021E795C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E7974   0x021E7974  thumb
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E798A; movs r0, #0x4b; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E7974  shape F1: gate on func_021D775C(3) */
void func_021E7974(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x4b, 1);
}

