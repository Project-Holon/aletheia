/*
 * function: func_021C1718
 * address:  0x021C1718
 * packet:   pkt_ov110_021C1718
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching func_021C1848 in ov110 (pkt_ov110_021C1848).
 *
 * symbols:
 *   func_021C1848  0x021C1848  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 func_021C1848(u32 *p);
u32 func_021C1718(u8 *p) { return func_021C1848((u32 *)(p + 4)); }
