/*
 * function: BTL_SERVER_FLOW_GetHitFlagsMultiHit
 * address:  0x021C1194
 * packet:   pkt_021C0C34
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetHitFlagsMultiHit   0x021C1194  thumb
 *
 * Reads the u8 field at #3 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021C1194  ldrb r0,[r0,#3] */
u8 BTL_SERVER_FLOW_GetHitFlagsMultiHit(u8 *p) { return p[3]; }

