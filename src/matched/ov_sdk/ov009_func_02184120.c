/*
 * function: SetElement
 * address:  0x02184120
 * packet:   pkt_ov009_02184120
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SetElement (darray.o)
 *
 * symbols:
 *   ArrayNth  0x02184208  arm  ov009
 *   memcpy    0x02092344  arm
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
extern void *memcpy(void *dst, const void *src, unsigned long n);

static void SetElement(struct DArrayImplementation *array, void *elem, int pos)
{
    memcpy(ArrayNth(array, pos), elem, array->elemsize);
}
