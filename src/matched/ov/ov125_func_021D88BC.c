/*
 * function: GDS_SOCKET_SendGetVideo
 * address: 0x021D88BC
 * packet: pkt_ov125_021D88BC
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
typedef struct {int a,b,c;} Triple;
extern int GDS_SOCKET_SendRequest(int id, void *buf, int x, int sz);
int GDS_SOCKET_SendGetVideo(u32 a, u32 b, u32 c, u32 n)
{
    Triple p;
    p.a=a; p.b=b; p.c=c;
    return GDS_SOCKET_SendRequest(0x55f2, &p, n, -1);
}
