/*
 * function: BTL_MAIN_GetOwnPartnerClient
 * address: 0x021B9000
 * packet: pkt_ov093_021B9000
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetPartnerClient 0x021B9010 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_MAIN_GetPartnerClient(u8 *p, u8 k);
u8 BTL_MAIN_GetOwnPartnerClient(u8 *p) { return BTL_MAIN_GetPartnerClient(p,p[0x46c]); }
