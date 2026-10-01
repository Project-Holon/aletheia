/*
 * function: func_0218B53C
 * address:  0x0218B53C
 * packet:   pkt_ov021_0218B53C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219E634  0x0219E634  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0219E570  0x0219E570  thumb  ov021
 */

int func_021A3074(int a);
int func_0219E634(int a, int *buf);
int func_02188C7C(int b);
int func_0219E570(int a, int *buf, int c);

int func_0218B53C(unsigned char *p, int b)
{
    int buf[2];
    if (func_0219E634(func_021A3074(*(int *)(p + 0x18)), buf) != 0)
        return func_0219E570(func_02188C7C(b), buf, 0);
    return 0;
}
