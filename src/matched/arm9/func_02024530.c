/*
 * function: PMSI_PARAM_GetSentenceId
 * address:  0x02024530
 * packet:   pkt_02024530
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
typedef unsigned short u16;
unsigned int PMSI_PARAM_GetSentenceId(const u16 *p) { return p[1]; }
