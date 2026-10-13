/*
 * function: FLDEFF_FOOTMARK_GetSlotIndex
 * address:  0x021BBD84
 * packet:   pkt_ov021_021BBD84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFootmarkSlotTable     0x021D9AE8  data  a4
 */

typedef unsigned char u8;
typedef struct Row { u8 b[4]; } Row;
extern Row gFootmarkSlotTable[];

int FLDEFF_FOOTMARK_GetSlotIndex(int a, int n, int x, int y)
{
    int r = 0;
    switch (n) {
    case 0: r = x; break;
    case 1: r = gFootmarkSlotTable[y].b[x]; break;
    case 2: r = x + 10; break;
    case 3: r = gFootmarkSlotTable[y].b[x] - 4; r += 14; break;
    case 4: r = gFootmarkSlotTable[y].b[x] - 4; r += 20; break;
    }
    return r;
}
