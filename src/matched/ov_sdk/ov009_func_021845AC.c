/*
 * function: mybsearch
 * address:  0x021845AC
 * packet:   pkt_ov009_021845AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      mybsearch (darray.o)
 */

static void *mybsearch(void *elem, void *base, int num, int elemsize,
                       int (*comparator)(void *, void *), int *found)
{
    int L = 0;
    int H = num - 1;
    int I;
    int C;

    *found = 0;
    while (L <= H)
    {
        I = (L + H) >> 1;
        C = comparator((char *)base + I * elemsize, elem);
        if (C == 0)
            *found = 1;
        if (C < 0)
            L = I + 1;
        else
            H = I - 1;
    }
    return (char *)base + L * elemsize;
}
