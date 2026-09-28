/*
 * function: ArrayClear
 * address:  0x0218452C
 * packet:   pkt_ov009_0218452C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayClear (darray.o)
 *
 * symbols:
 *   ArrayLength   0x02184200  arm  ov009
 *   ArrayDeleteAt 0x0218437C  arm  ov009
 */

struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

extern int ArrayLength(struct DArrayImplementation *array);
extern void ArrayDeleteAt(struct DArrayImplementation *array, int n);

void ArrayClear(struct DArrayImplementation *array)
{
    int i;

    for (i = ArrayLength(array) - 1; i >= 0; i--)
        ArrayDeleteAt(array, i);
}
