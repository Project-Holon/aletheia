/*
 * file:     unit_02184208_p03.c
 * unit:     yes
 * function: func_021844DC, func_0218452C, func_02184558, func_021845AC
 * address:  0x021844DC
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

extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int ArrayLength(struct DArrayImplementation *array);
extern void ArrayDeleteAt(struct DArrayImplementation *array, int n);
void *ArrayMapBackwards2(struct DArrayImplementation *array, int (*fn)(void *, void *), void *clientData);
void ArrayClear(struct DArrayImplementation *array);


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
