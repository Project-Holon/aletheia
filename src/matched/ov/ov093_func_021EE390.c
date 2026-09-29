/*
 * function: func_021EE390
 * address:  0x021EE390
 * packet:   pkt_ov093_021EE390
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned char u8;

struct O {
    u8 pad00[0xe0];
    int (*fe0)(void *, void *);
    int (*fe4)(void *, void *);
    void *fe8;
    int fec;
};

int func_021EE390(struct O *o)
{
    if (o->fe0 != 0) {
        if (o->fe0(&o->fec, o->fe8) != 0) {
            o->fe0 = 0;
            o->fec = 0;
        }
        return 0;
    }
    if (o->fe4 != 0) {
        if (o->fe4(&o->fec, o->fe8) != 0) {
            o->fe4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}
