/*
 * function: BR_FADE_Update
 * address:  0x021FE768
 * packet:   pkt_ov186_021FE768
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    int  f0;
    char pad8[8];
    char at_c[0x10];
    int  f1c;
} S;

void BR_FADE_Update(S *p)
{
    int (*fn)(S *, void *);

    fn = (int (*)(S *, void *))p->f1c;
    if (fn != 0) {
        p->f0 = fn(p, p->at_c);
        if (p->f0 != 0)
            p->f1c = 0;
    }
}
