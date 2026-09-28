/*
 * function: ArrayNew
 * address:  0x02184144
 * packet:   pkt_ov009_02184144
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayNew (darray.o)
 *
 * symbols:
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   memset     0x020923B0  arm
 */

struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

extern void *gsimalloc(unsigned long size);
extern void *memset(void *dst, int c, unsigned long n);

struct DArrayImplementation *ArrayNew(int elemSize, int numElemsToAllocate,
                                      void (*elemFreeFn)(void *))
{
    struct DArrayImplementation *array;

    array = gsimalloc(sizeof(struct DArrayImplementation));
    if (numElemsToAllocate == 0)
        numElemsToAllocate = 8;
    array->count = 0;
    array->capacity = numElemsToAllocate;
    array->elemsize = elemSize;
    array->growby = numElemsToAllocate;
    array->elemfreefn = elemFreeFn;
    if (numElemsToAllocate == 0)
        array->list = 0;
    else
    {
        array->list = gsimalloc(numElemsToAllocate * array->elemsize);
        memset(array->list, 0, array->capacity * array->elemsize);
    }
    return array;
}
