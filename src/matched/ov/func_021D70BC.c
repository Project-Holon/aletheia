/*
 * function: BTL_EVENT_EnableFactorSpecialEvent
 * address:  0x021D70BC
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_EnableFactorSpecialEvent   0x021D70BC  thumb
 *
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: movs r1, #1; ldr r2, [r0, #0x18]; lsls r1, r1, #0x1a; orrs r1, r2; str r1, [r0, #0x18]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D70BC  movs r1,#1; ldr r2,[r0,#0x18]; lsls r1,#0x1a; orrs r1,r2;
 *           str r1,[r0,#0x18] */
struct QR { u8 pad[0x18]; u32 v; };
void BTL_EVENT_EnableFactorSpecialEvent(struct QR *p) { p->v |= 1 << 26; }

