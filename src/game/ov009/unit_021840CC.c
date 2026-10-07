/*
 * file:     unit_021840CC.c
 * unit:     yes
 * function: func_021840CC, func_021840F0, func_02184120, func_02184144, func_021841B0
 * address:  0x021840CC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ArrayNth  0x02184208  arm  ov009
 *   gsirealloc  0x0217EAC8  arm  ov009
 *   memcpy    0x02092344  arm
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   memset     0x020923B0  arm
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

extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern void *gsirealloc(void *ptr, unsigned long size);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern void *gsimalloc(unsigned long size);
extern void *memset(void *dst, int c, unsigned long n);
extern void gsifree(void *ptr);
struct DArrayImplementation *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
void ArrayFree(struct DArrayImplementation *array);


static void FreeElement(struct DArrayImplementation *array, int n)
{
    if (array->elemfreefn == 0)
        return;
    array->elemfreefn(ArrayNth(array, n));
}


static void ArrayGrow(struct DArrayImplementation *array)
{
    array->capacity += array->growby;
    array->list = gsirealloc(array->list, array->capacity * array->elemsize);
}


static void SetElement(struct DArrayImplementation *array, void *elem, int pos)
{
    memcpy(ArrayNth(array, pos), elem, array->elemsize);
}


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


void ArrayFree(struct DArrayImplementation *array)
{
    int i;

    for (i = 0; i < array->count; i++)
        FreeElement(array, i);
    if (array->list != 0)
        gsifree(array->list);
    gsifree(array);
}
