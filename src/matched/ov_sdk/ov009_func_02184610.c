/*
 * function: TableNew
 * address:  0x02184610
 * packet:   pkt_ov009_02184610
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableNew (hashtable.o)
 *
 * symbols:
 *   TableNew2  0x02184638  arm  ov009
 */

struct HashImplementation;

struct HashImplementation *TableNew2(int elemSize, int nBuckets, int nChains,
                                     int (*hashFn)(void *, int),
                                     int (*compFn)(void *, void *),
                                     void (*freeFn)(void *));

struct HashImplementation *TableNew(int elemSize, int nBuckets,
                                    int (*hashFn)(void *, int),
                                    int (*compFn)(void *, void *),
                                    void (*freeFn)(void *))
{
    return TableNew2(elemSize, nBuckets, 4, hashFn, compFn, freeFn);
}