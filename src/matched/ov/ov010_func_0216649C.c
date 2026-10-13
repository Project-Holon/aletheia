/*
 * function: SYMBOL_MAP_GetSelectionGrid
 * address: 0x0216649C
 * packet: pkt_ov010_0216649C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * A zero case with a default continuation keeps the failure exit first.
 * Returns the full-word pointer payload from the selected table slot.
 * symbols:
 *   SYMBOL_MAP_GetSelection 0x02166434 thumb ov010
 *   g_SymbolMapGridTable 0x02171EF4 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *g_SymbolMapGridTable[];
extern int SYMBOL_MAP_GetSelection(void *, u32 *, u32 *);
u32 SYMBOL_MAP_GetSelectionGrid(void *p) {
    u32 a;
    u32 b;
    switch (SYMBOL_MAP_GetSelection(p, &a, &b)) {
    case 0: return 0;
    default: break;
    }
    return *(u32 *)((u32)g_SymbolMapGridTable + (a + b * 7u) * 4u);
}
