/*
 * function: func_02089B00
 * address:  0x02089B00
 * packet:   pkt_02089B00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_PushCommand (snd_command.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   sFreeList             0x0215146C  data
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

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern SNDCommandState sFreeList;

void func_02089B00(SNDCommand *command)
{
    unsigned long bak_psr = OS_DisableInterrupts();

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
