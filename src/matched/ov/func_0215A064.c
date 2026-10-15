/*
 * function: MAP_REPLACE_WarpIdToIndex
 * address:  0x0215A064
 * packet:   pkt_0215A064
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAP_REPLACE_IsValidWarpId  0x02159F84  thumb  ov010
 *   MAP_REPLACE_GetDefaultWarpId  0x02159F80  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MAP_REPLACE_IsValidWarpId(int a0);
extern int MAP_REPLACE_GetDefaultWarpId();

int MAP_REPLACE_WarpIdToIndex(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = MAP_REPLACE_IsValidWarpId(a0);
loc_0215A06C:
    if (a0 != 0) goto loc_0215A076;
loc_0215A070:
    a0 = MAP_REPLACE_GetDefaultWarpId();
loc_0215A074:
t4 = a0 + 0;
loc_0215A076:
a0 = t4 - 1;
    return a0;}
