/*
 * function: func_02024160
 * address:  0x02024160
 * packet:   pkt_02024160
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
typedef struct {unsigned char pad[3];unsigned char rest:3;unsigned char flag:1;unsigned char last:4;} Bits;
int func_02024160(Bits *p){return p->flag;}
