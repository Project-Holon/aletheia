/*
 * function: func_021BF808
 * address:  0x021BF808
 * packet:   pkt_ov110_021BF808
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching func_021BAFDC in ov110 (pkt_ov110_021BAFDC).
 *
 * symbols:
 *   func_021BAFDC  0x021BAFDC  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021BAFDC(u32);
void func_021BF808(u8 *p) { func_021BAFDC(*(u32 *)(p + 0x1c)); }
