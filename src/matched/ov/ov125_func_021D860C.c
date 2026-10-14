/*
 * function: GDS_SOCKET_SendUploadEntry
 * address: 0x021D860C
 * packet: pkt_ov125_021D860C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_SendRequest 0x021D7A10 arm ov125
 */
typedef struct { unsigned words[0x230/4]; } Packet;
extern int GDS_SOCKET_SendRequest(int id, void *buf, int x, int sz);
int GDS_SOCKET_SendUploadEntry(const Packet *p, int n) {
 Packet copy;
 copy = *p;
 return GDS_SOCKET_SendRequest(0x5208, &copy, n, -1);
}
