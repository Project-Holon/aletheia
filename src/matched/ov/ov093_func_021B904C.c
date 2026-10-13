/*
 * function: BTL_MAIN_GetOwnOpponentClient
 * address: 0x021B904C
 * packet: pkt_ov093_021B904C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetOpponentClient 0x021B9064 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_MAIN_GetOpponentClient(u8 *p, int k, int x);
u8 BTL_MAIN_GetOwnOpponentClient(u8 *p,int k) { return BTL_MAIN_GetOpponentClient(p,p[0x46c],k); }
