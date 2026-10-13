/*
 * function: DWCi_MSGlGet
 * address:  0x021C1030
 * packet:   pkt_021C1030
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MSGlGet   0x021C1030  arm
 *
 * Word of the table at p[0], indexed by the low halfword, plus the p[1] base.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MSGlGet.c \
 *       --func DWCi_MSGlGet --addr 0x021C1030 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned int DWCi_MSGlGet(unsigned int *p, unsigned int idx)
{
    return p[1] + ((unsigned int *)p[0])[(unsigned short)idx];
}
