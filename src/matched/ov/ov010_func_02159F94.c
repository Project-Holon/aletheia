/*
 * function: MAP_REPLACE_GetWarpFlagId
 * address: 0x02159F94
 * packet: pkt_ov010_02159F94
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * addressing: getter result converted to unsigned; scale/add modulo 32 bits
 * preserves the original muls/add address without assuming a valid array index.
 * symbols:
 *   MAP_REPLACE_WarpIdToIndex 0x0215A064 thumb ov010
 *   d_02170FF4 0x02170FF4 data a2
 */
typedef unsigned short u16;
extern int MAP_REPLACE_WarpIdToIndex(int);
extern u16 d_02170FF4[][10];
u16 MAP_REPLACE_GetWarpFlagId(int a) { return *(u16 *)((unsigned)d_02170FF4 + (unsigned)MAP_REPLACE_WarpIdToIndex(a) * 20u); }
