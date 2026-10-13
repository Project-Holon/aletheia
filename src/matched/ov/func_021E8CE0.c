/*
 * function: BTLV_CORE_PackBytes
 * address:  0x021E8CE0
 * packet:   pkt_021E8CE0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_PackBytes   0x021E8CE0  thumb
 *
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: lsls r0, r0, #0x18; lsrs r2, r0, #0x10; lsls r0, r1, #0x18; lsrs r0, r0, #0x18; orrs r0, r2; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E8CE0  ((a & 0xff) << 8) | (b & 0xff) as u16 */
u16 BTLV_CORE_PackBytes(u32 a, u32 b) { return (u16)(((a & 0xff) << 8) | (b & 0xff)); }

