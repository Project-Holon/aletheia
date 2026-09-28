/*
 * function: TableMapSafe
 * address:  0x0218489C
 * packet:   pkt_ov009_0218489C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableMapSafe (hashtable.o)
 *
 * symbols:
 *   ArrayMapBackwards  0x021844A0  arm  ov009
 */

struct DArrayImplementation;

struct HashImplementation {
    struct DArrayImplementation **buckets;
    int nbuckets;
    void (*freefn)(void *);
    int (*hashfn)(void *, int);
    int (*compfn)(void *, void *);
};

extern void ArrayMapBackwards(struct DArrayImplementation *array,
                              void (*fn)(void *, void *), void *clientData);

void TableMapSafe(struct HashImplementation *table, void (*fn)(void *, void *),
                  void *clientData)
{
    int i;

    for (i = 0; i < table->nbuckets; i++)
        ArrayMapBackwards(table->buckets[i], fn, clientData);
}