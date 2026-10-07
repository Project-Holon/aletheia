/*
 * file:     unit_02184208_p01.c
 * unit:     yes
 * function: func_02184208, func_02184234, func_0218424C, func_021842D0, func_02184324, func_0218437C, func_0218439C
 * address:  0x02184208
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
 *   func_0218424C  0x0218424C  arm  ov009
 *   ArrayGrow  0x021840F0  arm  ov009
 *   memmove    0x02092364  arm
 *   SetElement 0x02184120  arm  ov009
 *   mybsearch      0x021845AC  arm  ov009
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021840CC  0x021840CC  arm  ov009
 *   func_02184324  0x02184324  arm  ov009
 *   FreeElement  0x021840CC  arm  ov009
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

extern void *memmove(void *dst, const void *src, unsigned long n);
extern void ArrayGrow(struct DArrayImplementation *array);
extern void SetElement(struct DArrayImplementation *array, void *elem, int pos);
extern void *mybsearch(void *elem, void *base, int num, int elemsize,
                       int (*comparator)(void *, void *), int *found);
extern void func_021840CC(int a, int b);
extern void func_02184324(int a, int b);
extern void FreeElement(struct DArrayImplementation *array, int n);
void *ArrayNth(struct DArrayImplementation *array, int n);
void func_02184234(void *p, void *a);
void ArrayInsertAt(struct DArrayImplementation *array, void *newElem, int n);
void ArrayInsertSorted(struct DArrayImplementation *array, void *newElem, int (*comparator)(void *, void *));
void ArrayRemoveAt(struct DArrayImplementation *array, int n);
void func_0218437C(int a, int b);
void ArrayReplaceAt(struct DArrayImplementation *array, void *newElem, int n);


void *ArrayNth(struct DArrayImplementation *array, int n)
{
    return (n < 0 || n >= array->count)
               ? 0
               : (char *)array->list + array->elemsize * n;
}


/*
 * Guarded forward of a word load: calls func_0218424C(p, a, *p) when p is set.
 */
void func_02184234(void *p, void *a)
{
    void func_0218424C(void *, void *, void *);
    if (p) func_0218424C(p, a, *(void **)p);
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
void func_0218437C(int a, int b)
{
    func_021840CC(a, b);
    func_02184324(a, b);
}


void ArrayReplaceAt(struct DArrayImplementation *array, void *newElem, int n)
{
    FreeElement(array, n);
    SetElement(array, newElem, n);
}
