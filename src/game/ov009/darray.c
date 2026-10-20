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
 *   MSL_C_LIB_MemsetPtr     0x020923B0  arm
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
#include "../types.h"
#include "darray.h"

#include "gsmemory.h"
typedef unsigned int size_t;
#include "../arm9/msl_string_mem.h"
extern void qsort(void *table_base, unsigned int num_members, unsigned int member_size, int (*compare_members)(const void *, const void *));
struct DArrayImplementation *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
void ArrayFree(struct DArrayImplementation *array);
int ArrayLength(struct DArrayImplementation *array);
void *ArrayNth(struct DArrayImplementation *array, int n);
void ArrayAppend(struct DArrayImplementation *array, void *newElem);
void ArrayInsertAt(struct DArrayImplementation *array, void *newElem, int n);
void ArrayInsertSorted(struct DArrayImplementation *array, void *newElem, int (*comparator)(void *, void *));
void ArrayRemoveAt(struct DArrayImplementation *array, int n);
void ArrayDeleteAt(struct DArrayImplementation *array, int n);
void ArrayReplaceAt(struct DArrayImplementation *array, void *newElem, int n);
void ArraySort(struct DArrayImplementation *array, int (*comparator)(const void *, const void *));
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
        MSL_C_LIB_MemsetPtr(array->list, 0, array->capacity * array->elemsize);
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

int ArrayLength(struct DArrayImplementation *array)
{
    return array->count;
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
void ArrayAppend(struct DArrayImplementation *array, void *newElem)
{
    if (array) ArrayInsertAt(array, newElem, array->count);
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
void ArrayDeleteAt(struct DArrayImplementation *array, int n)
{
    FreeElement(array, n);
    ArrayRemoveAt(array, n);
}

void ArrayReplaceAt(struct DArrayImplementation *array, void *newElem, int n)
{
    FreeElement(array, n);
    SetElement(array, newElem, n);
}

/*
 * Tail call on three fields of the object and the second argument.
 */
void ArraySort(struct DArrayImplementation *array, int (*comparator)(const void *, const void *))
{
    qsort(array->list, array->count, array->elemsize, comparator);
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

    for (i = ArrayLength(array) - 1; i >= 0; i--)
        ArrayDeleteAt(array, i);
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
