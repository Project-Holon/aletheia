/*
 * function: func_021ABF2C
 * address:  0x021ABF2C
 * packet:   pkt_ov021_021ABF2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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

E *func_021ABF2C(T *t, int id)
{
    int n = t->f0;
    E *e = t->f10;
    while (n != 0) {
        if (e->f0 == id) {
            return e;
        }
        n--;
        e++;
    }
    return 0;
}
