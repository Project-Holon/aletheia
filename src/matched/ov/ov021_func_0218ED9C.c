/*
 * function: func_0218ED9C
 * address:  0x0218ED9C
 * packet:   pkt_ov021_0218ED9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0218F050  0x0218F050  thumb ov021
 */

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int n;
    int rd;
    int wr;
    int delay;
    int full;
    int keepX;
    int keepY;
    int keepZ;
    Vec *a;
    Vec *b;
    int on;
    int hold;
} Delay;

extern void func_0218F050(Delay *d);

void func_0218ED9C(Delay *d, Vec *inA, Vec *inB, Vec *outA, Vec *outB)
{
    int rd;
    int wr;

    if (d == 0) {
        *outA = *inA;
        *outB = *inB;
        return;
    }
    if (d->on == 0) {
        *outA = *inA;
        *outB = *inB;
        return;
    }
    rd = d->rd;
    wr = d->wr;
    if (d->hold == 0) {
        d->a[wr] = *inA;
        d->b[wr] = *inB;
        wr = (wr + 1) % d->n;
    }
    if (d->full != 0) {
        *outA = d->a[rd];
        *outB = d->b[rd];
    } else {
        *outA = d->a[d->delay];
        *outB = d->b[d->delay];
        if (rd == d->delay)
            d->full = 1;
    }
    if (d->hold != 0) {
        if (rd != wr) {
            rd = (rd + 1) % d->n;
            if (rd == wr)
                func_0218F050(d);
        }
    } else {
        rd = (rd + 1) % d->n;
    }
    d->rd = rd;
    d->wr = wr;
    if (d->keepX == 0) {
        outA->x = inA->x;
        outB->x = inB->x;
    }
    if (d->keepY == 0) {
        outA->y = inA->y;
        outB->y = inB->y;
    }
    if (d->keepZ == 0) {
        outA->z = inA->z;
        outB->z = inB->z;
    }
}
