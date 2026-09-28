/*
 * function: func_021D54E0
 * address:  0x021D54E0
 * packet:   pkt_021D51CC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D54E0   0x021D54E0  thumb
 * 8 instructions, 16 bytes: movs r2, #0xe; muls r2, r1, r2; adds r1, r0, r2; ldr r0, pool_021D54F0; ldrb r0, [r1, r0]; lsls r0, r0, #0x1c; lsrs r0, r0, #0x1c; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct NB { u8 lo : 4; u8 hi : 4; };
/* 021D54E0  the image extracts with lsls #0x1c / lsrs #0x1c, which is a 4-bit
 * unsigned bitfield read -- neither `& 0xf` nor the shift pair written out in
 * C reproduces it (both narrow to a mask). */
u32 func_021D54E0(u8 *p, u32 i)
{
    return ((struct NB *)(p + i * 0xe + 0x10f))->lo;
}

