/*
 * function: GDS_SOCKET_SendMarkVideo
 * address: 0x021D88F0
 * packet: pkt_ov125_021D88F0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_SendRequest 0x021D7A10 arm ov125
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {int a,b;} Pair;
extern int GDS_SOCKET_SendRequest(int id, void *buf, int x, int sz);
int GDS_SOCKET_SendMarkVideo(u32 a, u32 b, u32 n)
{
    Pair p;
    p.a=a; p.b=b;
    return GDS_SOCKET_SendRequest(0x55f3, &p, n, -1);
}
