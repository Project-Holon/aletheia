/*
 * function: func_02024994
 * address:  0x02024994
 * packet:   pkt_02024994
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
typedef unsigned int u32;
int func_02024994(const u32 *p, u32 idx){return (*p >> idx) & 1;}
