/*
 * function: VCT_SESSION_BroadcastState
 * address:  0x021B26DC
 * packet:   pkt_ov013_021B26DC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B4C0C  0x021B4C0C  data  ov013  a4
 *   VCT_SESSION_InitPacketHeader  0x021B2848  arm  ov013
 *   VCT_SESSION_BroadcastPacket  0x021B2620  arm  ov013
 */

typedef unsigned char u8;

extern char d_021B4C0C;
struct Msg;
extern int VCT_SESSION_InitPacketHeader(u8 *o, struct Msg *p, int n);
extern int VCT_SESSION_BroadcastPacket(int *o, u8 *p);

void VCT_SESSION_BroadcastState(int x)
{
    u8 buf[16];

    buf[4] = 0xff;
    VCT_SESSION_InitPacketHeader((u8 *)(&d_021B4C0C), (struct Msg *)buf, 4);
    buf[10] = x;
    VCT_SESSION_BroadcastPacket((int *)(&d_021B4C0C), buf);
}
