/*
 * file:     dwc_ac_close.c
 * unit:     yes
 * function: DWCi_AC_CloseNetwork, func_0205B264, CloseSocket
 * address:  0x0205B1E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0205B264 0x0205B264 arm
 *   DWC_Netcheck_Abort 0x0217AA20 arm
 *   DWC_Netcheck_Destroy 0x0217A950 arm
 *   func_021656A0 0x021656A0 arm
 *   WCM_Finish 0x02164EE0 arm
 *   WCM_CleanupAsync 0x02165088 arm
 *   WCM_EndSearchAsync 0x02165204 arm
 *   WCM_DisconnectAsync 0x02165478 arm
 *   WCM_TerminateAsync 0x02165560 arm
 *   DWCi_AC_SetError 0x0205C2E4 arm
 *   SOCL_CalmDown   0x0215ED60  arm
 *   SOC_Cleanup     0x0215FA90  arm
 *   SOCLiConfigPtr  0x021A1CD8  data  ov009
 */
extern int func_0205B264(void);
extern void DWC_Netcheck_Abort(void);
extern void DWC_Netcheck_Destroy(void);
extern int func_021656A0(void);
extern void WCM_Finish(void);
extern void WCM_CleanupAsync(void);
extern void WCM_EndSearchAsync(void);
extern void WCM_DisconnectAsync(void);
extern void WCM_TerminateAsync(void);
extern void DWCi_AC_SetError(int error);
extern int SOCL_CalmDown(void);
extern int SOC_Cleanup(void);
int DWCi_AC_CloseNetwork(unsigned char *phase);
int DisConnectAP(void);
int CloseSocket(void);
extern void *SOCLiConfigPtr;


/*
 * sdk:      DWCi_AC_CloseNetwork (close.o)
 */
int DWCi_AC_CloseNetwork(unsigned char *phase)
{
    int result;

    if (*phase <= 10) {
        result = func_0205B264();
        if (result == 1) {
            *phase = 0;
            return 1;
        } else if (result == -1) {
            *phase = 0x12;
            return 1;
        }
    } else if (*phase == 14) {
        DWC_Netcheck_Abort();
        DWC_Netcheck_Destroy();
        *phase = 12;
    } else if (*phase < 0x12) {
        if (CloseSocket() == 1)
            *phase = 10;
    }
    return 0;
}


int DisConnectAP(void)
{
    switch (func_021656A0()) {
    case 0:
        return 1;
    case 1:
        WCM_Finish();
        break;
    case 3:
        WCM_CleanupAsync();
        break;
    case 6:
        WCM_EndSearchAsync();
        break;
    case 9:
        WCM_DisconnectAsync();
        break;
    case 12:
        WCM_TerminateAsync();
        break;
    case 11:
        DWCi_AC_SetError(0);
        return -1;
    }
    return 0;
}


/*
 * sdk:      CloseSocket (libdwcac.TWL.HYB.a close.o, static)
 */
int CloseSocket(void)
{
    int result;

    if (SOCLiConfigPtr == 0)
        return 1;
    if (SOCL_CalmDown() != 0)
        return 0;
    result = SOC_Cleanup();
    if (result == 0 || result == -39)
        return 1;
    return 0;
}
