/*
 * function: BTL_SERVER_FLOW_GetHistoryList
 * address:  0x021C8130
 * packet:   pkt_021C7CD4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetHistoryList   0x021C8130  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x3e; lsls r1, r1, #4; adds r0, r0, r1; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021C8130  movs r1,#0x3e; lsls r1,#4; adds r0,r0,r1 */
u8 *BTL_SERVER_FLOW_GetHistoryList(u8 *p) { return p + 0x3e0; }

