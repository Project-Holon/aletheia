/*
 * function: GDS_SOCKET_SendDownloadEntries
 * address: 0x021D8654
 * packet: pkt_ov125_021D8654
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_SendRequest 0x021D7A10 arm ov125
 */
typedef struct { unsigned short a,b; long long value; } Packet;
extern int GDS_SOCKET_SendRequest(int id, void *buf, int x, int sz);
int GDS_SOCKET_SendDownloadEntries(int value, int n) {
 Packet p;
 p.a = 0; p.b = 0; p.value = value;
 return GDS_SOCKET_SendRequest(0x5209, &p, n, -1);
}
