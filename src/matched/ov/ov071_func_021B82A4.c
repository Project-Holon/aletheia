/*
 * function: func_021B82A4
 * address:  0x021B82A4
 * packet:   pkt_ov071_021B82A4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6C7C  0x021B6C7C  thumb  ov071
 *   func_021B6B70  0x021B6B70  thumb  ov071
 *   d_021BA978     0x021BA978  data  a4
 */

extern unsigned d_021BA978[];

void func_021B82A4(int *a, char *p)
{
    void func_021B6C7C(void *, int);
    void func_021B6B70(int, char *);
    unsigned i;

    func_021B6C7C(a, 3);
    for (i = 0; i < d_021BA978[*(unsigned char *)(p + 0x32)]; i++) {
        func_021B6B70(a[1], p + i * 16);
    }
}
