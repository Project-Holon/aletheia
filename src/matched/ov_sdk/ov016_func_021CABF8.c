/*
 * function: procError
 * address:  0x021CABF8
 * packet:   pkt_ov016_021CABF8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_WINlGet     0x021D1568 arm
 *   DWCi_SNDlPlay    0x021CFFAC arm
 *   DWCi_WINlEnd     0x021D1524 arm
 *   DWCi_ChangeScene 0x021C0E40 arm
 *   procError1       0x021CAC24 arm
 */

int DWCi_WINlGet(void);
void DWCi_SNDlPlay(int no);
void DWCi_WINlEnd(void);
void DWCi_ChangeScene(void (*scene)(void));
void procError1(void);

void procError(void)
{
    if (DWCi_WINlGet() == 0) {
        DWCi_SNDlPlay(6);
        DWCi_WINlEnd();
        DWCi_ChangeScene(procError1);
    }
}
