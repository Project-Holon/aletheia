/*
 * function: VCT_SESSION_SendPacket
 * address:  0x021B275C
 * packet:   pkt_ov013_021B275C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   VCT_SESSION_BroadcastPacket  0x021B2620  arm  ov013
 *   DWC_SendReliable  0x02176E90  arm  ov009
 */

typedef unsigned char u8;

extern int VCT_SESSION_BroadcastPacket(int *o, u8 *p);
extern int DWC_SendReliable(int i, u8 *p, int n);

int VCT_SESSION_SendPacket(u8 *o, u8 *p)
{
    if (p[4] == 0xff && p[6] == 4) {
        VCT_SESSION_BroadcastPacket((int *)o, p);
    } else if (DWC_SendReliable(o[4], p, 0x10) == 0) {
        return 0;
    }
    return 1;
}
