/*
 * function: ArrayRemoveAt
 * address:  0x02184324
 * packet:   pkt_ov009_02184324
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayRemoveAt (darray.o)
 *
 * symbols:
 *   ArrayNth  0x02184208  arm  ov009
 *   memmove   0x02092364  arm
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
extern void *memmove(void *dst, const void *src, unsigned long n);

void ArrayRemoveAt(struct DArrayImplementation *array, int n)
{
    if (n < array->count - 1)
        memmove(ArrayNth(array, n), ArrayNth(array, n + 1),
                (array->count - 1 - n) * array->elemsize);
    array->count--;
}
