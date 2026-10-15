/*
 * function: SND_RecvCommandReply
 * address:  0x02089978
 * packet:   pkt_02089978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_RecvCommandReply (snd_command.o)
 *
 * symbols:
 *   OS_DisableInterrupts        0x02087988  arm
 *   SNDi_GetFinishedCommandTag  0x0208A1AC  arm
 *   OS_RestoreInterrupts        0x0208799C  arm
 *   OS_SpinWaitSysCycles        0x02087A04  arm
 *   sFreeList                   0x0215146C  data
 *   sWaitingCommandListQueue    0x02151490  data
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
    int waitingCommandListQueueRead;
    int waitingCommandListQueueWrite;
    int waitingCommandListCount;
    u32 currentTag;
} SNDCommandState;

#define SND_COMMAND_BLOCK            0x1
#define SND_PXI_FIFO_MESSAGE_BUFSIZE 8

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern u32 SNDi_GetFinishedCommandTag(void);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern SNDCommandState sFreeList;
extern SNDCommand *sWaitingCommandListQueue[SND_PXI_FIFO_MESSAGE_BUFSIZE + 1];

const SNDCommand *SND_RecvCommandReply(u32 flags)
{
    unsigned long bak_psr;
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
