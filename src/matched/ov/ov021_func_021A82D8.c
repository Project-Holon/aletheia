/*
 * function: func_021A82D8
 * address:  0x021A82D8
 * packet:   pkt_ov021_021A82D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char u8;

typedef struct Src {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    u8 pad10[0x3C - 0x10];
    int f3C;
    int f40;
    u8 f44;
    u8 f45;
} Src;

extern void *func_021BE92C(void *a, void *b, int c, int d, int e, int f, int g);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);

void func_021A82D8(void *a, Src **pp)
{
    Src *s;
    void *r;

    s = *pp;
    if (s->f40 != 0) {
        r = func_021BE92C(s->f04, s->f0C, 3, 0, 0, s->f44, s->f45);
    } else {
        r = func_021BE92C(s->f04, s->f0C, s->f3C, 0, 1, 0, 0);
    }
    func_02012374(a, r);
}
