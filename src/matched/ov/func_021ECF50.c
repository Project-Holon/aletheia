/*
 * function: func_021ECF50
 * address:  0x021ECF50
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ECF50   0x021ECF50  thumb  ov093

 * Untraced mid-stream entry point (reached only through the `bx r3` tail thunks, so disasm.py emitted its bytes as a pool run).  Reads the byte at p+0x141: returns 1 and clears it when set, else 0.  The 0x141 index is too wide for Thumb ldrb's 5-bit immediate, so it lives in a pool word and the load is register-offset.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 func_021ECF50(u8 *p) { if (p[0x141]) { p[0x141] = 0; return 1; } return 0; }

