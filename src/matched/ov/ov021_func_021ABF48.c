/*
 * function: func_021ABF48
 * address:  0x021ABF48
 * packet:   pkt_ov021_021ABF48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D8F60  0x021D8F60  data  a4
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
} E;

typedef struct T T;

typedef struct {
    int id;
    int (*f4)(T *t, u16 h);
    void (*f8)(T *t, int v);
} D;

struct T {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E *f10;
};

extern D d_021D8F60[];

D *func_021ABF48(int id)
{
    int i;
    D *d = d_021D8F60;
    for (i = 0; i < 0x18; i++) {
        if (d->id == id) {
            return d;
        }
        d++;
    }
    return d;
}
