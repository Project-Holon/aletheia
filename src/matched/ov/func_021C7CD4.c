/*
 * function: BTL_SERVER_FLOW_GetPlayerResistedCount
 * address:  0x021C7CD4
 * packet:   pkt_021C7CD4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPlayerResistedCount   0x021C7CD4  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x7e; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021C7CD4  movs r1,#0x7e; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q6 { u8 pad[0x1f80]; u16 v; };
u16 BTL_SERVER_FLOW_GetPlayerResistedCount(struct Q6 *p) { return p->v; }

