/*
 * function: func_021B61FC
 * address:  0x021B61FC
 * packet:   pkt_ov090_021B61FC
 * region:   ov090
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 */

extern int func_020399A8(int, int);
extern int func_02039CB4(int, int, int);

int func_021B61FC(int a, int b)
{
    if (func_02039CB4(func_020399A8(a, b), b, 0x2d) == 1)
        return 1;
    if (*(unsigned char *)(a + 0x63) == 1)
        return 1;
    return 0;
}
