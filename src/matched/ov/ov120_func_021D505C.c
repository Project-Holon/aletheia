/*
 * function: GTSNEGO_DISP_OnDisconnectCallback
 * address: 0x021D505C
 * packet: pkt_ov120_021D505C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_HandleTradeKeys 0x021D4988 thumb ov120
 *   GTSNEGO_MSG_SetDecide 0x021D8638 thumb ov120
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_OnDisconnect 0x021D4FF4 thumb ov120
 */
#include "../include/Obj13931.h"
typedef unsigned char u8;
extern void GTSNEGO_DISP_HandleTradeKeys(int);
extern void GTSNEGO_MSG_SetDecide(u8 *);
typedef unsigned int   u32;
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_OnDisconnect(u8 *p);
void GTSNEGO_DISP_OnDisconnectCallback(int a, int b, int *p)
{
    if (b == 0 && *(void (**)(int))p == GTSNEGO_DISP_HandleTradeKeys) {
        GTSNEGO_MSG_SetDecide(*(u8 * *)&((struct Obj13931 *)p)->f40);
        GFL_NET_STATE_WifiDisconnect(1);
        func_020355D8(1);
        GFL_USE_PlaySeDefaultVolume(0x551);
        GTSNEGO_DISP_SetStateCallback(p, (int)((void (*)(int))GTSNEGO_DISP_OnDisconnect), 0x5f5);
    }
}
