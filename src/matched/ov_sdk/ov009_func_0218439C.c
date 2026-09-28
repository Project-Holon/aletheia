/*
 * function: ArrayReplaceAt
 * address:  0x0218439C
 * packet:   pkt_ov009_0218439C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ArrayReplaceAt (darray.o)
 *
 * symbols:
 *   FreeElement  0x021840CC  arm  ov009
 *   SetElement   0x02184120  arm  ov009
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
extern void SetElement(struct DArrayImplementation *array, void *elem, int pos);

void ArrayReplaceAt(struct DArrayImplementation *array, void *newElem, int n)
{
    FreeElement(array, n);
    SetElement(array, newElem, n);
}
