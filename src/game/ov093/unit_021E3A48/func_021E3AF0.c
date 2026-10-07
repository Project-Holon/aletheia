/*
 * function: func_021E3AF0
 * address:  0x021E3AF0
 * packet:   pkt_021DFA3C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E3AF0   0x021E3AF0  thumb
 *   func_021D7040   0x021D7040  thumb
 *   func_021D775C   0x021D775C  thumb
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E3B06; adds r0, r5, #0; bl func_021D7040; pop {r3, r4, r5, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E3AF0  shape F3: gate on func_021D775C(2) then func_021D7040 */
void func_021E3AF0(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D7040(a);
}

