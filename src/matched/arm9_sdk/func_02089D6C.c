/*
 * function: func_02089D6C
 * address:  0x02089D6C
 * packet:   pkt_02089D6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_IsFinishedCommandTag (snd_command.o)
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

BOOL func_02089D6C(u32 tag)
{
    unsigned long bak_psr = OS_DisableInterrupts();
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
