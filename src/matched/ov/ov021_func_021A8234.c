/*
 * function: func_021A8234
 * address:  0x021A8234
 * packet:   pkt_ov021_021A8234
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218C860  0x0218C860  thumb
 */

typedef struct {
    int pad[10];
    int f28;
} S;

extern void func_0218C860(int a);

void func_021A8234(S *s)
{
    if (s->f28 != 0) {
        func_0218C860(s->f28);
    }
}
