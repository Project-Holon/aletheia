/*
 * function: func_020898A8
 * address:  0x020898A8
 * packet:   pkt_020898A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    only the init loop differs: the original enters its 255-link loop through a b to the test (unrotated), mwcc -O4,p peels the first test for every loop spelling tried (for, while, goto); the whole object matches -O4,p elsewhere and this body is EXACT at -O2, so the missing piece is a loop spelling, not flags. sSharedWork literal is currently wildcarded (incomplete type).
 *
 * sdk:      SND_CommandInit (snd_command.o)
 *
 * symbols:
 *   InitPXI              0x02089E74  arm
 *   SNDi_InitSharedWork  0x0208A1D0  arm
 *   SND_AllocCommand     0x02089A78  arm
 *   SND_PushCommand      0x02089B00  arm
 *   SND_FlushCommand     0x02089B38  arm
 *   sCommandArray        0x02151740  data
 *   sFreeList            0x0215146C  data
 *   sSharedWork          0x021514C0  data
 *   SNDi_SharedWork      0x02152FA0  data
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

#define SND_COMMAND_BLOCK 0x1
#define SND_COMMAND_NUM   256

typedef struct SNDSharedWork SNDSharedWork;

extern void InitPXI(void);
extern void SNDi_InitSharedWork(SNDSharedWork *work);
extern SNDCommand *SND_AllocCommand(u32 flags);
extern void SND_PushCommand(SNDCommand *command);
extern BOOL SND_FlushCommand(u32 flags);

extern SNDCommand sCommandArray[SND_COMMAND_NUM];
extern SNDCommandState sFreeList;
extern struct SNDSharedWork sSharedWork;
extern SNDSharedWork *SNDi_SharedWork;

void func_020898A8(void)
{
    SNDCommand *command;
    int i;

    InitPXI();

    sFreeList.freeList = &sCommandArray[0];
    for (i = 0; i < SND_COMMAND_NUM - 1; i++) {
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
    SNDi_InitSharedWork(&sSharedWork);

    command = SND_AllocCommand(SND_COMMAND_BLOCK);
    if (command == 0) {
        return;
    }
    command->id = 0x1d;
    command->arg[0] = (u32)SNDi_SharedWork;
    SND_PushCommand(command);
    (void)SND_FlushCommand(SND_COMMAND_BLOCK);
}
