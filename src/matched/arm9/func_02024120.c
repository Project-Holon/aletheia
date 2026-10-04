/*
 * function: func_02024120
 * address:  0x02024120
 * packet:   pkt_02024120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 *
 * symbols:

 */
typedef unsigned char u8;
u8 func_02024120(u8 *p) { return p[2]; }
