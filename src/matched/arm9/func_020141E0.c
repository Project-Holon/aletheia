/*
 * function: func_020141E0
 * address:  0x020141E0
 * packet:   pkt_020141E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 18 lane ties_b: unlabelled follower of func_020141DC; copies the three words at +0x10 out, read into locals last-to-first.
 */

typedef struct Vec020141E0 {
    int x;
    int y;
    int z;
} Vec020141E0;

typedef struct Rec020141E0 {
    int f0;
    int f4;
    int f8;
    int fC;
    Vec020141E0 v;
} Rec020141E0;

void func_020141E0(const Rec020141E0 *p, Vec020141E0 *out)
{
    int z = p->v.z;
    int y = p->v.y;
    int x = p->v.x;

    out->x = x;
    out->y = y;
    out->z = z;
}
