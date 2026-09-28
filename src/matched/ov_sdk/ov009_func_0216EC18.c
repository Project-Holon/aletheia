/*
 * function: DWCi_ClearQR2Key
 * address:  0x0216EC18
 * packet:   pkt_ov009_0216EC18
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ClearQR2Key (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWC_GetState        0x0216B994 arm
 *   DWCi_GetMatchCnt    0x02175F3C arm
 *   qr2_send_statechanged 0x0219B490 arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[0x10];
    void *qr2Obj;            /* +0x10 */
    u8 pad1[0x17 - 0x14];
    u8 qr2NumEntry;          /* +0x17 */
    u8 pad2[0x790 - 0x18];
    u32 groupID;             /* +0x790 */
};

extern int DWC_GetState(void);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void qr2_send_statechanged(void *qrec);

void DWCi_ClearQR2Key(void)
{
    if (DWC_GetState() != 3)
        return;
    DWCi_GetMatchCnt()->qr2NumEntry = 0;
    DWCi_GetMatchCnt()->groupID = 0;
    qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
}
