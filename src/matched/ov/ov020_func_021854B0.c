/*
 * function: EVENT_MAPCHANGE_CreateWarpEventDefaultTransition
 * address: 0x021854B0
 * packet: pkt_ov020_021854B0
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   EVENT_MAPCHANGE_CreateWarpEventWithTransition 0x02185458 thumb ov020
 */
typedef unsigned short u16;
typedef short s16;
extern void *EVENT_MAPCHANGE_CreateWarpEventWithTransition(void *p, int u, int b, s16 a, const int *s, u16 x);
void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *p, int u, s16 a, const int *s, u16 x)
{
    return EVENT_MAPCHANGE_CreateWarpEventWithTransition(p, u, 0, a, s, x);
}
