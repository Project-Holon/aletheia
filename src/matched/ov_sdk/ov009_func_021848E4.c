/*
 * function: TableMapSafe2
 * address:  0x021848E4
 * packet:   pkt_ov009_021848E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableMapSafe2 (hashtable.o)
 *
 * symbols:
 *   ArrayMap2  0x021844DC  arm  ov009
 */

struct DArrayImplementation;

struct HashImplementation {
    struct DArrayImplementation **buckets;
    int nbuckets;
    void (*freefn)(void *);
    int (*hashfn)(void *, int);
    int (*compfn)(void *, void *);
};

extern void *ArrayMap2(void *elem, int (*fn)(void *, void *),
                       void *clientData);

void *TableMapSafe2(struct HashImplementation *table, int (*fn)(void *, void *),
                void *clientData)
{
    void *pcurr;
    int i;

    for (i = 0; i < table->nbuckets; i++)
    {
        pcurr = table->buckets[i];
        pcurr = ArrayMap2(pcurr, fn, clientData);
        if (pcurr != 0)
            return pcurr;
    }
    return 0;
}
