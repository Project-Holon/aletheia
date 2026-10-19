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
typedef unsigned int u32;

typedef unsigned char u8;
typedef unsigned short u16;

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

extern u32 OS_DisableInterrupts(void);
extern u32 WMi_CheckInitializedAfterMeasure(void);
extern void OS_RestoreInterrupts(u32);
extern void PXI_Init(void);
extern int PXI_IsCallbackReady(int fifotag, int proc);
extern void DC_InvalidateRange(void *, u32);
extern void MIi_DmaFill32(unsigned int dmaNo, void *dest, unsigned int data, unsigned int size, int dmaEnable);
extern void DC_StoreRange(void *, u32);
extern void NWMi_ClearFifoRecvFlag(void);
struct OSMessageQueue;
extern void OS_InitMessageQueue(struct OSMessageQueue *mq, void **msgArray, int msgCount);
extern int OS_SendMessage(struct OSMessageQueue *mq, void *msg, int flags);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*)(void));
extern void NWMi_ReceiveFifo9(void);
extern void MI_CpuFill8(void *, u32, u32);
u32 NWM_Init(CamBuf *buf, u32 size, u32 mode);
u32 NWMi_InitCore(CamBuf *buf, u32 size, u32 mode);
u32 NWMi_CheckInitialized(void);
u32 NWMi_CheckEnableFlag(void);
extern CamBuf *NWMi_SysWorkPtr;
extern u8 data_027341A0[];
extern int OS_IsAvailableWireless(void);
extern int OS_IsForceDisableWireless(void);


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
    if (((u32)buf & 0x1f) != 0) {
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
    PXI_SetFifoRecvCallback(0x16, NWMi_ReceiveFifo9);
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
