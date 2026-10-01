/*
 * function: func_021BD554
 * address:  0x021BD554
 * packet:   pkt_ov021_021BD554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD484  0x021BD484  thumb  ov021
 */

typedef struct {
    int x, y;
} V2;

typedef struct {
    int a, b, c, d, e, f;
    V2 g;
} Src;

typedef struct {
    char pad[0x10];
    int a, b, c, d;
    char pad2[8];
    int e, f;
    V2 g;
} Obj;

extern void func_021BD484(Obj *p);

void func_021BD554(Obj *p, Src *s)
{
    p->a = s->a;
    p->b = s->b;
    p->c = s->c;
    p->d = s->d;
    p->e = s->e;
    p->f = s->f;
    p->g = s->g;
    func_021BD484(p);
}
