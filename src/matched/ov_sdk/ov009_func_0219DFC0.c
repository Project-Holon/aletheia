/*
 * function: SBRefStrHashCleanup
 * address:  0x0219DFC0
 * packet:   pkt_ov009_0219DFC0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBRefStrHashCleanup (sb_server.o)
 *
 * symbols:
 *   TableCount   0x02184700  arm
 *   TableFree    0x021846B4  arm
 *   g_021AEAF8   0x021AEAF8  data
 */

struct HashImplementation;

extern struct HashImplementation *g_021AEAF8[];
extern int TableCount(struct HashImplementation *table);
extern void TableFree(struct HashImplementation *table);

void SBRefStrHashCleanup(void)
{
    if (g_021AEAF8[1] == 0)
        return;
    if (TableCount(g_021AEAF8[1]) != 0)
        return;
    TableFree(g_021AEAF8[1]);
    g_021AEAF8[1] = 0;
}
