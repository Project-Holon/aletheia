/*
 * function: DWC_RAP_UpdatePeerVchatFlag
 * address: 0x02155DA4
 * packet: pkt_ov009_02155DA4
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _pRapWork 0x021A8264 data ov009 a4
 */
typedef unsigned char u8;
extern u8 *_pRapWork;
void DWC_RAP_UpdatePeerVchatFlag(unsigned int v)
{
    if (v & 0x100) {
        *(int *)(_pRapWork + 0x790) = 1;
    } else {
        *(int *)(_pRapWork + 0x790) = 0;
    }
}
