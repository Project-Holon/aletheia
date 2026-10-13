/*
 * function: MAP_MATRIX_GetZoneIdByPos
 * address:  0x02159BD4
 * packet:   pkt_02159BD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAP_MATRIX_PosToBlock  0x02159D68  thumb  ov010
 *   MAP_MATRIX_GetZoneId  0x02159BC4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MAP_MATRIX_PosToBlock(int x);
struct MapMatrix;
extern u16 MAP_MATRIX_GetZoneId(const struct MapMatrix *m, u32 x, u32 y);

int MAP_MATRIX_GetZoneIdByPos(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a2 + 0;
a0 = a1 + 0;
    a0 = MAP_MATRIX_PosToBlock(a0);
loc_02159BE0:
t6 = a0 + 0;
a0 = t4 + 0;
    a0 = MAP_MATRIX_PosToBlock(a0);
loc_02159BE8:
a2 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = MAP_MATRIX_GetZoneId((const struct MapMatrix *)a0, a1, a2);
loc_02159BF2:
    return a0;}
