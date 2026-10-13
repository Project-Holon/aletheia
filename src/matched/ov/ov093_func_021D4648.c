/*
 * function: BTL_NET_GetPerapVoice
 * address: 0x021D4648
 * packet: pkt_ov093_021D4648
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Indexed struct arrays preserve scaled-index-before-base-load order.
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   BTL_NET_FindNetIdByClient 0x021D4394 thumb ov093
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct S { u8 pad[0x3ae4]; u32 a[4],b[4]; };
extern struct S *gBtlNet;
extern u8 BTL_NET_FindNetIdByClient(u32);
u32 BTL_NET_GetPerapVoice(u32 a) { u32 r; r=BTL_NET_FindNetIdByClient(a); if(r!=40) { if(gBtlNet->b[r]) return gBtlNet->a[r]; } return 0; }
