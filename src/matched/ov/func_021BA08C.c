/*
 * function: BTL_MAIN_GetField
 * address:  0x021BA08C
 * packet:   pkt_021B85A0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetField   0x021BA08C  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0xaf; lsls r1, r1, #2; ldr r0, [r0, r1]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021BA08C  movs r1,#0xaf; lsls r1,#2; ldr r0,[r0,r1] */
struct Q2 { u8 pad[0x2bc]; u32 v; };
u32 BTL_MAIN_GetField(struct Q2 *p) { return p->v; }

