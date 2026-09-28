/*
 * function: DWCi_SetHostStatus
 * address:  0x02175F84
 * packet:   pkt_ov009_02175F84
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SetHostStatus (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt       0x02175F3C arm
 *   qr2_send_statechanged  0x0219B490 arm
 *   s_bInNNThink           0x021AAA20 data
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x10];
    void *qr2Obj;            /* +0x10 */
    u8 pad1[0x16 - 0x14];
    u8 hostState;            /* +0x16 */
};

struct NNThinkGlobal
{
    int f0;
    struct DWCstMatchControl *pMatch;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void qr2_send_statechanged(void *qrec);
extern struct NNThinkGlobal s_bInNNThink;

void DWCi_SetHostStatus(int host)
{
    s_bInNNThink.pMatch->hostState = host;
    if (DWCi_GetMatchCnt()->qr2Obj != 0)
        qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
}
