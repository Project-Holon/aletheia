/*
 * function: func_021D6D7C
 * address:  0x021D6D7C
 * packet:   pkt_021D6D7C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6D7C   0x021D6D7C  thumb
 * 8 instructions, 16 bytes: ldr r1, pool_021D6D8C; ldrh r0, [r0, r1]; cmp r0, #0; beq loc_021D6D88; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D6D7C  halfword field 0x1f2 != 0 */
u32 func_021D6D7C(u8 *p)
{
    return (*(u16 *)(p + 0x1f2) != 0);
}

