/*
 * function: func_020141F0
 * address:  0x020141F0
 * packet:   pkt_020141F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 18 lane ties_b: unlabelled follower; clears the +0xC word and struct-assigns the three words at +0x10.
 */

typedef struct Vec020141F0 {
    int x;
    int y;
    int z;
} Vec020141F0;

typedef struct Rec020141F0 {
    int f0;
    int f4;
    int f8;
    int fC;
    Vec020141F0 v;
} Rec020141F0;

void func_020141F0(Rec020141F0 *p, const Vec020141F0 *v)
{
    p->fC = 0;
    p->v = *v;
}
