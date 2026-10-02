/*
 * function: func_021735FC
 * address: 0x021735FC
 * packet: pkt_ov012_021735FC
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217357C 0x0217357C thumb ov012
 */
typedef unsigned char u8;
typedef struct Entry { u8 mac[6]; u8 low6 : 4; u8 f6 : 4; u8 lo : 3; u8 used : 1; u8 hi : 4; u8 body[0x5c]; u8 mac2[6]; } Entry;
extern int func_0217357C(u8 *self, const u8 *mac, u8 a2, u8 a3);
int func_021735FC(u8 *self, const Entry *p) { return func_0217357C(self, p->mac2, p->f6, p->used); }
