/*
 * function: ArrayInsertSorted
 * address:  0x021842D0
 * packet:   pkt_ov009_021842D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayInsertSorted (darray.o)
 *
 * symbols:
 *   ArrayInsertAt  0x0218424C  arm  ov009
 *   mybsearch      0x021845AC  arm  ov009
 *   _s32_div_f     0x0209C0A4  arm
 */

struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

extern void ArrayInsertAt(struct DArrayImplementation *array, void *newElem,
                          int n);
extern void *mybsearch(void *elem, void *base, int num, int elemsize,
                       int (*comparator)(void *, void *), int *found);

void ArrayInsertSorted(struct DArrayImplementation *array, void *newElem,
                       int (*comparator)(void *, void *))
{
    int found;
    void *res;

    res = mybsearch(newElem, array->list, array->count, array->elemsize,
                    comparator, &found);
    ArrayInsertAt(array, newElem,
                  ((char *)res - (char *)array->list) / array->elemsize);
}
