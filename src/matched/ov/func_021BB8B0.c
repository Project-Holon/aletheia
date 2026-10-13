/*
 * function: BTL_SERVER_GetActionTableEntry
 * address:  0x021BB8B0
 * packet:   pkt_021BB840
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_GetActionTableEntry   0x021BB8B0  thumb
 *
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: movs r3, #0xc; muls r3, r1, r3; lsls r1, r2, #2; adds r0, r0, r3; ldr r0, [r1, r0]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021BB8B0  movs r3,#0xc; muls r3,r1,r3; lsls r1,r2,#2; adds r0,r0,r3;
 *           ldr r0,[r1,r0] */
u32 BTL_SERVER_GetActionTableEntry(u8 *p, int i, int j)
{
    return *(u32 *)(p + i * 12 + j * 4);
}

