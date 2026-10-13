/*
 * function: BTLV_CORE_GetHighByte
 * address:  0x021E8CFC
 * packet:   pkt_021E8CFC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetHighByte   0x021E8CFC  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: asrs r0, r0, #8; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E8CFC  asrs r0,r0,#8; lsls #0x18; lsrs #0x18 */
u8 BTLV_CORE_GetHighByte(s32 v) { return (u8)(v >> 8); }

