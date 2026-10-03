/*
 * function: func_021DCFF8
 * address:  0x021DCFF8
 * packet:   pkt_021DC604
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DCFF8   0x021DCFF8  thumb
 *   func_021D70A8   0x021D70A8  thumb
 *   func_021D805C   0x021D805C  thumb
 * Leaf with no calls and no pool; 6 instructions, 16 bytes: push {r4, lr}; adds r4, r1, #0; bl func_021D70A8; adds r1, r4, #0; bl func_021D805C; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u16 func_021D70A8(void *p);
extern u32 func_021D805C(u32 v, int k);

/* 021DCFF8  pass-through: second callee takes the first one's result */
int func_021DCFF8(int a, int b)
{
    return func_021D805C(func_021D70A8((void *)a), b);
}

