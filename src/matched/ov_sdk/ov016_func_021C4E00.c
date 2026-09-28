/*
 * function: procError
 * address:  0x021C4E00
 * packet:   pkt_ov016_021C4E00
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procError (libdwcutil.TWL.HYB.a scenesetaossbutt)
 * symbols:
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procError1                       0x021C4E2C  arm
 */
extern int  DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_WINlEnd(void);
extern void DWCi_ChangeScene(void (*scene)());

static void procError1(void);

static void procError(void)
{
    if (DWCi_WINlGet())
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procError1);
}
