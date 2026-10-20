/*
 * file:     hashtable.c
 * unit:     yes
 * function: TableNew, TableNew2, TableFree, TableCount, TableEnter, TableRemove, TableLookup, TableMapSafe, TableMapSafe2
 * address:  0x02184610
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
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   ArrayNew   0x02184144  arm  ov009
 *   ArrayFree  0x021841B0  arm  ov009
 *   gsifree    0x0217EAE0  arm  ov009
 *   ArrayLength  0x02184200  arm  ov009
 *   ArraySearch     0x021843E8  arm  ov009
 *   ArrayAppend     0x02184234  arm  ov009
 *   ArrayReplaceAt  0x0218439C  arm  ov009
 *   ArrayDeleteAt  0x0218437C  arm  ov009
 *   ArrayNth     0x02184208  arm  ov009
 *   ArrayMapBackwards  0x021844A0  arm  ov009
 *   ArrayMapBackwards2  0x021844DC  arm  ov009
 */
struct HashImplementation;
struct DArrayImplementation;
struct HashImplementation {
    struct DArrayImplementation **buckets;
    int nbuckets;
    void (*freefn)(void *);
    int (*hashfn)(void *, int);
    int (*compfn)(void *, void *);
};

#include "gsmemory.h"
#include "darray.h"
struct HashImplementation *TableNew(int elemSize, int nBuckets, int (*hashFn)(void *, int), int (*compFn)(void *, void *), void (*freeFn)(void *));
struct HashImplementation *TableNew2(int elemSize, int nBuckets, int nChains, int (*hashFn)(void *, int), int (*compFn)(void *, void *), void (*freeFn)(void *));
void TableFree(struct HashImplementation *table);
int TableCount(struct HashImplementation *table);
void TableEnter(struct HashImplementation *table, void *newElem);
int TableRemove(struct HashImplementation *table, void *delElem);
void *TableLookup(struct HashImplementation *table, void *elemKey);
void TableMapSafe(struct HashImplementation *table, void (*fn)(void *, void *), void *clientData);
void *TableMapSafe2(struct HashImplementation *table, int (*fn)(void *, void *), void *clientData);


struct HashImplementation *TableNew(int elemSize, int nBuckets,
                                    int (*hashFn)(void *, int),
                                    int (*compFn)(void *, void *),
                                    void (*freeFn)(void *))
{
    return TableNew2(elemSize, nBuckets, 4, hashFn, compFn, freeFn);
}


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


void TableFree(struct HashImplementation *table)
{
    int i;

    if (table == 0)
        return;
    for (i = 0; i < table->nbuckets; i++)
        ArrayFree(table->buckets[i]);
    gsifree(table->buckets);
    gsifree(table);
}


int TableCount(struct HashImplementation *table)
{
    int i;
    int count = 0;

    if (table == 0)
        return 0;
    for (i = 0; i < table->nbuckets; i++)
        count += ArrayLength((struct DArrayImplementation *)table->buckets[i]);
    return count;
}


void TableEnter(struct HashImplementation *table, void *newElem)
{
    int itempos;
    int hash;

    if (table == 0)
        return;
    hash = table->hashfn(newElem, table->nbuckets);
    itempos = ArraySearch(table->buckets[hash], newElem, table->compfn, 0, 0);
    if (itempos == -1)
        ArrayAppend(table->buckets[hash], newElem);
    else
        ArrayReplaceAt(table->buckets[hash], newElem, itempos);
}


int TableRemove(struct HashImplementation *table, void *delElem)
{
    int itempos;
    int hash;

    if (table == 0)
        return 0;
    hash = table->hashfn(delElem, table->nbuckets);
    itempos = ArraySearch(table->buckets[hash], delElem, table->compfn, 0, 0);
    if (itempos == -1)
        return 0;
    ArrayDeleteAt(table->buckets[hash], itempos);
    return 1;
}


void *TableLookup(struct HashImplementation *table, void *elemKey)
{
    int itempos;
    int hash;

    if (table == 0)
        return 0;
    hash = table->hashfn(elemKey, table->nbuckets);
    itempos = ArraySearch(table->buckets[hash], elemKey, table->compfn, 0, 0);
    if (itempos == -1)
        return 0;
    return ArrayNth(table->buckets[hash], itempos);
}


void TableMapSafe(struct HashImplementation *table, void (*fn)(void *, void *),
                  void *clientData)
{
    int i;

    for (i = 0; i < table->nbuckets; i++)
        ArrayMapBackwards(table->buckets[i], fn, clientData);
}


void *TableMapSafe2(struct HashImplementation *table, int (*fn)(void *, void *),
                void *clientData)
{
    void *pcurr;
    int i;

    for (i = 0; i < table->nbuckets; i++)
    {
        pcurr = table->buckets[i];
        pcurr = ArrayMapBackwards2(pcurr, fn, clientData);
        if (pcurr != 0)
            return pcurr;
    }
    return 0;
}
