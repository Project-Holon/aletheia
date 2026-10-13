/*
 * function: SYMBOL_MAP_GetSelectedNeighborCell
 * address:  0x021665F0
 * packet:   pkt_021665F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SYMBOL_MAP_GetSelectionGrid  0x0216649C  thumb  ov010
 *   SYMBOL_MAP_GetNeighborCellId  0x021663F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 SYMBOL_MAP_GetSelectionGrid(void *p);
extern int SYMBOL_MAP_GetNeighborCellId(u8 *list, int def, unsigned dir);

int SYMBOL_MAP_GetSelectedNeighborCell(int a0, int a1, int a2)
{
    int t4;
    int t5;
    void *p;

t5 = a1 + 0;
t4 = a2 + 0;
    p = (void *)SYMBOL_MAP_GetSelectionGrid((void *)a0);
loc_021665FA:
    if (p == 0) goto loc_02166614;
loc_021665FE:
a1 = t5 + 1;
a1 = a1 << 0x18;
a2 = t4 << 0x18;
a1 = (unsigned)a1 >> 0x18;
a2 = (unsigned)a2 >> 0x18;
    a0 = SYMBOL_MAP_GetNeighborCellId(p, a1, a2);
loc_0216660C:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
a0 = a0 - 1;
    return a0;
loc_02166614:
a0 = 4;
    return a0;}
