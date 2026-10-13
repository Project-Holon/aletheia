/*
 * function: BTL_SERVER_FLOW_AddSeenPokeThunk
 * address:  0x021C84E0
 * packet:   pkt_021C84E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_AddSeenPoke  0x021C84F4  thumb  ov093
 *
 * Was MATCH (pool word to the unlabelled 0x021C84F4 had no witness); the
 * matched BTL_SERVER_FLOW_AddSeenPoke now resolves it, verified EXACT.
 */

void BTL_SERVER_FLOW_AddSeenPoke(unsigned char *p, unsigned int v);

void BTL_SERVER_FLOW_AddSeenPokeThunk(unsigned char *p, unsigned int v)
{
    BTL_SERVER_FLOW_AddSeenPoke(p, v);
}
