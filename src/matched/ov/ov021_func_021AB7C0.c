/*
 * function: func_021AB7C0
 * address:  0x021AB7C0
 * packet:   pkt_ov021_021AB7C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB780  0x021AB780  thumb
 */

typedef void (*Fn)(int a, int b, int c);

typedef struct {
    Fn *f0;
    Fn *f4;
} S;

extern int func_021AB780(S *s, int i);

void func_021AB7C0(S *s, int i, int a, int b, int c)
{
    if (func_021AB780(s, i)) {
        s->f4[i](a, b, c);
    }
}
