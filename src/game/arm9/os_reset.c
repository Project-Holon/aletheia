/*
 * file:     os_reset.c
 * unit:     yes
 * function: OS_InitReset, OS_ResetSystem
 * address:  0x02087B78
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
 *   PXI_Init                 0x02088498  arm
 *   PXI_IsCallbackReady      0x020885EC  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   OSi_CommonCallback       0x02084A38  arm
 *   OSi_IsInitReset          0x02151368  data
 *   OS_IsRunOnTwl                    0x02085D3C  arm
 *   OS_Terminate                     0x02088234  arm
 *   PMi_ExecutePostExitCallbackList  0x027315A8  arm
 *   OS_GetLockID                     0x02084EB8  arm
 *   CARD_LockRom                     0x02075E10  arm
 *   OS_SetIrqMask                    0x0208493C  arm
 *   OS_ResetRequestIrqMask           0x020849C8  arm
 *   MI_StopAllDma                    0x02082658  arm
 *   MI_StopAllNDma                   0x0272FD18  arm
 *   OSi_SendToPxi                    0x02084A84  arm
 *   OSi_DoResetSystem                0x01FF8414  arm
 */
#include "../types.h"

#include "../sdk_os.h"

#include "pxi_fifo.h"
#include "os_pxi.h"
#include "os_emulator.h"
#include "os_terminate_processor.h"
#include "../twl/pm.h"
#include "os_spinlock.h"
#include "card_api.h"
#include "os_interrupt.h"
#include "mi_dma.h"
#include "../twl/mi_ndma.h"
#include "../arm9_autoload0_ITCM/os_reset.h"
void OS_InitReset(void);
void OS_ResetSystem(u32 parameter);
extern char SDK_AUTOLOAD_DTCM_START[];
extern u16 OSi_IsInitReset;

/*
 * sdk:      OS_InitReset (os_reset.o)
 */
void OS_InitReset(void)
{
    if (OSi_IsInitReset) {
        return;
    }
    OSi_IsInitReset = 1;

    PXI_Init();
    while (!PXI_IsCallbackReady(12, 1)) {
    }
    PXI_SetFifoRecvCallback(12, OSi_CommonCallback);
}

/*
 * sdk:      OS_ResetSystem (os_reset.o)
 */
void OS_ResetSystem(u32 parameter)
{
    if (*(u16 *)0x02FFFC40 == 2
        || (OS_IsRunOnTwl() == 1 && (*(u32 *)0x02FFE234 & 4))) {
        OS_Terminate();
    }

    if (OS_IsRunOnTwl()) {
        PMi_ExecutePostExitCallbackList();
    }

    CARD_LockRom((u16)OS_GetLockID());

    (void)OS_SetIrqMask(0x40000);
    (void)OS_ResetRequestIrqMask((u32)~0);

    MI_StopAllDma();
    if (OS_IsRunOnTwl()) {
        MI_StopAllNDma();
    }

    *(u32 *)0x02FFFC20 = parameter;
    OSi_SendToPxi(0x10);
    OSi_DoResetSystem();
}
