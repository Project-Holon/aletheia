/*
 * function: ArrayInsertAt
 * address:  0x0218424C
 * packet:   pkt_ov009_0218424C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayInsertAt (darray.o)
 *
 * symbols:
 *   ArrayGrow  0x021840F0  arm  ov009
 *   ArrayNth   0x02184208  arm  ov009
 *   memmove    0x02092364  arm
 *   SetElement 0x02184120  arm  ov009
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
extern void ArrayGrow(struct DArrayImplementation *array);
extern void SetElement(struct DArrayImplementation *array, void *elem, int pos);

void ArrayInsertAt(struct DArrayImplementation *array, void *newElem, int n)
{
    if (array->count == array->capacity)
        ArrayGrow(array);
    array->count++;
    if (n < array->count - 1)
        memmove(ArrayNth(array, n + 1), ArrayNth(array, n),
                (array->count - 1 - n) * array->elemsize);
    SetElement(array, newElem, n);
}
