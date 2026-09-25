/*
 * function: func_021B7448
 * address:  0x021B7448
 * packet:   pkt_021B7448
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 */

extern int func_02017E1C(int, int, int);

unsigned short func_021B7448(int *p)
{
    int *q = *(int **)p;

    return func_02017E1C(*(int *)q, *(unsigned char *)((char *)q + 0x1b) + 0x36, 0);
}
