/*
 * file:     nwm_loaddev.c
 * unit:     yes
 * function: NWM_LoadDevice
 * address:  0x02702B08
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_loaddev.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_RegisterSleepCallback  0x02702A40  arm
 *   NWMi_ForceExit  0x02702D7C  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommand  0x02703A74  arm
 *   NWMi_CheckFirmDataParamIntegrity  0x02703C28  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 *   NWMi_PostExitInfo                 0x027341A8  data
 */
#include "../types.h"

extern u32 NWMi_CheckState(u32, ...);
extern u32 NWMi_GetSystemWork(void);
extern void DC_InvalidateRange(u32, u32);
extern u32 NWMi_CheckFirmDataParamIntegrity(void);
extern void NWMi_SetCallbackTable(u32, u32);
extern void NWMi_RegisterSleepCallback(void);
struct PMiGenCallbackInfo;
extern void PMi_InsertPostExitCallbackEx(struct PMiGenCallbackInfo *info, int priority);
extern u32 NWMi_SendCommand(unsigned short apiid, unsigned short argc, ...);
extern void NWMi_ForceExit(void);
extern u32 NWMi_PostExitInfo[];

u32 NWM_LoadDevice(u32 callback) {
    u32 base = NWMi_GetSystemWork();
    u32 st = NWMi_CheckState(1, 1);
    u32 busy;
    u32 ret;
    u32 b2;
    if (st != 0 && st != 2) {
        return st;
    }
    b2 = NWMi_GetSystemWork();
    if (b2 != 0) {
        busy = 1;
        DC_InvalidateRange(*(u32 *)(b2 + 0x2278) + 3, busy);
        if (*(u8 *)(*(u32 *)(b2 + 0x2278) + 3) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_CheckFirmDataParamIntegrity();
    NWMi_SetCallbackTable(3, callback);
    NWMi_RegisterSleepCallback();
    NWMi_PostExitInfo[0] = (u32)NWMi_ForceExit;
    NWMi_PostExitInfo[1] = 0;
    PMi_InsertPostExitCallbackEx((struct PMiGenCallbackInfo *)NWMi_PostExitInfo, 0xFFFF);
    ret = NWMi_SendCommand(3, 4, *(u32 *)(base + 0x2274), *(u32 *)(base + 0x2278), *(u32 *)(base + 0x227C), 0);
    if (ret == 0 || ret == 2) {
        ret = 2;
    }
    return ret;
}
