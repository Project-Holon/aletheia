/*
 * function: ArrayGrow
 * address:  0x021840F0
 * packet:   pkt_ov009_021840F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayGrow (darray.o)
 *
 * symbols:
 *   gsirealloc  0x0217EAC8  arm  ov009
 */

struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

extern void *gsirealloc(void *ptr, unsigned long size);

static void ArrayGrow(struct DArrayImplementation *array)
{
    array->capacity += array->growby;
    array->list = gsirealloc(array->list, array->capacity * array->elemsize);
}
