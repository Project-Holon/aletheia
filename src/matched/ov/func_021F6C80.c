/*
 * function: func_021F6C80
 * address:  0x021F6C80
 * packet:   pkt_021F6C80
 * region:   ov135
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_021F6C80(void *pa, void *pb)
{
    signed char a3;
    signed char b3;
    signed char b4;
    signed char b2;

    if (*(short *)pa != *(short *)pb)
        return 0;
    b2 = *(signed char *)((char *)pb + 2);
    if (b2 != 3 && b2 != *(signed char *)((char *)pa + 2))
        return 0;
    a3 = *(signed char *)((char *)pa + 3);
    if (a3 == 0)
        return 0;
    b3 = *(signed char *)((char *)pb + 3);
    if (b3 != 0 && b3 > a3)
        return 0;
    b4 = *(signed char *)((char *)pb + 4);
    if (b4 != 0 && b4 < a3)
        return 0;
    return 1;
}
