/*
 * function: func_021ED374
 * address:  0x021ED374
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED374   0x021ED374  thumb  ov093

 * Untraced mid-stream entry point.  `adds r0,#0x42; ldrb r0,[r0]`: the offset exceeds Thumb ldrb's immediate, so it is materialised with adds and the flag is normalised to 0/1 by branch.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 func_021ED374(u8 *p) { if (p[0x42] == 0) return 1; return 0; }

