/*
 * function: BEACON_VIEW_RefreshActorAnims
 * address:  0x021F067C
 * packet:   pkt_ov032_021F067C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_RefreshActorAnims 0x021F067C thumb
 *   BEACON_VIEW_UpdateActorAnims 0x021F0E24 thumb ov032
 */

extern void BEACON_VIEW_UpdateActorAnims(char *p);

void BEACON_VIEW_RefreshActorAnims(char *p)
{
    BEACON_VIEW_UpdateActorAnims(p);
}
