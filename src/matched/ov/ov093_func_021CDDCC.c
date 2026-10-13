/*
 * function: BTL_CLIENT_IsWindowDone
 * address: 0x021CDDCC
 * packet: pkt_ov093_021CDDCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u8 pad[0x1b2]; u8 low:5; u8 flag:1; u8 high:2; };
u32 BTL_CLIENT_IsWindowDone(struct Flags *p) { return p->flag; }
