/*
 * function: mylsearch
 * address:  0x02184558
 * packet:   pkt_ov009_02184558
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      mylsearch (darray.o)
 */

static void *mylsearch(void *key, void *base, int count, int size,
                       int (*comparator)(void *, void *))
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (comparator(key, (char *)base + size * i) == 0)
            return (char *)base + size * i;
    }
    return 0;
}
