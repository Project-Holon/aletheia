/*
 * function: ArrayNth
 * address:  0x02184208
 * packet:   pkt_ov009_02184208
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayNth (darray.o)
 */

struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

void *ArrayNth(struct DArrayImplementation *array, int n)
{
    return (n < 0 || n >= array->count)
               ? 0
               : (char *)array->list + array->elemsize * n;
}
