/*
 * function: FIELD_GIMMICK_LANE_TRAINS_PlaceTrains
 * address:  0x021F38F4
 * packet:   pkt_ov058_021F38F4
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains  0x021F391C  thumb  ov058
 */

extern void FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(void *unused, void *a, int i, int j);

void FIELD_GIMMICK_LANE_TRAINS_PlaceTrains(void *unused, void *a)
{
    FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(unused, a, 0, 1);
    FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(unused, a, 4, 5);
    FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(unused, a, 8, 9);
}
