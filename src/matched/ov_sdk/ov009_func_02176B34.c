/*
 * function: DWCi_NNFreeNegotiateList
 * address:  0x02176B34
 * packet:   pkt_ov009_02176B34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NNFreeNegotiateList (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt      0x02175F3C arm
 *   NNCancel              0x02199FB4 arm
 *   NNFreeNegotiateList   0x0219922C arm
 *   s_bInNNThink          0x021AAA20 data
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x618];
    int nnCookie;            /* +0x618 */
};

struct NNThinkGlobal
{
    int f0;
    int f4;
    int f8;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void NNCancel(int cookie);
extern void NNFreeNegotiateList(void);
extern struct NNThinkGlobal s_bInNNThink;

void DWCi_NNFreeNegotiateList(void)
{
    NNCancel(DWCi_GetMatchCnt()->nnCookie);
    if (s_bInNNThink.f0 != 0) {
        s_bInNNThink.f8 = 1;
    } else {
        NNFreeNegotiateList();
    }
}
