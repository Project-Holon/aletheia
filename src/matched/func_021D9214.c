/*
 * function: func_021D9214
 * address:  0x021D9214
 * packet:   pkt_021D8A8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D9214   0x021D9214  thumb
 *   func_021D928C   0x021D928C  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #1; bl func_021D928C; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D9214  shifted 4-arg wrapper -> func_021D928C(..., 0x1) */
void func_021D9214(int a, int b, int c, int d)
{
    func_021D928C(b, c, d, 0x1);
}

