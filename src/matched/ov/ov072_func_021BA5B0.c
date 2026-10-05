/*
 * function: func_021BA5B0
 * address:  0x021BA5B0
 * packet:   pkt_ov072_021BA5B0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA638  0x021BA638  thumb  ov072
 *   func_021BAD10  0x021BAD10  thumb  ov072
 *   func_021BAD84  0x021BAD84  thumb  ov072
 *   func_021BAF3C  0x021BAF3C  thumb  ov072
 *   d_021BBB78     0x021BBB78  data  ov072
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    int f4;
    char *f8;
    u32 fC;
    int f10;
    int f14;
    short f18;
    short f1A;
    u16 f1C;
    u16 f1E;
} W;

extern char d_021BBB78[];
extern void func_021BA638(W *p, int *v);
extern void func_021BAD10(char *p, int s, char *r);
extern void func_021BAD84(char *p, int *b);
extern void func_021BAF3C(char *p, int *b);

void func_021BA5B0(W *p, u32 s, const int *v)
{
    u32 i;
    int t[2];

    if (s == 0x1000) {
        p->f18 = 0;
        p->f1A = 0;
        p->f1C = 0;
        p->f1E = 0;
    } else {
        p->f18 = -0x48;
        p->f1A = -0x80;
        p->f1C = 0x80;
        p->f1E = 0x60;
    }
    t[0] = -v[0];
    t[1] = -v[1];
    func_021BA638(p, t);
    for (i = 0; i < p->fC; i++) {
        func_021BAD10(p->f8 + i * 0x44, s, d_021BBB78);
        func_021BAD84(p->f8 + i * 0x44, &p->f10);
    }
    func_021BAF3C((char *)p + 0x20, (int *)&p->f10);
}
