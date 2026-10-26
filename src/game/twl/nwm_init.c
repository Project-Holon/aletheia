/*
 * file:     nwm_init.c
 * unit:     yes
 * function: NWM_Init, NWMi_InitCore, NWMi_CheckInitialized, NWMi_CheckEnableFlag
 * address:  0x02702434
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_init.o
 *
 *
 * symbols:
 *   NWMi_ClearFifoRecvFlag  0x027026EC  arm
 *   NWMi_ReceiveFifo9  0x02702740  arm
 *   PXI_Init  0x02088498  arm  arm9
 *   WMi_CheckInitializedAfterMeasure  0x02090ECC  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   PXI_IsCallbackReady  0x020885EC  arm  arm9
 *   MIi_DmaFill32  0x020821C0  arm  arm9
 *   OS_InitMessageQueue  0x02085D94  arm  arm9
 *   OS_SendMessage  0x02085DBC  arm  arm9
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 *   OS_IsAvailableWireless  0x02087DC4  arm  arm9
 *   PXI_SetFifoRecvCallback  0x020885A0  arm  arm9
 *   OS_IsForceDisableWireless  0x02087E84  arm  arm9
 *   data_027341A0                0x027341A0  data
 *   NWMi_SysWorkPtr                0x027341A4  data
 */
#include "../types.h"

typedef struct CamRing {
    u8 pad0[0x24];
    u16 ready;
} CamRing;

typedef struct CamBuf {
    u16 lines[0x20][0x80];
    u8 ctlA[0x20];
    u8 ctlB[0x100];
    u8 state[0x154];
    u8 *p274;
    CamRing *ring;
    u8 *p27c;
    u16 dmaNo;
} CamBuf;

#include "../arm9/os_system.h"
#include "../arm9/wm_etc.h"
#include "../arm9/pxi_fifo.h"
#include "../arm9/os_cache.h"
#include "../arm9/mi_dma.h"
#include "nwm_system.h"
#include "../sdk_os.h"

#include "../arm9/os_message.h"
#include "../arm9/mi_memory.h"
u32 NWM_Init(CamBuf *buf, u32 size, u32 mode);
u32 NWMi_InitCore(CamBuf *buf, u32 size, u32 mode);
u32 NWMi_CheckInitialized(void);
u32 NWMi_CheckEnableFlag(void);
extern CamBuf *NWMi_SysWorkPtr;
extern u8 data_027341A0[];
#include "../arm9/os_ownerinfoex.h"

#ifndef __MWERKS__
static void NWMi_ReceiveFifo9Pxi(int tag, u32 data, BOOL err)
{
    NWMi_ReceiveFifo9(tag, (Msg *)(uptr)data, err);
}
#endif

u32 NWM_Init(CamBuf *buf, u32 size, u32 mode) {
    if (NWMi_CheckEnableFlag() == 0) {
        return 4;
    }
    return NWMi_InitCore(buf, size, mode);
}

u32 NWMi_InitCore(CamBuf *buf, u32 size, u32 mode) {
    u32 irq = OS_DisableInterrupts();
    int i;
    if (WMi_CheckInitializedAfterMeasure() == 0) {
        OS_RestoreInterrupts(irq);
        return 3;
    }
    if (data_027341A0[0] != 0) {
        OS_RestoreInterrupts(irq);
        return 3;
    }
    if (buf == 0) {
        OS_RestoreInterrupts(irq);
        return 5;
    }
    if (mode > 3) {
        OS_RestoreInterrupts(irq);
        return 5;
    }
    if (((uptr)buf & 0x1f) != 0) {
        OS_RestoreInterrupts(irq);
        return 5;
    }
    PXI_Init();
    if (PXI_IsCallbackReady(0x16, 1) == 0) {
        OS_RestoreInterrupts(irq);
        return 4;
    }
    DC_InvalidateRange(buf, size);
    MIi_DmaFill32(mode, buf, 0, size, 1);
    NWMi_SysWorkPtr = buf;
    DC_StoreRange(&NWMi_SysWorkPtr, 4);
    NWMi_SysWorkPtr->p274 = (u8 *)NWMi_SysWorkPtr + 0x22e0;
    NWMi_SysWorkPtr->ring = (CamRing *)(NWMi_SysWorkPtr->p274 + 0x20);
    NWMi_SysWorkPtr->p27c = (u8 *)NWMi_SysWorkPtr->ring + 0xc0;
    NWMi_ClearFifoRecvFlag();
    NWMi_SysWorkPtr->dmaNo = mode;
    OS_InitMessageQueue((struct OSMessageQueue *)NWMi_SysWorkPtr->ctlA, (void **)NWMi_SysWorkPtr->ctlB, 0x20);
    for (i = 0; i < 0x20; i++) {
        NWMi_SysWorkPtr->lines[i][0] = 0x8000;
        DC_StoreRange(NWMi_SysWorkPtr->lines[i], 2);
        OS_SendMessage((struct OSMessageQueue *)NWMi_SysWorkPtr->ctlA, NWMi_SysWorkPtr->lines[i], 1);
    }
#ifdef __MWERKS__
    PXI_SetFifoRecvCallback(0x16, (PXIFifoCallback)NWMi_ReceiveFifo9);
#else
    PXI_SetFifoRecvCallback(0x16, NWMi_ReceiveFifo9Pxi);
#endif
    MI_CpuFill8(NWMi_SysWorkPtr->state, 0, 0x154);
    data_027341A0[0] = 1;
    NWMi_SysWorkPtr->ring->ready = 1;
    DC_StoreRange(NWMi_SysWorkPtr, 0x22e0);
    DC_StoreRange((void *)0x27341a0, 1);
    OS_RestoreInterrupts(irq);
    return 0;
}

u32 NWMi_CheckInitialized(void) {
    if (data_027341A0[0] != 0) {
        return 0;
    }
    return 3;
}

u32 NWMi_CheckEnableFlag(void) {
    if (OS_IsAvailableWireless() == 1) {
        if (OS_IsForceDisableWireless() == 0) {
            return 1;
        }
    }
    return 0;
}
