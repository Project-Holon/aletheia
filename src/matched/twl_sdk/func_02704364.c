/*
 * function: SNDEXi_Init
 * address:  0x02704364
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_02734450  0x02734450  data twl
 *   DAT_0273446c  0x0273446c  data twl
 *   DAT_0273448c  0x0273448c  data twl
 *   SVC_WaitByLoop  0x02004490  thumb
 *   OS_DisableInterrupts  0x02087988  arm twl
 *   OS_RestoreInterrupts  0x0208799C  arm twl
 *   PXI_Init  0x02088498  arm twl
 *   func_020885A0  0x020885A0  arm twl
 *   PXI_IsCallbackReady  0x020885EC  arm twl
 *   PMi_InsertPreSleepCallbackEx  0x0208C848  arm twl
 *   CommonCallback  0x027049B0  arm twl
 *   SetSndexWork  0x02704D48  arm twl
 *   SndexSleepAndExitCallback  0x02704D64  arm twl
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm twl
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef void (*Cb)(u32, void *);

typedef struct {
    u32 pad0;
    u32 busy;
    u32 pad8;
    volatile u32 state;
    u32 pad10;
    u32 pad14;
    u32 f18;
    void (*f1c)(void);
    u32 f20;
    u32 pad24;
    u32 pad28;
    Cb f2c;
    void *f30;
    u32 pad34;
    u32 pad38;
    void (*f3c)(void);
    u32 f40;
    u32 pad44;
    u32 pad48;
    Cb f4c;
    void *f50;
    void *f54;
    u8 f58;
} State;

extern State DAT_02734450;
extern u32 DAT_0273446c[];
extern u32 DAT_0273448c[];
extern void SVC_WaitByLoop(u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void PXI_Init(void);
extern void func_020885A0(u32, void (*)(u32, u32, u32));
extern u32 PXI_IsCallbackReady(u32, u32);
extern void PMi_InsertPreSleepCallbackEx(u32 *, u32);
void CommonCallback(u32 a0, u32 a1, u32 a2);
void SetSndexWork(Cb a0, void *a1, void *a2, u32 a3);
extern void SndexSleepAndExitCallback(void);
extern void PMi_InsertPostExitCallbackEx(u32 *, u32);

void SNDEXi_Init(void) {
    u32 irq = OS_DisableInterrupts();
    if (DAT_02734450.state != 0) {
        OS_RestoreInterrupts(irq);
        return;
    }
    DAT_02734450.state = 1;
    OS_RestoreInterrupts(irq);
    SetSndexWork(0, 0, 0, 0);
    PXI_Init();
    while (PXI_IsCallbackReady(0x18, 1) == 0) {
        SVC_WaitByLoop(10);
    }
    func_020885A0(0x18, (void (*)(u32, u32, u32))CommonCallback);
    DAT_02734450.f1c = SndexSleepAndExitCallback;
    DAT_02734450.f20 = 0;
    PMi_InsertPostExitCallbackEx(DAT_0273446c, 0xfffd);
    DAT_02734450.f3c = SndexSleepAndExitCallback;
    DAT_02734450.f40 = 0;
    PMi_InsertPreSleepCallbackEx(DAT_0273448c, 0xfffd);
    DAT_02734450.state = 2;
}
