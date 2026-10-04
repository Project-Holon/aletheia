/*
 * function: func_021B7A68
 * address:  0x021B7A68
 * packet:   pkt_ov071_021B7A68
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6F40  0x021B6F40  thumb  ov071
 *   func_021B6F54  0x021B6F54  thumb  ov071
 *   d_021BAA4C     0x021BAA4C  data  a4
 *   d_021BA8A0     0x021BA8A0  data  a4
 */

extern const unsigned d_021BAA4C[];
extern const char d_021BA8A0[];

typedef struct {
    int pad[3];
    int v[6];
} S;

typedef unsigned char  u8;
struct P;
void func_021B7A68(S *a, int *b)
{
    void *func_021B6F40(u8 **p);
    int func_021B6F54(struct P *p, u8 *q, int c, const int *d, int e);
    int i;
    int t = (int)func_021B6F40((u8 **)b);

    for (i = 0; i < 6; i++) {
        int r;
        unsigned u = d_021BAA4C[i];
        r = func_021B6F54((struct P *)b[1], (u8 *)t, i, (const int *)(d_021BA8A0 + u * 8), 1);
        a->v[i] = r;
    }
}
