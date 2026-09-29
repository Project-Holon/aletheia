/*
 * function: func_021CD60C
 * address:  0x021CD60C
 * packet:   pkt_ov021_021CD60C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

typedef struct {
    u8 pad000[0x488];
    void *f488;
    void *f48c;
    void *f490;
} Obj;

void func_021CD60C(Obj *p, void *a, void *b, void *c)
{
    p->f488 = a;
    p->f48c = b;
    p->f490 = c;
}
