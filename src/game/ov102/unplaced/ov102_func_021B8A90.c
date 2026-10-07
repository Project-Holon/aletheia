/*
 * function: func_021B8A90
 * address:  0x021B8A90
 * packet:   pkt_021B8A90
 * region:   ov102
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Step the counter at +0x10 up to +0x14, recomputing +0x0 from +0x4, +0xC
 * and the counter; when it has caught up, copy +0x8 into +0x0.
 */

typedef struct Struct021B8A90 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Struct021B8A90;

int func_021B8A90(Struct021B8A90 *p)
{
    if (p->f10 < p->f14 - 1) {
        p->f10 = p->f10 + 1;
        p->f0 = p->f4 + ((p->fC * p->f10) >> 12);
        return 0;
    }
    p->f0 = p->f8;
    return 1;
}
