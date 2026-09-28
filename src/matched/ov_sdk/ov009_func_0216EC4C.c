/*
 * function: DWCi_ProcessMatchSynPacket
 * address:  0x0216EC4C
 * packet:   pkt_ov009_0216EC4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessMatchSynPacket (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_IsFullMesh                        0x0217695C arm
 *   DWCi_ProcessMatchSynPacketSub_FullMesh 0x0216F008 arm
 *   DWCi_ProcessMatchSynPacketSub_Hybrid   0x0216EC84 arm
 */

extern int DWCi_IsFullMesh(void);
extern void DWCi_ProcessMatchSynPacketSub_FullMesh(unsigned char aid, unsigned short type, unsigned char *data);
extern void DWCi_ProcessMatchSynPacketSub_Hybrid(unsigned char aid, unsigned short type, unsigned char *data);

void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data)
{
    if (DWCi_IsFullMesh())
        DWCi_ProcessMatchSynPacketSub_FullMesh(aid, type, data);
    else
        DWCi_ProcessMatchSynPacketSub_Hybrid(aid, type, data);
}
