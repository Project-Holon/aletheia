/*
 * function: func_021CD9C8
 * address:  0x021CD9C8
 * packet:   pkt_021CD9C8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD9C8   0x021CD9C8  thumb
 * 8 instructions, 16 bytes: ldr r1, pool_021CD9D8; ldrb r0, [r0, r1]; cmp r0, #2; bne loc_021CD9D4; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CD9C8  byte field 0x1a7 == 2 */
u32 func_021CD9C8(u8 *p)
{
    return (*(u8 *)(p + 0x1a7) == 2);
}

