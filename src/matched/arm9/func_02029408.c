/*
 * function: FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm
 * address:  0x02029408
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm.c \\
 *       --func FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm --addr 0x02029408 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_StepBgmLoad  0x020063B4  thumb
 *   GFL_NET_SetDeviceModeIfRunning  0x0203D12C  arm
 */
#include "../include/Obj04741.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);
extern void GFL_NET_SetDeviceModeIfRunning(int a);

u32 FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm(u8 *p)
{
    if (((struct Obj04741 *)p)->fC == 0) {
        return 0;
    }
    GFL_USE_StepBgmLoad((u8 *)(((struct Obj04741 *)p)->fC), (u32 *)((u32)(p + 0x14)), 1);
    ((struct Obj04741 *)p)->f10 = ((struct Obj04741 *)p)->fC;
    ((struct Obj04741 *)p)->fC = 0;
    ((struct Obj04741 *)p)->f8 = 0;
    GFL_NET_SetDeviceModeIfRunning(2);
    return 1;
}
