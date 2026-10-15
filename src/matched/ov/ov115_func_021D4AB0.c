/*
 * function: WIFILOGIN_DISP_StepCallSync
 * address:  0x021D4AB0
 * packet:   pkt_ov115_021D4AB0
 * region:   ov115
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFILOGIN_COMMON_SetStateHandler  0x021D426C  thumb  ov115
 *   WIFILOGIN_MSG_RedrawBorder  0x021D5F7C  thumb  ov115
 *   WIFILOGIN_MSG_CloseMessage  0x021D5D3C  thumb  ov115
 *   WIFILOGIN_MSG_RedrawWindow  0x021D5C94  thumb  ov115
 *   WIFILOGIN_MSG_PrintMessage  0x021D5ED8  thumb  ov115
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   func_0200FBB0  0x0200FBB0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   WIFILOGIN_DISP_StepStartWipe  0x021D4B3C  thumb  ov115
 *   WIFILOGIN_DISP_StepConfirmConsole  0x021D460C  thumb  ov115
 */
#include "../include/Obj02825.h"

extern void WIFILOGIN_COMMON_SetStateHandler(unsigned char *p, unsigned int v);
extern void WIFILOGIN_MSG_RedrawBorder(unsigned char *p);
extern void WIFILOGIN_MSG_CloseMessage(unsigned char *p);
extern void WIFILOGIN_MSG_RedrawWindow(unsigned char *p);
extern void WIFILOGIN_MSG_PrintMessage(unsigned char *p, unsigned int n);
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_0200FBB0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_ClearErrorMode(void);
extern void WIFILOGIN_DISP_StepStartWipe(u8 *p);
extern void WIFILOGIN_DISP_StepConfirmConsole(u8 *p);

void WIFILOGIN_DISP_StepCallSync(unsigned char *a)
{
    int r;

    if (*(int *)(((struct Obj02825 *)a)->f40 + 0x20) != 0 &&
        *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) == 0) {
        r = ((int (*)(int, int)) * (int *)(*(int *)(a + 0x40) + 0x20))(
            ((struct Obj02825 *)a)->f38, *(int *)(((struct Obj02825 *)a)->f40 + 0x24));
        if (r == 2)
            return;
        switch (r) {
        case 0:
            *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) = 0;
            WIFILOGIN_COMMON_SetStateHandler(a, (int)WIFILOGIN_DISP_StepStartWipe);
            break;
        case 1:
            *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) = 1;
            WIFILOGIN_MSG_RedrawBorder((unsigned char *)(((struct Obj02825 *)a)->f38));
            WIFILOGIN_MSG_CloseMessage((unsigned char *)(((struct Obj02825 *)a)->f38));
            WIFILOGIN_MSG_RedrawWindow((unsigned char *)(((struct Obj02825 *)a)->f38));
            if (GFL_NET_GetRunState() != 0)
                func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            WIFILOGIN_MSG_PrintMessage((unsigned char *)(((struct Obj02825 *)a)->f38), 0x25);
            WIFILOGIN_COMMON_SetStateHandler(a, (int)WIFILOGIN_DISP_StepConfirmConsole);
            break;
        }
    } else {
        WIFILOGIN_COMMON_SetStateHandler(a, (int)WIFILOGIN_DISP_StepStartWipe);
    }
}
