/*
 * function: DWCi_ResumeMatch
 * address:  0x02172DE8
 * packet:   pkt_ov009_02172DE8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ResumeMatch (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt        0x02175F3C arm
 *   DWCi_RestartFromCancel  0x02172BB8 arm
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x18];
    u8 qr2IsReserved;        /* +0x18 */
    u8 pad1[0x5dc - 0x19];
    int qr2Reservation;      /* +0x5dc */
    u8 pad2[0x629 - 0x5e0];
    u8 closeState;           /* +0x629 */
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void DWCi_RestartFromCancel(int level);

int DWCi_ResumeMatch(void)
{
    DWCi_GetMatchCnt()->qr2IsReserved = 0;
    DWCi_GetMatchCnt()->qr2Reservation = 0;
    DWCi_GetMatchCnt()->closeState = 0;
    DWCi_RestartFromCancel(1);
    return 0;
}
