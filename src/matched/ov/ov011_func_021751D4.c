/*
 * function: func_021751D4
 * address:  0x021751D4
 * packet:   pkt_ov011_021751D4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02175144  0x02175144  thumb ov011
 *   func_02175184  0x02175184  thumb ov011
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021751A8  0x021751A8  thumb ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    int f0;
    int f4;
    u8 pad8[0xc];
    u16 f14;
    u16 a : 3;
    u16 rest : 13;
} Ent;

int func_02175144(u16 v, u8 *out);
int func_02175184(u8 *a, u8 *b);
typedef unsigned int   u32;
u32 func_02013D5C(u32 id);
int func_021751A8(u8 *p, int a);

void func_021751D4(u8 *p, u16 a, int b, Ent *c)
{
    u8 x[4];
    u8 y[4];
    int r;
    int w;
    int k;
    int n;

    func_02175144(a, x);
    func_02175144(c->f14, y);
    r = func_02175184(x, y);
    switch (r) {
    case 1:
        break;
    case 2:
        break;
    case 0:
        if (func_02013D5C(a) != 0) {
            w = c->f4 % 0x400000;
            k = func_021751A8(p, c->a);
            n = p[0x902];
            if (k == n - 1 && w > 0x200000 && b < 0x200000) {
                c->f4 = w - 0x400000;
            } else if (k == 0 && w < 0x200000 && b > (n << 22) - 0x200000) {
                c->f4 = w + (n << 22);
            } else {
                c->f4 = w + (k << 22);
            }
        }
        break;
    }
}
