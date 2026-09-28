/*
 * function: TableNew2
 * address:  0x02184638
 * packet:   pkt_ov009_02184638
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableNew2 (hashtable.o)
 *
 * symbols:
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   ArrayNew   0x02184144  arm  ov009
 */

struct DArrayImplementation;

struct HashImplementation {
    struct DArrayImplementation **buckets;
    int nbuckets;
    void (*freefn)(void *);
    int (*hashfn)(void *, int);
    int (*compfn)(void *, void *);
};

extern void *gsimalloc(unsigned long size);
extern struct DArrayImplementation *ArrayNew(int elemSize,
                                             int numElemsToAllocate,
                                             void (*elemFreeFn)(void *));

struct HashImplementation *TableNew2(int elemSize, int nBuckets, int nChains,
                                     int (*hashFn)(void *, int),
                                     int (*compFn)(void *, void *),
                                     void (*freeFn)(void *))
{
    struct HashImplementation *table;
    int i;

    table = gsimalloc(0x14);
    table->buckets = gsimalloc(nBuckets << 2);
    for (i = 0; i < nBuckets; i++)
        table->buckets[i] = ArrayNew(elemSize, nChains, freeFn);
    table->nbuckets = nBuckets;
    table->freefn = freeFn;
    table->compfn = compFn;
    table->hashfn = hashFn;
    return table;
}