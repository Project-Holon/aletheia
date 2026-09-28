/*
 * function: ArrayMapBackwards
 * address:  0x021844A0
 * packet:   pkt_ov009_021844A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayMapBackwards (darray.o)
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

void ArrayMapBackwards(struct DArrayImplementation *array,
                       void (*fn)(void *, void *), void *clientData)
{
    int i;

    for (i = array->count - 1; i >= 0; i--)
        fn(ArrayNth(array, i), clientData);
}
