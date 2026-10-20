#ifndef GAME_OV009_DARRAY_H
#define GAME_OV009_DARRAY_H

struct DArrayImplementation {
    int count;
    int capacity;
    int elemsize;
    int growby;
    void (*elemfreefn)(void *);
    void *list;
};

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of darray.c, prototypes copied from their definitions. */

struct DArrayImplementation;

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
/* END mkheaders: generated region */

#endif
