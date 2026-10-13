/*
 * function: VCT_SESSION_SendReply
 * address:  0x021B25B0
 * packet:   pkt_ov013_021B25B0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   VCT_SESSION_BuildPeerReply  0x021B20D4  arm  ov013
 *   VCT_SESSION_SendPacket  0x021B275C  arm  ov013
 */

typedef unsigned char u8;

struct Chan;
extern int VCT_SESSION_BuildPeerReply(struct Chan *a, unsigned int b, unsigned char *buf, unsigned int c);
extern int VCT_SESSION_SendPacket(u8 *o, u8 *p);

int VCT_SESSION_SendReply(int a, int b)
{
    u8 buf[16];
    int r;

    r = VCT_SESSION_BuildPeerReply((struct Chan *)a, b, buf, 16);
    if (r != 0)
        return r;
    if (VCT_SESSION_SendPacket((u8 *)a, buf) != 0)
        return 0;
    return -4;
}
