/*
 * file:     unit_0219DF30_p02.c
 * unit:     yes
 * function: func_0219DF54, func_0219DF64, func_0219DFC0
 * address:  0x0219DF54
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
 *   gsifree                      0x0217EAE0  arm
 *   TableNew2         0x02184638  arm
 *   RefStringHash     0x0219DF30  arm
 *   RefStringCompare  0x0219DF40  arm
 *   RefStringFree     0x0219DF54  arm
 *   g_021AEAF8        0x021AEAF8  data
 *   TableCount   0x02184700  arm
 *   TableFree    0x021846B4  arm
 */
struct HashImplementation;
extern void gsifree(void);
extern struct HashImplementation *TableNew2(int elemSize, int nBuckets,
    int nChains, int (*hashFn)(void *, int), int (*compFn)(void *, void *),
    void (*freeFn)(void *));
extern int RefStringHash(void *elem, int numbuckets);
extern int RefStringCompare(void *entry1, void *entry2);
extern void RefStringFree(void *elem);
extern int TableCount(struct HashImplementation *table);
extern void TableFree(struct HashImplementation *table);
asm void KeyValHashKey(void);
struct HashImplementation *SBRefStrHash(void);
void SBRefStrHashCleanup(void);
extern struct HashImplementation *g_021AEAF8[];

asm void KeyValHashKey(void)
{
	ldr r0, [r0]
	ldr ip, =gsifree
	bx ip
}


struct HashImplementation *SBRefStrHash(void)
{
    if (g_021AEAF8[1] != 0)
        return g_021AEAF8[1];
    g_021AEAF8[1] = TableNew2(8, 100, 2, RefStringHash, RefStringCompare,
                              RefStringFree);
    return g_021AEAF8[1];
}


void SBRefStrHashCleanup(void)
{
    if (g_021AEAF8[1] == 0)
        return;
    if (TableCount(g_021AEAF8[1]) != 0)
        return;
    TableFree(g_021AEAF8[1]);
    g_021AEAF8[1] = 0;
}
