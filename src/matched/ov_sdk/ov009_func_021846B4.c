/*
 * function: TableFree
 * address:  0x021846B4
 * packet:   pkt_ov009_021846B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TableFree (hashtable.o)
 *
 * symbols:
 *   ArrayFree  0x021841B0  arm  ov009
 *   gsifree    0x0217EAE0  arm  ov009
 */

struct DArrayImplementation;

struct HashImplementation {
    struct DArrayImplementation **buckets;
    int nbuckets;
    void (*freefn)(void *);
    int (*hashfn)(void *, int);
    int (*compfn)(void *, void *);
};

extern void ArrayFree(struct DArrayImplementation *array);
extern void gsifree(void *ptr);

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
