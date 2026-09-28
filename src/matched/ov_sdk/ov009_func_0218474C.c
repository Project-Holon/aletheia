/*
 * function: TableEnter
 * address:  0x0218474C
 * packet:   pkt_ov009_0218474C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableEnter (hashtable.o)
 *
 * symbols:
 *   ArraySearch     0x021843E8  arm  ov009
 *   ArrayAppend     0x02184234  arm  ov009
 *   ArrayReplaceAt  0x0218439C  arm  ov009
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
extern void ArrayAppend(struct DArrayImplementation *array, void *newElem);
extern void ArrayReplaceAt(struct DArrayImplementation *array, void *newElem,
                           int n);

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