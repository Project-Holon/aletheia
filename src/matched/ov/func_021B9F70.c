/*
 * function: func_021B9F70
 * address:  0x021B9F70
 * packet:   pkt_021B85A0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9F70   0x021B9F70  thumb
 *
 * Leaf with no calls and no pool; 10 instructions, 20 bytes: movs r2, #0x28; muls r2, r1, r2; adds r0, r0, r2; ldr r0, [r0, #0x20]; cmp r0, #0; bne loc_021B9F80; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021B9F70  movs r2,#0x28; muls r2,r1,r2; adds r0,r0,r2; ldr r0,[r0,#0x20] */
int func_021B9F70(u8 *p, int i) { return *(u32 *)(p + i * 0x28 + 0x20) == 0; }

