/*
 * function: FreeElement
 * address:  0x021840CC
 * packet:   pkt_ov009_021840CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FreeElement (darray.o)
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

static void FreeElement(struct DArrayImplementation *array, int n)
{
    if (array->elemfreefn == 0)
        return;
    array->elemfreefn(ArrayNth(array, n));
}
