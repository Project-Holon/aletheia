/*
 * unit:     yes
 * function: func_021EE318, func_021EE370
 * address:  0x021EE318
 * packet:   pkt_ov093_021EE318
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE544  0x021EE544  thumb  ov093
 */

typedef unsigned char u8;

struct O {
    u8 pad00[0xe0];
    int (*fe0)(void *, void *);
    int (*fe4)(void *, void *);
    void *fe8;
    int fec;
};

extern int func_021EE544(void *a, void *b);

int func_021EE318(struct O *o)
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

void func_021EE370(struct O *o)
{
    o->fe0 = 0;
    o->fe4 = func_021EE544;
    o->fe8 = o;
    o->fec = 0;
}
