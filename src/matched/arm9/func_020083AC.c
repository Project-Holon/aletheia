/*
 * function: func_020083AC
 * address:  0x020083AC
 * packet:   pkt_020083AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf getter on a u16 bitfield word (witness for ov068 callers).
 *
 * symbols:
 *   func_020083AC  0x020083AC  thumb
 */

typedef struct {
    unsigned short a : 4;
    unsigned short b : 2;
    unsigned short c : 1;
    unsigned short d : 1;
    unsigned short e : 1;
    unsigned short f : 1;
} BF;

unsigned int func_020083AC(BF *p) { return p->d; }
