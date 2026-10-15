/*
 * function: ghiPostDataFree
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
 *   gsifree  0x0217EAE0  arm
 *   gsXmlFreeWriter  0x02181D84  arm
 */

typedef struct Obj {
    int type;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} Obj;

extern void gsifree(void *);
extern void gsXmlFreeWriter(void *);

void ghiPostDataFree(Obj *o)
{
    if (o->type != 3)
        gsifree(o->p4);
    if (o->type == 0) {
        gsifree(o->p8);
    } else if (o->type == 1) {
        gsifree(o->p8);
        gsifree(o->pC);
        gsifree(o->p10);
    } else if (o->type == 2) {
        gsifree(o->p10);
        gsifree(o->p14);
    } else if (o->type == 3) {
        gsXmlFreeWriter(o->p8);
    }
}
