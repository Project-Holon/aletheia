/*
 * function: func_021A8214
 * address:  0x021A8214
 * packet:   pkt_ov021_021A8214
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb
 *   func_0218DC6C  0x0218DC6C  thumb
 *   func_0218C7D8  0x0218C7D8  thumb
 */

typedef struct {
    int pad[3];
    int fc;
} R;

typedef struct {
    R *f0;
    int pad[6];
    int f1c[3];
    int f28;
} S;

extern int func_02188C98(int a);
extern int func_0218DC6C(int a);
extern int func_0218C7D8(int a, int b, int *c);

void func_021A8214(S *s)
{
    s->f28 = func_0218C7D8(func_0218DC6C(func_02188C98(s->f0->fc)), 1, s->f1c);
}
