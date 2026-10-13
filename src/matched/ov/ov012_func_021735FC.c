/*
 * function: UNION_COMM_AddMemberFromBeaconPc
 * address: 0x021735FC
 * packet: pkt_ov012_021735FC
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_COMM_AddMember 0x0217357C thumb ov012
 */
typedef unsigned char u8;
typedef struct Entry { u8 mac[6]; u8 low6 : 4; u8 f6 : 4; u8 lo : 3; u8 used : 1; u8 hi : 4; u8 body[0x5c]; u8 mac2[6]; } Entry;
extern int UNION_COMM_AddMember(u8 *self, const u8 *mac, u8 a2, u8 a3);
int UNION_COMM_AddMemberFromBeaconPc(u8 *self, const Entry *p) { return UNION_COMM_AddMember(self, p->mac2, p->f6, p->used); }
