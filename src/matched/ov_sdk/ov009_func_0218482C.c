/*
 * function: TableLookup
 * address:  0x0218482C
 * packet:   pkt_ov009_0218482C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableLookup (hashtable.o)
 *
 * symbols:
 *   ArraySearch  0x021843E8  arm  ov009
 *   ArrayNth     0x02184208  arm  ov009
 */

struct DArrayImplementation;

struct HashImplementation {
    struct DArrayImplementation **buckets;
    int nbuckets;
    void (*freefn)(void *);
    int (*hashfn)(void *, int);
    int (*compfn)(void *, void *);
};

extern int ArraySearch(struct DArrayImplementation *array, void *key,
                       int (*comparator)(void *, void *), int fromIndex,
                       int isSorted);
extern void *ArrayNth(struct DArrayImplementation *array, int n);

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
