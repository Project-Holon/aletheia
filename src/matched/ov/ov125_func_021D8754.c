/*
 * function: GDS_SOCKET_SendSearchByCondition
 * address: 0x021D8754
 * packet: pkt_ov125_021D8754
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * lever: The source Data pointer is non-const; const swaps the initial
 * strh lr,[sp] and mov r4,r1 (six concrete bytes differ).
 * symbols:
 *   GDS_SOCKET_SendRequest 0x021D7A10 arm ov125
 */
typedef struct { unsigned words[4]; } Data;
typedef struct { unsigned short a,b; Data data; unsigned tail[2]; } Packet;
extern int GDS_SOCKET_SendRequest(int id, void *buf, int x, int sz);
int GDS_SOCKET_SendSearchByCondition(Data *data, int n) {
 Packet p;
 p.a = 0;
 p.data = *data;
 p.a = 0; p.b = 0;
 return GDS_SOCKET_SendRequest(0x55f1, &p, n, -1);
}
