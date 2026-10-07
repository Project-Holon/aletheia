/*
 * function: MBi_CommEnd
 * address:  0x021F5EE4
 * packet:   pkt_ov107_021F5EE4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 *
 * symbols:
 *   OS_DisableInterrupts             0x02087988 arm
 *   MBi_EndCommon                    0x021f4684 arm
 *   MBi_IsTaskAvailable              0x021f6610 arm
 *   MBi_EndTaskThread                0x021f67bc arm
 *   MBi_CallReset                    0x021f5ea0 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   d_021F6F90                       0x021F6F90 data
 *   MBi_OnReset                      0x021f5ed8 arm
 */

#include "../../../matched/include/G_WmBase.h"

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct MBiTaskInfo_tag;

extern struct WmBase d_021F6F90;
extern u32 OS_DisableInterrupts(void);
extern void MBi_EndCommon(void *arg);
extern int MBi_IsTaskAvailable(void);
extern void MBi_EndTaskThread(void (*callback)(struct MBiTaskInfo_tag *));
extern int MBi_CallReset(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void MBi_OnReset(void);

int MBi_CommEnd(void)
{
    int ret = 1;
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (*(u8 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 0x50D) == 0) {
        MBi_EndCommon(0);
    } else if (*(u16 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 0x526) == 0) {
        *(u32 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 0x5E4) = 0;
        *(u16 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 0x526) = 1;
        if (MBi_IsTaskAvailable()) {
            MBi_EndTaskThread((void (*)(struct MBiTaskInfo_tag *))MBi_OnReset);
            ret = 0;
        } else {
            ret = MBi_CallReset();
        }
    }
    OS_RestoreInterrupts(enabled);
    return ret;
}
