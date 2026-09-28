/*
 * function: func_02089F00
 * address:  0x02089F00
 * packet:   pkt_02089F00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      AllocCommand (snd_command.o)
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
