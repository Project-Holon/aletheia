/*
 * function: func_021DDB64
 * address:  0x021DDB64
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DDB64   0x021DDB64  thumb
 *   func_021DDCD8   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #1; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DDB64  shape F2: two stack constants (1, 0) */
void func_021DDB64(int a, int b, int c, int d)
{
    func_021DDCD8(a, b, c, d, 1, 0);
}

