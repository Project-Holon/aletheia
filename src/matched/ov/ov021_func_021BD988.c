/*
 * function: func_021BD988
 * address:  0x021BD988
 * packet:   pkt_ov021_021BD988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 */

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fC;
    char pad10[0x28];
    int f38;
    int f3C;
    int f40;
} Sub;

typedef struct {
    int f0;
    int f4;
    Sub *f8;
} Obj;

extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_02012374(int a, int b);

void func_021BD988(Obj *o, int b)
{
    Sub *s = o->f8;
    int sel = s->f40;
    void *p = s->f4;
    int c = s->fC;

    if (sel != 0) {
        func_02012374(b, func_021BE8D4(p, c, 0, 0));
    } else {
        func_02012374(b, func_021BE8D4(p, c, s->f38, 0));
    }
}
