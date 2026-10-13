/*
 * function: BTL_SERVER_FLOW_GetClientIdBySide
 * address:  0x021C8300
 * packet:   pkt_021C8300
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetPartnerClient  0x021B9010  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 BTL_MAIN_GetPartnerClient(u8 *p, u8 k);

u32 BTL_SERVER_FLOW_GetClientIdBySide(int *p, u8 k)
{
    return BTL_MAIN_GetPartnerClient((u8 *)p[1], k);
}
