/*
 * function: func_02024150
 * address:  0x02024150
 * packet:   pkt_02024150
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
typedef struct {unsigned char pad[3];unsigned char flag:1;unsigned char rest:7;} Bits;
int func_02024150(Bits *p){return p->flag;}
