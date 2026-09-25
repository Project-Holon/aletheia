/*
 * function: func_021E7248
 * address:  0x021E7248
 * packet:   pkt_021E7248
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct
{
    int x;
    int y;
    int z;
} T;

typedef struct
{
    T f0;
    T f0c;
    T f18;
    T f24;
    T f30;
    int f3c;
    int f40;
} S;

void func_021E7248(S *d, T *a, T *b, T *c, T *dd, int e)
{
    d->f0 = *a;
    d->f0c = *a;
    d->f18 = *b;
    d->f24 = *c;
    d->f30 = *dd;
    d->f3c = 0;
    d->f40 = e;
}
