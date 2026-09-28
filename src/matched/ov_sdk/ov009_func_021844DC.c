/*
 * function: ArrayMapBackwards2
 * address:  0x021844DC
 * packet:   pkt_ov009_021844DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayMapBackwards2 (darray.o)
 *
 * symbols:
 *   ArrayNth  0x02184208  arm  ov009
 */

struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

extern void *ArrayNth(struct DArrayImplementation *array, int n);

void *ArrayMapBackwards2(struct DArrayImplementation *array,
                         int (*fn)(void *, void *), void *clientData)
{
    void *pcurr;
    int i;

    for (i = array->count - 1; i >= 0; i--)
    {
        pcurr = ArrayNth(array, i);
        if (fn(pcurr, clientData) == 0)
            return pcurr;
    }
    return 0;
}
