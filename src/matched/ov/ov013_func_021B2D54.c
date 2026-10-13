/*
 * function: VCT_SESSION_HandleUnknownProtocolPacket
 * address:  0x021B2D54
 * packet:   pkt_ov013_021B2D54
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B4BF4  0x021B4BF4  data  a4
 *   VCT_SESSION_FindPeer  0x021B2A20  arm  ov013
 *   VCT_SESSION_SendReply  0x021B25B0  arm  ov013
 *   VCT_SESSION_InitPeer  0x021B2724  arm  ov013
 */

typedef unsigned char u8;

typedef struct N {
    int a;
} N;

extern int d_021B4BF4[];
extern N *VCT_SESSION_FindPeer(int id);
extern int VCT_SESSION_SendReply(int a, int b);
extern void VCT_SESSION_InitPeer(u8 *p, u8 v);

int VCT_SESSION_HandleUnknownProtocolPacket(u8 *p, int *out)
{
    N *n;

    if (p[4] == 0xff && p[6] == 4)
        return 0;
    n = VCT_SESSION_FindPeer(p[8]);
    if (n) {
        out[0] = 2;
        out[1] = (int)n;
        n->a = 0;
        VCT_SESSION_SendReply((int)n, 2);
        return 1;
    }
    VCT_SESSION_InitPeer((u8 *)d_021B4BF4, p[8]);
    VCT_SESSION_SendReply((int)d_021B4BF4, 2);
    return 0;
}
