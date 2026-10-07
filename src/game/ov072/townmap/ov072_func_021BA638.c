/*
 * function: func_021BA638
 * address:  0x021BA638
 * packet:   pkt_ov072_021BA638
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BAD84  0x021BAD84  thumb  ov072
 *   func_021BAF3C  0x021BAF3C  thumb  ov072
 */

typedef short s16;
typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    char *f8;
    u32 fc;
    int f10;
    int f14;
    s16 f18;
    s16 f1a;
    s16 f1c;
    s16 f1e;
} W;

extern void func_021BAD84(int *p, int *b);
extern void func_021BAF3C(u32 *p, const u32 *v);

void func_021BA638(W *p, int *in)
{
    u32 i;
    int x;
    int y;

    x = p->f1c;
    if (in[0] <= x) {
        x = p->f1a;
        if (in[0] >= x) {
            x = in[0];
        }
    }
    p->f10 = x;
    y = p->f1e;
    if (in[1] <= y) {
        y = p->f18;
        if (in[1] >= y) {
            y = in[1];
        }
    }
    p->f14 = y;
    for (i = 0; i < p->fc; i++) {
        func_021BAD84((int *)(p->f8 + i * 0x44), &p->f10);
    }
    func_021BAF3C((u32 *)((char *)p + 0x20), (const u32 *)(&p->f10));
}
