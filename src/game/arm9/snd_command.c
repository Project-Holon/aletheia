/*
 * file:     snd_command.c
 * unit:     yes
 * function: SND_CommandInit, SND_RecvCommandReply, SND_AllocCommand, SND_PushCommand, SND_FlushCommand, SND_WaitForCommandProc, SND_GetCurrentCommandTag, SND_IsFinishedCommandTag, SND_CountFreeCommand, SND_CountReservedCommand, SND_CountWaitingCommand, PxiFifoCallback, InitPXI, RequestCommandProc, AllocCommand, IsCommandAvailable
 * address:  0x020898A8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libsnd snd_command.o (.comment stamp 4.0.0.1024, dsi/1.1p1), with the
 * sound init function in front of it.
 *
 * symbols:
 *   InitPXI                          0x02089E74 arm
 *   SNDi_InitSharedWork              0x0208A1D0 arm
 *   SND_AllocCommand                 0x02089A78 arm
 *   SND_PushCommand                  0x02089B00 arm
 *   SND_FlushCommand                 0x02089B38 arm
 *   sCommandArray                    0x02151740 data
 *   sSharedWork                      0x021514C0 data
 *   SNDi_SharedWork                  0x02152FA0 data
 *   OS_DisableInterrupts        0x02087988  arm
 *   SNDi_GetFinishedCommandTag  0x0208A1AC  arm
 *   OS_RestoreInterrupts        0x0208799C  arm
 *   OS_SpinWaitSysCycles        0x02087A04  arm
 *   sFreeList                   0x0215146C  data
 *   sWaitingCommandListQueue    0x02151490  data
 *   IsCommandAvailable       0x02089F48  arm
 *   AllocCommand             0x02089F00  arm
 *   SND_CountWaitingCommand  0x02089E34  arm
 *   SND_RecvCommandReply     0x02089978  arm
 *   RequestCommandProc       0x02089ED8  arm
 *   DC_FlushRange             0x020862F0  arm
 *   PXI_SendWordByFifo        0x02088610  arm
 *   SND_IsFinishedCommandTag  0x02089D6C  arm
 *   SND_CountFreeCommand      0x02089DBC  arm
 *   SND_CountReservedCommand  0x02089DF8  arm
 *   SNDi_CallAlarmHandler  0x0208A010  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   PXI_IsCallbackReady      0x020885EC  arm
 *   PxiFifoCallback          0x02089E50  arm
 *   OS_IsRunOnEmulator    0x02085D24  arm
 */
#define SND_COMMAND_BLOCK            0x1
#define SND_COMMAND_IMMEDIATE        0x2
#define SND_PXI_FIFO_MESSAGE_BUFSIZE 8
#define SND_COMMAND_NUM              256
#define PXI_FIFO_TAG_SOUND           7

#include "../types.h"
#include "../sdk_os.h"

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    u32 arg[4];
} SNDCommand;

#include "snd_shared_types.h"

/* snd_command.o's .bss statics from sFreeList on, in their laid-out order */
typedef struct {
    SNDCommand *freeList;
    u32 finishedTag;
    SNDCommand *reserveList;
    SNDCommand *reserveListEnd;
    SNDCommand *freeListEnd;
    int waitingCommandListQueueRead;
    int waitingCommandListQueueWrite;
    int waitingCommandListCount;
    u32 currentTag;
} SNDCommandState;

typedef void (*PXIFifoCallback)(int tag, u32 data, BOOL err);

extern void InitPXI(void);
extern void SNDi_InitSharedWork(SNDSharedWork *work);
extern SNDCommand *SND_AllocCommand(u32 flags);
extern void SND_PushCommand(SNDCommand *command);
extern BOOL SND_FlushCommand(u32 flags);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern u32 SNDi_GetFinishedCommandTag(void);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern BOOL IsCommandAvailable(void);
extern SNDCommand *AllocCommand(void);
extern int SND_CountWaitingCommand(void);
extern const SNDCommand *SND_RecvCommandReply(u32 flags);
extern void RequestCommandProc(void);
extern void DC_FlushRange(const void *startAddr, u32 nBytes);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern BOOL SND_IsFinishedCommandTag(u32 tag);
extern int SND_CountFreeCommand(void);
extern int SND_CountReservedCommand(void);
extern void SNDi_CallAlarmHandler(int msg);
extern void PXI_SetFifoRecvCallback(int fifotag, PXIFifoCallback callback);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void PxiFifoCallback(int tag, u32 data, BOOL err);
extern BOOL OS_IsRunOnEmulator(void);
void SND_CommandInit(void);
void SND_WaitForCommandProc(u32 tag);
u32 SND_GetCurrentCommandTag(void);
extern SNDCommandState sFreeList;
extern SNDCommand sCommandArray[SND_COMMAND_NUM];
extern SNDSharedWork sSharedWork;
extern SNDSharedWork *SNDi_SharedWork;
extern SNDCommand *sWaitingCommandListQueue[SND_PXI_FIFO_MESSAGE_BUFSIZE + 1];

/*
 * sdk:      SND_CommandInit (libsnd.TWL.HYB.a snd_command.o)
 *           The free-list loop is entered with a b to its bottom test and the constant
 *           first test is not folded; the loop condition written as `(c) ? 1 : 0` keeps
 *           that form (docs/idioms/a-loop-entered-by-a-branch-to-its-bottom-test-has-a-ternary-condition.md).
 *           snd_command.o .bss is one block addressed from the sFreeList pool word:
 *           +0 freeList, +4 finishedTag, +8 reserveList, +0xC reserveListEnd,
 *           +0x10 freeListEnd, +0x14 queueRead, +0x18 queueWrite, +0x1C waitingCount,
 *           +0x20 currentTag.
 */
void SND_CommandInit(void)
{
    SNDCommand *command;
    int i;

    InitPXI();

    sFreeList.freeList = &sCommandArray[0];
    for (i = 0; (i < SND_COMMAND_NUM - 1) ? 1 : 0; i++) {
        sCommandArray[i].next = &sCommandArray[i + 1];
    }
    sCommandArray[SND_COMMAND_NUM - 1].next = 0;
    sFreeList.freeListEnd = &sCommandArray[SND_COMMAND_NUM - 1];

    sFreeList.reserveList = 0;
    sFreeList.reserveListEnd = 0;

    sFreeList.waitingCommandListCount = 0;
    sFreeList.waitingCommandListQueueRead = 0;
    sFreeList.waitingCommandListQueueWrite = 0;

    sFreeList.currentTag = 1;
    sFreeList.finishedTag = 0;

    SNDi_SharedWork = &sSharedWork;
    SNDi_InitSharedWork(SNDi_SharedWork);

    command = SND_AllocCommand(1);
    if (command == 0) {
        return;
    }
    command->id = 0x1d;
    command->arg[0] = (u32)SNDi_SharedWork;
    SND_PushCommand(command);
    (void)SND_FlushCommand(1);
}

/*
 * sdk:      SND_RecvCommandReply (snd_command.o)
 */
const SNDCommand *SND_RecvCommandReply(u32 flags)
{
    OSIntrMode bak_psr;
    SNDCommand *commandList;
    SNDCommand *commandListEnd;

    bak_psr = OS_DisableInterrupts();

    if (flags & SND_COMMAND_BLOCK) {
        while (sFreeList.finishedTag == SNDi_GetFinishedCommandTag()) {
            (void)OS_RestoreInterrupts(bak_psr);
            OS_SpinWaitSysCycles(0x32);
            bak_psr = OS_DisableInterrupts();
        }
    } else {
        if (sFreeList.finishedTag == SNDi_GetFinishedCommandTag()) {
            (void)OS_RestoreInterrupts(bak_psr);
            return 0;
        }
    }

    commandList = sWaitingCommandListQueue[sFreeList.waitingCommandListQueueRead];
    sFreeList.waitingCommandListQueueRead++;
    if (sFreeList.waitingCommandListQueueRead > SND_PXI_FIFO_MESSAGE_BUFSIZE) {
        sFreeList.waitingCommandListQueueRead = 0;
    }

    commandListEnd = commandList;
    while (commandListEnd->next != 0) {
        commandListEnd = commandListEnd->next;
    }

    if (sFreeList.freeListEnd != 0) {
        sFreeList.freeListEnd->next = commandList;
    } else {
        sFreeList.freeList = commandList;
    }
    sFreeList.freeListEnd = commandListEnd;

    sFreeList.waitingCommandListCount--;
    sFreeList.finishedTag++;

    (void)OS_RestoreInterrupts(bak_psr);
    return commandList;
}

/*
 * sdk:      SND_AllocCommand (snd_command.o)
 */
SNDCommand *SND_AllocCommand(u32 flags)
{
    SNDCommand *command;

    if (!IsCommandAvailable()) {
        return 0;
    }
    command = AllocCommand();
    if (command != 0) {
        return command;
    }
    if ((flags & SND_COMMAND_BLOCK) == 0) {
        return 0;
    }
    if (SND_CountWaitingCommand() > 0) {
        while (SND_RecvCommandReply(0) != 0) {
        }
        command = AllocCommand();
        if (command != 0) {
            return command;
        }
    } else {
        (void)SND_FlushCommand(SND_COMMAND_BLOCK);
    }
    RequestCommandProc();
    do {
        (void)SND_RecvCommandReply(SND_COMMAND_BLOCK);
        command = AllocCommand();
    } while (command == 0);
    return command;
}

/*
 * sdk:      SND_PushCommand (snd_command.o)
 */
void SND_PushCommand(SNDCommand *command)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();

    if (sFreeList.reserveListEnd == 0) {
        sFreeList.reserveList = command;
        sFreeList.reserveListEnd = command;
    } else {
        sFreeList.reserveListEnd->next = command;
        sFreeList.reserveListEnd = command;
    }
    command->next = 0;
    (void)OS_RestoreInterrupts(bak_psr);
}

/*
 * sdk:      SND_FlushCommand (snd_command.o)
 * Hands the reserved command list to the ARM7 over the sound FIFO: waits
 * (SND_COMMAND_BLOCK) or fails when the waiting queue is full or the FIFO
 * send fails, then queues the list, clears the reserve list, bumps the tag
 * and, with SND_COMMAND_IMMEDIATE, requests immediate processing.
 */
BOOL SND_FlushCommand(u32 flags)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();

    if (sFreeList.reserveList == 0) {
        (void)OS_RestoreInterrupts(bak_psr);
        return 1;
    }

    if (sFreeList.waitingCommandListCount >= SND_PXI_FIFO_MESSAGE_BUFSIZE) {
        if ((flags & SND_COMMAND_BLOCK) == 0) {
            (void)OS_RestoreInterrupts(bak_psr);
            return 0;
        }
        do {
            (void)SND_RecvCommandReply(SND_COMMAND_BLOCK);
        } while (sFreeList.waitingCommandListCount >= SND_PXI_FIFO_MESSAGE_BUFSIZE);

        if (sFreeList.reserveList == 0) {
            (void)OS_RestoreInterrupts(bak_psr);
            return 1;
        }
    }

    DC_FlushRange(sCommandArray, sizeof(sCommandArray));

    if (PXI_SendWordByFifo(PXI_FIFO_TAG_SOUND, (u32)sFreeList.reserveList, 0) < 0) {
        if ((flags & SND_COMMAND_BLOCK) == 0) {
            (void)OS_RestoreInterrupts(bak_psr);
            return 0;
        }
        while (sFreeList.waitingCommandListCount >= SND_PXI_FIFO_MESSAGE_BUFSIZE ||
               PXI_SendWordByFifo(PXI_FIFO_TAG_SOUND, (u32)sFreeList.reserveList, 0) < 0) {
            (void)OS_RestoreInterrupts(bak_psr);
            (void)SND_RecvCommandReply(0);
            bak_psr = OS_DisableInterrupts();
            DC_FlushRange(sCommandArray, sizeof(sCommandArray));
            if (sFreeList.reserveList == 0) {
                (void)OS_RestoreInterrupts(bak_psr);
                return 1;
            }
        }
    }

    sWaitingCommandListQueue[sFreeList.waitingCommandListQueueWrite] = sFreeList.reserveList;
    sFreeList.waitingCommandListQueueWrite++;
    if (sFreeList.waitingCommandListQueueWrite > SND_PXI_FIFO_MESSAGE_BUFSIZE) {
        sFreeList.waitingCommandListQueueWrite = 0;
    }

    sFreeList.reserveList = 0;
    sFreeList.reserveListEnd = 0;

    sFreeList.waitingCommandListCount++;
    sFreeList.currentTag++;

    (void)OS_RestoreInterrupts(bak_psr);

    if (flags & SND_COMMAND_IMMEDIATE) {
        RequestCommandProc();
    }

    return 1;
}

/*
 * sdk:      SND_WaitForCommandProc (snd_command.o)
 */
void SND_WaitForCommandProc(u32 tag)
{
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    while (SND_RecvCommandReply(0) != 0) {
    }
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    RequestCommandProc();
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    do {
        (void)SND_RecvCommandReply(1);
    } while (!SND_IsFinishedCommandTag(tag));
}

/*
 * sdk:      SND_GetCurrentCommandTag (snd_command.o)
 */
u32 SND_GetCurrentCommandTag(void)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
    u32 tag;

    if (sFreeList.reserveList == 0) {
        tag = sFreeList.finishedTag;
    } else {
        tag = sFreeList.currentTag;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return tag;
}

/*
 * sdk:      SND_IsFinishedCommandTag (snd_command.o)
 */
BOOL SND_IsFinishedCommandTag(u32 tag)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
    BOOL result;

    if (tag > sFreeList.finishedTag) {
        if (tag - sFreeList.finishedTag < 0x80000000) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        if (sFreeList.finishedTag - tag < 0x80000000) {
            result = 1;
        } else {
            result = 0;
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return result;
}

/*
 * sdk:      SND_CountFreeCommand (snd_command.o)
 */
int SND_CountFreeCommand(void)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
    SNDCommand *command;
    int count = 0;

    for (command = sFreeList.freeList; command != 0; command = command->next) {
        count++;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return count;
}

/*
 * sdk:      SND_CountReservedCommand (snd_command.o)
 */
int SND_CountReservedCommand(void)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
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
int SND_CountWaitingCommand(void)
{
    int freeCount = SND_CountFreeCommand();
    int reservedCount = SND_CountReservedCommand();

    return 0x100 - freeCount - reservedCount;
}

/*
 * sdk:      PxiFifoCallback (snd_command.o)
 */
void PxiFifoCallback(int tag, u32 data, BOOL err)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    SNDi_CallAlarmHandler((int)data);
    (void)OS_RestoreInterrupts(enabled);
}

/*
 * sdk:      InitPXI (snd_command.o)
 */
void InitPXI(void)
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
void RequestCommandProc(void)
{
    while (PXI_SendWordByFifo(7, 0, 0) < 0) {
    }
}

/*
 * sdk:      AllocCommand (snd_command.o)
 */
SNDCommand *AllocCommand(void)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
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
BOOL IsCommandAvailable(void)
{
    OSIntrMode prev_mode;
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
