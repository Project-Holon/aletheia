/*
 * function: FIELD_PLAYER_TryPushBoulder
 * address:  0x021A2F20
 * packet:   pkt_ov021_021A2F20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_TryPushBoulder  0x021C0CA4  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 FIELDMAP_GetMoveKind(u8 *p);
int FIELD_PLAYER_GRID_EVENT_TryPushBoulder(u8 *a, int b, int c, int d);

int FIELD_PLAYER_TryPushBoulder(u32 *p, int a, int b, int c)
{
    int r = 0;

    if (FIELDMAP_GetMoveKind((u8 *)p[0]) == 0)
        r = FIELD_PLAYER_GRID_EVENT_TryPushBoulder((u8 *)p[2], a, b, c);
    return r;
}
