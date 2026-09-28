/*
 * function: ArrayFree
 * address:  0x021841B0
 * packet:   pkt_ov009_021841B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayFree (darray.o)
 *
 * symbols:
 *   FreeElement  0x021840CC  arm  ov009
 *   gsifree      0x0217EAE0  arm  ov009
 */

struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

extern void FreeElement(struct DArrayImplementation *array, int n);
extern void gsifree(void *ptr);

void ArrayFree(struct DArrayImplementation *array)
{
    int i;

    for (i = 0; i < array->count; i++)
        FreeElement(array, i);
    if (array->list != 0)
        gsifree(array->list);
    gsifree(array);
}
