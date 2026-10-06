/*
 * file:     unit_020898A8_p03.c
 * unit:     yes
 * function: func_02089DF8, func_02089E34, func_02089E50, func_02089E74, func_02089ED8, func_02089F00, func_02089F48
 * address:  0x02089DF8
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   sFreeList             0x0215146C  data
 *   SND_CountFreeCommand      0x02089DBC  arm
 *   SND_CountReservedCommand  0x02089DF8  arm
 *   SNDi_CallAlarmHandler  0x0208A010  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   IsCommandAvailable       0x02089F48  arm
 *   PXI_IsCallbackReady      0x020885EC  arm
 *   OS_SpinWaitSysCycles     0x02087A04  arm
 *   PxiFifoCallback          0x02089E50  arm
 *   PXI_SendWordByFifo  0x02088610  arm
 *   OS_IsRunOnEmulator    0x02085D24  arm
 */
typedef unsigned long u32;

typedef int BOOL;

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    u32 arg[4];
} SNDCommand;

/* snd_command.o's .bss statics from sFreeList on, in their laid-out order */
typedef struct {
    SNDCommand *freeList;
    u32 finishedTag;
    SNDCommand *reserveList;
    SNDCommand *reserveListEnd;
    SNDCommand *freeListEnd;
    u32 unk14;
    int waitingCommandListQueueWrite;
    int waitingCommandListCount;
    u32 currentTag;
} SNDCommandState;

typedef void (*PXIFifoCallback)(int tag, u32 data, BOOL err);

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
int SND_CountFreeCommand(void);
int SND_CountReservedCommand(void);
extern void SNDi_CallAlarmHandler(int msg);
extern void PXI_SetFifoRecvCallback(int fifotag, PXIFifoCallback callback);
extern BOOL IsCommandAvailable(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern void PxiFifoCallback(int tag, u32 data, BOOL err);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern BOOL OS_IsRunOnEmulator(void);
int func_02089DF8(void);
int func_02089E34(void);
void func_02089E50(int tag, u32 data, BOOL err);
void func_02089E74(void);
void func_02089ED8(void);
SNDCommand *func_02089F00(void);
BOOL func_02089F48(void);
extern SNDCommandState sFreeList;



/*
 * sdk:      SND_CountReservedCommand (snd_command.o)
 */
int func_02089DF8(void)
{
    unsigned long bak_psr = OS_DisableInterrupts();
    SNDCommand *command;
    int count = 0;

    for (command = sFreeList.reserveList; command != 0; command = command->next) {
        count++;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return count;
}




/*
 * note:     snd_command.o SND_CountWaitingCommand.
 */
int func_02089E34(void)
{
    int freeCount = SND_CountFreeCommand();
    int reservedCount = SND_CountReservedCommand();

    return 0x100 - freeCount - reservedCount;
}




/*
 * sdk:      PxiFifoCallback (snd_command.o)
 */
void func_02089E50(int tag, u32 data, BOOL err)
{
    unsigned long enabled = OS_DisableInterrupts();

    SNDi_CallAlarmHandler((int)data);
    (void)OS_RestoreInterrupts(enabled);
}



/*
 * sdk:      InitPXI (snd_command.o)
 */
void func_02089E74(void)
{
    PXI_SetFifoRecvCallback(7, PxiFifoCallback);

    if (IsCommandAvailable()) {
        if (!PXI_IsCallbackReady(7, 1)) {
            do {
                OS_SpinWaitSysCycles(0x32);
            } while (!PXI_IsCallbackReady(7, 1));
        }
    }
}



/*
 * sdk:      RequestCommandProc (snd_command.o)
 */
void func_02089ED8(void)
{
    while (PXI_SendWordByFifo(7, 0, 0) < 0) {
    }
}



/*
 * sdk:      AllocCommand (snd_command.o)
 */
SNDCommand *func_02089F00(void)
{
    unsigned long bak_psr = OS_DisableInterrupts();
    SNDCommand *command = sFreeList.freeList;

    if (command == 0) {
        (void)OS_RestoreInterrupts(bak_psr);
        return 0;
    }
    sFreeList.freeList = command->next;
    if (sFreeList.freeList == 0) {
        sFreeList.freeListEnd = 0;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return command;
}



#define REG_EMU_COMMAND (*(volatile u32 *)0x04FFF200)



/*
 * sdk:      IsCommandAvailable (snd_command.o)
 */
BOOL func_02089F48(void)
{
    unsigned long prev_mode;
    u32 res;

    if (!OS_IsRunOnEmulator()) {
        return 1;
    }
    prev_mode = OS_DisableInterrupts();
    REG_EMU_COMMAND = 0x10;
    res = REG_EMU_COMMAND;
    (void)OS_RestoreInterrupts(prev_mode);
    return (res != 0) ? 1 : 0;
}
