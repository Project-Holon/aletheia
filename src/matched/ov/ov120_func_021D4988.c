/*
 * function: GTSNEGO_DISP_HandleTradeKeys
 * address:  0x021D4988
 * packet:   pkt_ov120_021D4988
 * region:   ov120
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker resolved: the call to GFL_NET_STATE_GetWifiState (site +0050) was the only
 *          unresolved relocation.  It is an unlabelled ARM leaf in the ARM9
 *          image; it was matched in arm9 (src/matched/GFL_NET_STATE_GetWifiState.c, shard
 *          pkt_0203C3EC) so `attest_matched` now resolves the BL field.  All
 *          17 relocations and all 152 bytes agree.
 * symbols:
 *   GTSNEGO_MSG_UpdateButtons  0x021D7C10  thumb  ov120
 *   GTSNEGO_MSG_SetDecide  0x021D8638  thumb  ov120
 *   GTSNEGO_DISP_SetStateCallback  0x021D4244  thumb  ov120
 *   GTSNEGO_MSG_DeleteWindow  0x021D7B38  thumb  ov120
 *   GTSNEGO_MSG_PrintWindowB  0x021D7A74  thumb  ov120
 *   GTSNEGO_MSG_DeleteConfirmWindow  0x021D8648  thumb  ov120
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   func_020355D8  0x020355D8  arm
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */
#include "../include/Obj05343.h"

typedef unsigned int u32;

extern int GTSNEGO_MSG_UpdateButtons(char *p);
extern u32 KEY_GetTrg(void);
extern void GTSNEGO_MSG_SetDecide(unsigned char *p);
extern int GFL_NET_GetRunState(void);
typedef unsigned char  u8;
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern int GFL_NET_STATE_GetWifiState(void);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GTSNEGO_MSG_DeleteWindow(char *p);
extern void GTSNEGO_MSG_PrintWindowB(u8 *p, int n);
extern void GTSNEGO_MSG_DeleteConfirmWindow(u8 *p);

void GTSNEGO_DISP_HandleTradeKeys(int *a)
{
    GTSNEGO_MSG_UpdateButtons((char *)(((struct Obj05343 *)a)->f40));
    if (KEY_GetTrg() == 2) {
        GTSNEGO_MSG_SetDecide((unsigned char *)(((struct Obj05343 *)a)->f40));
        if (GFL_NET_GetRunState() != 0)
            GFL_NET_STATE_WifiDisconnect(1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x551);
        GTSNEGO_DISP_SetStateCallback(a, 0x021D4FF5, 0x360);
    }
    if (GFL_NET_GetRunState() == 0) {
        if (KEY_GetTrg() != 1)
            return;
    } else {
        if (GFL_NET_STATE_GetWifiState() != 1)
            return;
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
    }
    GTSNEGO_MSG_DeleteWindow((char *)(((struct Obj05343 *)a)->f40));
    GTSNEGO_MSG_PrintWindowB((u8 *)(((struct Obj05343 *)a)->f40), 0x10);
    ((struct Obj05343 *)a)->f14 = 0xb4;
    GTSNEGO_MSG_DeleteConfirmWindow((u8 *)(((struct Obj05343 *)a)->f40));
    GTSNEGO_DISP_SetStateCallback(a, 0x021D4931, 0x377);
}
