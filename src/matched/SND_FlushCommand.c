/*
 * function: SND_FlushCommand
 * address:  0x02089B38
 * packet:   pkt_02089B38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libsnd snd_command.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Hands the reserved command list to the ARM7 over the sound FIFO: waits
 * (SND_COMMAND_BLOCK) or fails when the waiting queue is full or the FIFO
 * send fails, then queues the list, clears the reserve list, bumps the tag
 * and, with SND_COMMAND_IMMEDIATE, requests immediate processing.
 *
 * symbols:
 *   OS_DisableInterrupts      0x02087988  arm
 *   OS_RestoreInterrupts      0x0208799C  arm
 *   SND_RecvCommandReply      0x02089978  arm
 *   DC_FlushRange             0x020862F0  arm
 *   PXI_SendWordByFifo        0x02088610  arm
 *   RequestCommandProc        0x02089ED8  arm
 *   sFreeList                 0x0215146C  data
 *   sCommandArray             0x02151740  data
 *   sWaitingCommandListQueue  0x02151490  data
 */

typedef unsigned long u32;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    u32 arg[4];
} SNDCommand;

#define SND_COMMAND_BLOCK        0x1
#define SND_COMMAND_IMMEDIATE    0x2
#define SND_PXI_FIFO_MESSAGE_BUFSIZE 8
#define SND_COMMAND_NUM          256
#define PXI_FIFO_TAG_SOUND       7

/* snd_command.o's .bss statics from sFreeList on, in their laid-out order */
typedef struct {
    SNDCommand *freeList;
    SNDCommand *freeListEnd;
    SNDCommand *reserveList;
    SNDCommand *reserveListEnd;
    u32 unk10;
    u32 unk14;
    int waitingCommandListQueueWrite;
    int waitingCommandListCount;
    u32 currentTag;
} SNDCommandState;

extern SNDCommandState sFreeList;
extern SNDCommand sCommandArray[SND_COMMAND_NUM];
extern SNDCommand *sWaitingCommandListQueue[SND_PXI_FIFO_MESSAGE_BUFSIZE + 1];

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern const SNDCommand *SND_RecvCommandReply(u32 flags);
extern void DC_FlushRange(const void *startAddr, u32 nBytes);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern void RequestCommandProc(void);

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
