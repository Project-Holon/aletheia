/*
 * function: func_021DC614
 * address:  0x021DC614
 * packet:   pkt_021DC604
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DC614   0x021DC614  thumb
 *   func_021D92CC   0x021D92CC  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xcc; bl func_021D92CC; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DC614  shifted 4-arg wrapper -> func_021D92CC(..., 0xcc) */
void func_021DC614(int a, int b, int c, int d)
{
    func_021D92CC(b, c, d, 0xcc);
}

