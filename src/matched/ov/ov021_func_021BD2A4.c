/*
 * function: func_021BD2A4
 * address:  0x021BD2A4
 * packet:   pkt_ov021_021BD2A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[0xC];
    void *fC;
} Obj;

struct Grid;
extern void func_0202570C(struct Grid *g);

void func_021BD2A4(Obj *p)
{
    if (p->fC != 0) {
        func_0202570C(p->fC);
        p->fC = 0;
    }
}
