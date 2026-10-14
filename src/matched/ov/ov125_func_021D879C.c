/*
 * function: GDS_SOCKET_SendSearchKind1
 * address: 0x021D879C
 * packet: pkt_ov125_021D879C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_SendRequest 0x021D7A10 arm ov125
 */
typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet;
extern int GDS_SOCKET_SendRequest(int id, void *buf, int x, int sz);
int GDS_SOCKET_SendSearchKind1(int value, int n) {
 Packet p = {0};
 p.value = value;
 p.a = 1; p.tail[1] = 0; p.tail[2] = 0; p.b = 0;
 return GDS_SOCKET_SendRequest(0x55f1, &p, n, -1);
}
