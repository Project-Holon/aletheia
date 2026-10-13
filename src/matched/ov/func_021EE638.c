/*
 * function: BTL_REC_GetPacketId
 * address:  0x021EE638
 * packet:   pkt_021EDF78
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_REC_GetPacketId   0x021EE638  thumb
 *
 * Reads the u8 field at offset 0 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021EE638  ldrb r0,[r0] */
u8 BTL_REC_GetPacketId(u8 *p) { return *p; }

