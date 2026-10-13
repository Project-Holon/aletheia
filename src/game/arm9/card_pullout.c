/*
 * file:     card_pullout.c
 * unit:     yes
 * function: func_020773DC, func_02077410, func_020774A0, func_020774B0, func_020774C0, func_02077518, func_02077568
 * address:  0x020773DC
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
 *   PXI_Init  0x02088498  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   CARDiSlotResetCount  0x02150B00  data
 *   CARDi_PulledOutCallback  0x02077410  arm
 *   CARDi_NotifyEvent  0x02076100  arm
 *   CARD_TerminateForPulledOut  0x020774C0  arm
 *   OS_Terminate  0x02088234  arm
 *   s_data_02150B00  0x02150B00  data
 *   PM_ForceToPowerOff  0x0208BEA4  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   PMi_ExecutePostExitCallbackList  0x027315A8  arm
 *   CARDi_SendtoPxi  0x02077568  arm
 *   MI_StopAllDma  0x02082658  arm
 *   MI_StopAllNDma  0x0272FD18  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02088610 0x02088610  arm
 *   func_02004490 0x02004490  thumb
 */
typedef unsigned long u32_020773DC;

typedef int BOOL;

struct CARDPulledOutState_020773DC {
    u32_020773DC slot_reset_count;
    BOOL is_pulled_out;
    BOOL (*callback)(void);
};

typedef unsigned long u32_02077410;

struct CARDPulledOutState_02077410 {
    u32_02077410 slot_reset_count;
    BOOL is_pulled_out;
    BOOL (*callback)(void);
};

struct CARDPulledOutState_020774A0 {
    unsigned long slot_reset_count;
    int is_pulled_out;
    int (*callback)(void);
};

struct Data02150B00 {
    void *unk00;
    void *unk04;
};

typedef unsigned short u16;

typedef unsigned long u32_020774C0;

typedef unsigned long u32_02077518;

typedef volatile u32_02077518 vu32;

typedef unsigned int u32_02077568;

extern void PXI_Init(void);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32_020773DC, BOOL));
extern void CARDi_PulledOutCallback(int tag, u32_020773DC data, BOOL err);
extern void CARDi_NotifyEvent(u32_02077410 event, void *arg);
extern void CARD_TerminateForPulledOut(void);
extern void OS_Terminate(void);
extern u32_020774C0 PM_ForceToPowerOff(void);
extern BOOL OS_IsRunOnTwl(void);
extern void PMi_ExecutePostExitCallbackList(void);
extern void CARDi_SendtoPxi(u32_020774C0 data, u32_020774C0 wait);
extern void MI_StopAllDma(void);
extern void MI_StopAllNDma(void);
extern u32_02077518 OS_DisableInterrupts(void);
extern u32_02077518 OS_RestoreInterrupts(u32_02077518 state);
extern u32_02077568  func_02088610(u32_02077568, u32_02077568, u32_02077568);
extern void func_02004490(u32_02077568);
void func_020773DC(void);
void func_02077410(int tag, u32_02077410 data, BOOL err);
void func_020774A0(int (*callback)(void));
void *func_020774B0(void);
void func_020774C0(void);
void func_02077518(u32_02077518 id);
void func_02077568(u32_02077568 a, u32_02077568 b);
extern struct CARDPulledOutState_020773DC CARDiSlotResetCount;
extern struct Data02150B00 s_data_02150B00;


/*
 * sdk:      CARD_InitPulledOutCallback (libcard.TWL.HYB.a card_pullout.o)
 */
void func_020773DC(void)
{
    PXI_Init();
    CARDiSlotResetCount.slot_reset_count = 0;
    CARDiSlotResetCount.is_pulled_out = 0;
    PXI_SetFifoRecvCallback(14, CARDi_PulledOutCallback);
    CARDiSlotResetCount.callback = 0;
}


/*
 * sdk:      CARDi_PulledOutCallback (libcard.TWL.HYB.a card_pullout.o)
 */
void func_02077410(int tag, u32_02077410 data, BOOL err)
{
#pragma unused(tag, err)
    u32_02077410 command = data & 0x3F;

    if (command == 0x11)
    {
        if (!CARDiSlotResetCount.is_pulled_out)
        {
            BOOL isTerminateImm = 1;

            CARDiSlotResetCount.is_pulled_out = 1;
            CARDi_NotifyEvent(1, 0);
            if (CARDiSlotResetCount.callback)
            {
                isTerminateImm = (*CARDiSlotResetCount.callback)();
            }
            if (isTerminateImm)
            {
                CARD_TerminateForPulledOut();
            }
        }
    }
    else if (command == 2)
    {
        CARDiSlotResetCount.slot_reset_count++;
        CARDiSlotResetCount.is_pulled_out = 0;
        CARDi_NotifyEvent(2, 0);
    }
    else
    {
        OS_Terminate();
    }
}


/*
 * sdk:      CARD_SetPulledOutCallback (libcard.TWL.HYB.a card_pullout.o)
 */
void func_020774A0(int (*callback)(void))
{
    CARDiSlotResetCount.callback = callback;
}


void *func_020774B0(void)
{
    return s_data_02150B00.unk04;
}


/*
 * sdk:      CARD_TerminateForPulledOut (libcard.TWL.HYB.a card_pullout.o)
 */
void func_020774C0(void)
{
    if ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15)
    {
        (void)PM_ForceToPowerOff();
    }
    if (OS_IsRunOnTwl())
    {
        PMi_ExecutePostExitCallbackList();
    }
    CARDi_SendtoPxi(1, 1);
    MI_StopAllDma();
    if (OS_IsRunOnTwl())
    {
        MI_StopAllNDma();
    }
    OS_Terminate();
}


/*
 * sdk:      CARDi_CheckPulledOutCore (libcard.TWL.HYB.a card_pullout.o)
 */
void func_02077518(u32_02077518 id)
{
    vu32 iplCardID = *(u32_02077518 *)0x02FFFC00;

    if (id != iplCardID)
    {
        u32_02077518 bak_cpsr = OS_DisableInterrupts();

        CARDi_PulledOutCallback(14, 0x11, 0);
        (void)OS_RestoreInterrupts(bak_cpsr);
    }
}


/*
 * The verdict is EXACT*: 0x02077568 is the last labelled function in the
 * block and its follower has no label (it is the unlabelled save at
 * 0x020775B8, see docs/notes/pkt_02077568.c.txt), so the inferred extent runs
 * to 0x02077634.  Nothing in the compared bytes differs.
 *
 * The two constants are held in locals across the loop, which is what puts the
 * 0xe in r5 and the 0 in r4 for the tail probe while the entry probe still
 * materialises both as immediates.  The loop tests at the bottom, so it is a
 * do/while and not the obvious while.
 */
void func_02077568(u32_02077568 a, u32_02077568 b)
{
    u32_02077568 n = 0xe;
    u32_02077568 z = 0;

    if (func_02088610(n, a, z) == 0) return;
    do {
        func_02004490(b);
    } while (func_02088610(n, a, z) != 0);
}
