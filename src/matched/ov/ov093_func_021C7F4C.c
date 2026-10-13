/*
 * function: BTL_SERVER_FLOW_TrySetOnceFlag
 * address: 0x021C7F4C
 * packet: pkt_ov093_021C7F4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
struct Flag { u8 pad[0x78a]; u8 low:3; u8 set:1; u8 high:4; };
int BTL_SERVER_FLOW_TrySetOnceFlag(struct Flag *p) { if (p->set) return 0; p->set = 1; return 1; }
