/*
 * file:     unit_02184208_p02.c
 * unit:     yes
 * function: func_021843C8, func_021843E8, func_021844A0
 * address:  0x021843C8
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
 *   ArrayNth     0x02184208  arm  ov009
 *   mybsearch    0x021845AC  arm  ov009
 *   mylsearch    0x02184558  arm  ov009
 *   _s32_div_f   0x0209C0A4  arm
 */
struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

extern void func_0209455C(int a, int b, int c, int d);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern void *mybsearch(void *elem, void *base, int num, int elemsize,
                       int (*comparator)(void *, void *), int *found);
extern void *mylsearch(void *key, void *base, int count, int size,
                       int (*comparator)(void *, void *));
extern int _s32_div_f(int a, int b);
void func_021843C8(int *p, int b);
int ArraySearch(struct DArrayImplementation *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
void ArrayMapBackwards(struct DArrayImplementation *array, void (*fn)(void *, void *), void *clientData);


/*
 * Tail call on three fields of the object and the second argument.
 */
void func_021843C8(int *p, int b)
{
    func_0209455C(p[5], p[0], p[2], b);
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
