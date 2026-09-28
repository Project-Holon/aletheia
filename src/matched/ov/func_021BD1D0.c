/*
 * function: func_021BD1D0
 * address:  0x021BD1D0
 * packet:   pkt_021BD1D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD1D0   0x021BD1D0  thumb
 *   func_021BCA08   0x021BCA08  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; bl func_021BCA08; cmp r0, #0; beq loc_021BD1DE; movs r1, #1; strb r1, [r0, #0xd]; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021BD1D0  guard on a callee's pointer result, then set a byte */
void func_021BD1D0(void)
{
    u8 *p = (u8 *)func_021BCA08();
    if (p != 0)
        p[0xd] = 1;
}

