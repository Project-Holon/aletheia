/*
 * function: TableCount
 * address:  0x02184700
 * packet:   pkt_ov009_02184700
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableCount (hashtable.o)
 *
 * symbols:
 *   ArrayLength  0x02184200  arm  ov009
 */

struct DArrayImplementation;

struct HashImplementation {
    struct DArrayImplementation **buckets;
    int nbuckets;
    void (*freefn)(void *);
    int (*hashfn)(void *, int);
    int (*compfn)(void *, void *);
};

extern int ArrayLength(struct DArrayImplementation *array);

int TableCount(struct HashImplementation *table)
{
    int i;
    int count = 0;

    if (table == 0)
        return 0;
    for (i = 0; i < table->nbuckets; i++)
        count += ArrayLength(table->buckets[i]);
    return count;
}