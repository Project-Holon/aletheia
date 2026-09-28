/*
 * function: TableRemove
 * address:  0x021847BC
 * packet:   pkt_ov009_021847BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableRemove (hashtable.o)
 *
 * symbols:
 *   ArraySearch    0x021843E8  arm  ov009
 *   ArrayDeleteAt  0x0218437C  arm  ov009
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
extern void ArrayDeleteAt(struct DArrayImplementation *array, int n);

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