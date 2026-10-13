/*
 * function: PMSI_PARAM_GetInputMode
 * address:  0x02024144
 * packet:   pkt_02024144
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
typedef unsigned int u32;
u32 PMSI_PARAM_GetInputMode(const u8 *p) { return p[0]; }
