/*
 * function: MAP_MATRIX_IsInRangeByPos
 * address:  0x02159C48
 * packet:   pkt_02159C48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAP_MATRIX_PosToBlock  0x02159D68  thumb  ov010
 *   MAP_MATRIX_IsInRange  0x02159C2C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MAP_MATRIX_PosToBlock(int x);
extern int MAP_MATRIX_IsInRange();

int MAP_MATRIX_IsInRangeByPos(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a2 + 0;
a0 = a1 + 0;
    a0 = MAP_MATRIX_PosToBlock(a0);
loc_02159C54:
t6 = a0 + 0;
a0 = t4 + 0;
    a0 = MAP_MATRIX_PosToBlock(a0);
loc_02159C5C:
a2 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = MAP_MATRIX_IsInRange(a0, a1, a2);
loc_02159C66:
    return a0;}
