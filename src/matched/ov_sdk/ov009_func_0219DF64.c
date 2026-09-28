/*
 * function: SBRefStrHash
 * address:  0x0219DF64
 * packet:   pkt_ov009_0219DF64
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TableNew2         0x02184638  arm
 *   RefStringHash     0x0219DF30  arm
 *   RefStringCompare  0x0219DF40  arm
 *   RefStringFree     0x0219DF54  arm
 *   g_021AEAF8        0x021AEAF8  data
 */
struct HashImplementation;

extern struct HashImplementation *g_021AEAF8[];
extern struct HashImplementation *TableNew2(int elemSize, int nBuckets,
    int nChains, int (*hashFn)(void *, int), int (*compFn)(void *, void *),
    void (*freeFn)(void *));
extern int RefStringHash(void *elem, int numbuckets);
extern int RefStringCompare(void *entry1, void *entry2);
extern void RefStringFree(void *elem);

struct HashImplementation *SBRefStrHash(void)
{
    if (g_021AEAF8[1] != 0)
        return g_021AEAF8[1];
    g_021AEAF8[1] = TableNew2(8, 100, 2, RefStringHash, RefStringCompare,
                              RefStringFree);
    return g_021AEAF8[1];
}
