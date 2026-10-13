/*
 * function: DisConnectAP
 * address:  0x0205B264
 * packet:   pkt_0205B264
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021656A0 0x021656A0 arm
 *   WCM_Finish 0x02164EE0 arm
 *   WCM_CleanupAsync 0x02165088 arm
 *   WCM_EndSearchAsync 0x02165204 arm
 *   WCM_DisconnectAsync 0x02165478 arm
 *   WCM_TerminateAsync 0x02165560 arm
 *   func_0205C2E4 0x0205C2E4 arm
 */

extern int func_021656A0(void);
extern void WCM_Finish(void);
extern void WCM_CleanupAsync(void);
extern void WCM_EndSearchAsync(void);
extern void WCM_DisconnectAsync(void);
extern void WCM_TerminateAsync(void);
extern void func_0205C2E4(int error);

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
        func_0205C2E4(0);
        return -1;
    }
    return 0;
}
