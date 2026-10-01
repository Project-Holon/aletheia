/*
 * function: func_021ABE30
 * address:  0x021ABE30
 * packet:   pkt_ov021_021ABE30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ABF2C  0x021ABF2C  thumb
 *   func_021ABF48  0x021ABF48  thumb
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

extern E *func_021ABF2C(T *t, int id);
extern D *func_021ABF48(int id);

void func_021ABE30(T *t, int *arr, int n)
{
    E *e;
    D *d;
    for (; n != 0; n--) {
        e = func_021ABF2C(t, 0x18);
        d = func_021ABF48(*arr);
        e->f0 = *arr;
        e->f4 = d->f4(t, t->h4);
        arr++;
    }
}
