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
    u16 f280;
} CamBuf;

extern u32 func_02087988(void);
extern u32 WMi_CheckInitializedAfterMeasure(void);
extern void func_0208799C(u32);
extern void PXI_Init(void);
extern u32 func_020885EC(u32, u32);
extern void func_020862B8(void *, u32);
extern void func_020821C0(u32, void *, u32, u32, u32);
extern void func_020862D4(void *, u32);
extern void NWMi_ClearFifoRecvFlag(void);
extern void func_02085D94(void *, void *, u32);
extern void func_02085DBC(void *, void *, u32);
extern void func_020885A0(u32, void (*)(void));
extern void NWMi_ReceiveFifo9(void);
extern void func_02082BCC(void *, u32, u32);
u32 NWM_Init(CamBuf *buf, u32 size, u32 mode);
u32 NWMi_InitCore(CamBuf *buf, u32 size, u32 mode);
u32 NWMi_CheckInitialized(void);
u32 NWMi_CheckEnableFlag(void);
extern CamBuf *data_027341A4;
extern u8 data_027341A0[];
extern u32 func_02087DC4(void);
extern u32 func_02087E84(void);


u32 NWM_Init(CamBuf *buf, u32 size, u32 mode) {
    if (NWMi_CheckEnableFlag() == 0) {
        return 4;
    }
    return NWMi_InitCore(buf, size, mode);
}

u32 NWMi_InitCore(CamBuf *buf, u32 size, u32 mode) {
    u32 irq = func_02087988();
    int i;
    if (WMi_CheckInitializedAfterMeasure() == 0) {
        func_0208799C(irq);
        return 3;
    }
    if (data_027341A0[0] != 0) {
        func_0208799C(irq);
        return 3;
    }
    if (buf == 0) {
        func_0208799C(irq);
        return 5;
    }
    if (mode > 3) {
        func_0208799C(irq);
        return 5;
    }
    if (((u32)buf & 0x1f) != 0) {
        func_0208799C(irq);
        return 5;
    }
    PXI_Init();
    if (func_020885EC(0x16, 1) == 0) {
        func_0208799C(irq);
        return 4;
    }
    func_020862B8(buf, size);
    func_020821C0(mode, buf, 0, size, 1);
    data_027341A4 = buf;
    func_020862D4(&data_027341A4, 4);
    data_027341A4->p274 = (u8 *)data_027341A4 + 0x22e0;
    data_027341A4->ring = (CamRing *)(data_027341A4->p274 + 0x20);
    data_027341A4->p27c = (u8 *)data_027341A4->ring + 0xc0;
    NWMi_ClearFifoRecvFlag();
    data_027341A4->f280 = mode;
    func_02085D94(data_027341A4->ctlA, data_027341A4->ctlB, 0x20);
    for (i = 0; i < 0x20; i++) {
        data_027341A4->lines[i][0] = 0x8000;
        func_020862D4(data_027341A4->lines[i], 2);
        func_02085DBC(data_027341A4->ctlA, data_027341A4->lines[i], 1);
    }
    func_020885A0(0x16, NWMi_ReceiveFifo9);
    func_02082BCC(data_027341A4->state, 0, 0x154);
    data_027341A0[0] = 1;
    data_027341A4->ring->ready = 1;
    func_020862D4(data_027341A4, 0x22e0);
    func_020862D4((void *)0x27341a0, 1);
    func_0208799C(irq);
    return 0;
}

u32 NWMi_CheckInitialized(void) {
    if (data_027341A0[0] != 0) {
        return 0;
    }
    return 3;
}

u32 NWMi_CheckEnableFlag(void) {
    if (func_02087DC4() == 1) {
        if (func_02087E84() == 0) {
            return 1;
        }
    }
    return 0;
}
