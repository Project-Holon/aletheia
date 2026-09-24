/*
 * function: func_021D9250
 * address:  0x021D9250
 * packet:   pkt_021D8A8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D9250   0x021D9250  thumb
 *   func_021D92CC   0x021D92CC  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xcf; bl func_021D92CC; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D9250  shifted 4-arg wrapper -> func_021D92CC(..., 0xcf) */
void func_021D9250(int a, int b, int c, int d)
{
    func_021D92CC(b, c, d, 0xcf);
}

