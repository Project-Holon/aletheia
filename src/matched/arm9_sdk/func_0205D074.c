/*
 * function: DWC_UpdateConnection
 * address:  0x0205D074
 * packet:   pkt_0205D074
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_UpdateConnection (dwc_connectinet.o)
 *
 * symbols:
 *   DWC_ProcessInet 0x0205C8E0 arm
 *   DWCi_CheckDisconnected 0x0205CCAC arm
 *   DWC_AC_GetApType 0x0205BDD0 arm
 *   WCM_GetPhase 0x021656A0 arm
 *   DWCi_SetError 0x02059F54 arm
 */

extern void DWC_ProcessInet(void);
extern int DWCi_CheckDisconnected(void);
extern unsigned char DWC_AC_GetApType(void);
extern long WCM_GetPhase(void);
extern void DWCi_SetError(int error, int errorCode);

int DWC_UpdateConnection(void)
{
    unsigned char aptype;

    DWC_ProcessInet();
    if (DWCi_CheckDisconnected()) {
        aptype = DWC_AC_GetApType();
        if (aptype == 0xff || aptype > 99) {
            aptype = 99;
        }
        if (WCM_GetPhase() == 11) {
            DWCi_SetError(9, -54900 - aptype);
        } else {
            DWCi_SetError(8, -54000 - aptype);
        }
        return 1;
    }
    return 0;
}
