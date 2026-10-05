/*
 * function: func_020141DC
 * address:  0x020141DC
 * packet:   pkt_020141DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 lane untried_small: a getter of the +0xC word; listing extent runs over the unlabelled neighbours 0x020141E0 and 0x020141F0.
 */

typedef struct Rec020141DC {
    int f0;
    int f4;
    int f8;
    int fC;
} Rec020141DC;

int func_020141DC(const Rec020141DC *p)
{
    return p->fC;
}
