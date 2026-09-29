/*
 * function: func_021B7BFC
 * address:  0x021B7BFC
 * packet:   pkt_ov071_021B7BFC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6B58  0x021B6B58  thumb  ov071
 */

void func_021B7BFC(int *a, char *p, unsigned char m)
{
    void func_021B6B58(void *, int);

    if (m == 0) {
        func_021B6B58(p + 0x2c, 1);
        func_021B6B58(p + 0x3c, 0);
    } else {
        *(unsigned char *)a[2] = 6;
        func_021B6B58(p + 0x2c, 0);
        func_021B6B58(p + 0x3c, 1);
    }
    *(unsigned char *)(p + 0x82) = m;
}
