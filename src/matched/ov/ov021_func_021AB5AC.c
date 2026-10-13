/*
 * function: MAP_ATTR_IsHopTransition
 * address:  0x021AB5AC
 * packet:   pkt_ov021_021AB5AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb
 *   MAP_ATTR_IsLongHopEdge  0x021AB2E8  thumb
 */

extern unsigned short MAP_ATTR_GetTerrainId(unsigned long attr);
extern unsigned short MAP_ATTR_GetFlags(unsigned long attr);
extern int MAP_ATTR_IsBlocked(unsigned long attr);
extern int MAP_ATTR_IsLongHopEdge(int id);

int MAP_ATTR_IsHopTransition(unsigned long a, unsigned long b)
{
    unsigned short lo = MAP_ATTR_GetFlags(b);
    unsigned short hi = MAP_ATTR_GetTerrainId(b);

    if (MAP_ATTR_IsBlocked(a))
        return 0;
    if (((lo & 2) && !MAP_ATTR_IsBlocked(b)) || MAP_ATTR_IsLongHopEdge(hi))
        return 1;
    return 0;
}
