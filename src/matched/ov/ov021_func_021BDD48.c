/*
 * function: func_021BDD48
 * address:  0x021BDD48
 * packet:   pkt_ov021_021BDD48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: true when the object's f08 is null.
 */

typedef struct Obj {
    int f00;
    int f04;
    void *f08;
} Obj;

int func_021BDD48(Obj *o)
{
    if (o->f08 == 0) {
        return 1;
    }
    return 0;
}
