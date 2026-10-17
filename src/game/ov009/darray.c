/*
 * file:     darray.c
 * unit:     yes
 * function: FreeElement, ArrayGrow, SetElement, ArrayNew, ArrayFree, ArrayLength, ArrayNth, ArrayAppend, ArrayInsertAt, ArrayInsertSorted, ArrayRemoveAt, ArrayDeleteAt, ArrayReplaceAt, ArraySort, ArraySearch, ArrayMapBackwards, ArrayMapBackwards2, ArrayClear, mylsearch, mybsearch
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
 * Returns the first word of the dynamic array header (its element count).
 *
 * symbols:
 *   gsirealloc  0x0217EAC8  arm  ov009
 *   memcpy    0x02092344  arm
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   memset     0x020923B0  arm
 *   gsifree      0x0217EAE0  arm  ov009
 *   ArrayInsertAt  0x0218424C  arm  ov009
 *   memmove    0x02092364  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   FreeElement  0x021840CC  arm  ov009
 *   ArrayRemoveAt  0x02184324  arm  ov009
 *   ArrayLength   0x02184200  arm  ov009
 *   ArrayDeleteAt 0x0218437C  arm  ov009
 *   qsort  0x0209455C  arm  arm9
 */
struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *gsirealloc(void *ptr, unsigned long size);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern void *gsimalloc(unsigned long size);
extern void *memset(void *dst, int c, unsigned long n);
extern void gsifree(void *ptr);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern void qsort(int a, int b, int c, int d);
extern int _s32_div_f(int a, int b);
struct DArrayImplementation *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
void ArrayFree(struct DArrayImplementation *array);
int ArrayLength(const int *array);
void *ArrayNth(struct DArrayImplementation *array, int n);
void ArrayAppend(void *p, void *a);
void ArrayInsertAt(struct DArrayImplementation *array, void *newElem, int n);
void ArrayInsertSorted(struct DArrayImplementation *array, void *newElem, int (*comparator)(void *, void *));
void ArrayRemoveAt(struct DArrayImplementation *array, int n);
void ArrayDeleteAt(int a, int b);
void ArrayReplaceAt(struct DArrayImplementation *array, void *newElem, int n);
void ArraySort(int *p, int b);
int ArraySearch(struct DArrayImplementation *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
void ArrayMapBackwards(struct DArrayImplementation *array, void (*fn)(void *, void *), void *clientData);
void *ArrayMapBackwards2(struct DArrayImplementation *array, int (*fn)(void *, void *), void *clientData);
void ArrayClear(struct DArrayImplementation *array);



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

int ArrayLength(const int *array)
{
    return *array;
}


static void *mybsearch(void *elem, void *base, int num, int elemsize,
                       int (*comparator)(void *, void *), int *found);


static void *mylsearch(void *key, void *base, int count, int size,
                       int (*comparator)(void *, void *));





void *ArrayNth(struct DArrayImplementation *array, int n)
{
    return (n < 0 || n >= array->count)
               ? 0
               : (char *)array->list + array->elemsize * n;
}





/*
 * Guarded forward of a word load: calls ArrayInsertAt(p, a, *p) when p is set.
 */
void ArrayAppend(void *p, void *a)
{
    if (p) ArrayInsertAt(p, a, (int)*(void **)p);
}





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





void ArrayRemoveAt(struct DArrayImplementation *array, int n)
{
    if (n < array->count - 1)
        memmove(ArrayNth(array, n), ArrayNth(array, n + 1),
                (array->count - 1 - n) * array->elemsize);
    array->count--;
}





/*
 * Calls the two helpers on both arguments.
 */
void ArrayDeleteAt(int a, int b)
{
    FreeElement((struct DArrayImplementation *)a, b);
    ArrayRemoveAt((struct DArrayImplementation *)a, b);
}





void ArrayReplaceAt(struct DArrayImplementation *array, void *newElem, int n)
{
    FreeElement(array, n);
    SetElement(array, newElem, n);
}





/*
 * Tail call on three fields of the object and the second argument.
 */
void ArraySort(int *p, int b)
{
    qsort(p[5], p[0], p[2], b);
}





int ArraySearch(struct DArrayImplementation *array, void *key,
                int (*comparator)(void *, void *), int fromIndex, int isSorted)
{
    int found = 1;
    void *res;

    if (array == 0 || array->count == 0)
        return -1;
    if (isSorted)
        res = mybsearch(key, ArrayNth(array, fromIndex),
                        array->count - fromIndex, array->elemsize, comparator,
                        &found);
    else
        res = mylsearch(key, ArrayNth(array, fromIndex),
                        array->count - fromIndex, array->elemsize, comparator);
    if (res == 0 || found == 0)
        return -1;
    return ((char *)res - (char *)array->list) / array->elemsize;
}





void ArrayMapBackwards(struct DArrayImplementation *array,
                       void (*fn)(void *, void *), void *clientData)
{
    int i;

    for (i = array->count - 1; i >= 0; i--)
        fn(ArrayNth(array, i), clientData);
}




void *ArrayMapBackwards2(struct DArrayImplementation *array,
                         int (*fn)(void *, void *), void *clientData)
{
    void *pcurr;
    int i;

    for (i = array->count - 1; i >= 0; i--)
    {
        pcurr = ArrayNth(array, i);
        if (fn(pcurr, clientData) == 0)
            return pcurr;
    }
    return 0;
}




void ArrayClear(struct DArrayImplementation *array)
{
    int i;

    for (i = ArrayLength((const int *)array) - 1; i >= 0; i--)
        ArrayDeleteAt((int)array, i);
}



static void *mylsearch(void *key, void *base, int count, int size,
                       int (*comparator)(void *, void *))
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (comparator(key, (char *)base + size * i) == 0)
            return (char *)base + size * i;
    }
    return 0;
}



static void *mybsearch(void *elem, void *base, int num, int elemsize,
                       int (*comparator)(void *, void *), int *found)
{
    int L = 0;
    int H = num - 1;
    int I;
    int C;

    *found = 0;
    while (L <= H)
    {
        I = (L + H) >> 1;
        C = comparator((char *)base + I * elemsize, elem);
        if (C == 0)
            *found = 1;
        if (C < 0)
            L = I + 1;
        else
            H = I - 1;
    }
    return (char *)base + L * elemsize;
}
