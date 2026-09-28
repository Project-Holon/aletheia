/*
 * function: func_021EB988
 * address:  0x021EB988
 * packet:   pkt_ov170_021EB988
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202CFC0 0x0202CFC0 thumb
 *   func_021EB6D8 0x021EB6D8 thumb
 *   func_0202CE50 0x0202CE50 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021EAAE4 0x021EAAE4 thumb
 */

typedef struct {
    unsigned short a;
    unsigned short b;
} Ent;

extern void func_0202CFC0(int mgr, unsigned idx, unsigned short *w, unsigned short *h);
extern void func_021EB6D8(char *p, int b, int c, int d);
extern void func_0202CE50(int mgr, unsigned idx, int x, int y, unsigned char w, unsigned char h, unsigned char pal);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *a, unsigned b);
extern void func_021EAAE4(char *w, unsigned i);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(int *)(WORK(p) + 0x74))

void func_021EB988(char *p, Ent *e, unsigned n)
{
    unsigned short w;
    unsigned short h;
    unsigned i = 0;
    func_0202CFC0(MGR(p), 0, &w, &h);
    for (i = 0; i < n; i++) {
        Ent *x = &e[n - 1 - i];
        if (x->b == 0)
            func_021EB6D8(p, 0x13 - i, x->a, 0);
        else
            func_021EB6D8(p, 0x13 - i, x->a, 1);
        func_0202CE50(MGR(p), 5 - i, 0, 0, w, h, 0xC);
    }
    for (; n < 6; n++) {
        unsigned k = 0x13 - n;
        func_02043B5C(func_02045770(*(void **)(WORK(p) + k * 8 + 0x94)), 0);
        func_021EAAE4(WORK(p), k);
    }
}
