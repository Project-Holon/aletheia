/*
 * function: func_021C235C
 * address:  0x021C235C
 * packet:   pkt_ov114_021C235C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm
 *   func_02181D84  0x02181D84  arm
 */

typedef struct Obj {
    int type;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} Obj;

extern void func_0217EAE0(void *);
extern void func_02181D84(void *);

void func_021C235C(Obj *o)
{
    if (o->type != 3)
        func_0217EAE0(o->p4);
    if (o->type == 0) {
        func_0217EAE0(o->p8);
    } else if (o->type == 1) {
        func_0217EAE0(o->p8);
        func_0217EAE0(o->pC);
        func_0217EAE0(o->p10);
    } else if (o->type == 2) {
        func_0217EAE0(o->p10);
        func_0217EAE0(o->p14);
    } else if (o->type == 3) {
        func_02181D84(o->p8);
    }
}
