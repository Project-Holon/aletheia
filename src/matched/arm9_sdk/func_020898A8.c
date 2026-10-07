/*
 * function: func_020898A8
 * address:  0x020898A8
 * packet:   pkt_020898A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_CommandInit (libsnd.TWL.HYB.a snd_command.o)
 *           The free-list loop is entered with a b to its bottom test and the constant
 *           first test is not folded; the loop condition written as `(c) ? 1 : 0` keeps
 *           that form (docs/idioms/a-loop-entered-by-a-branch-to-its-bottom-test-has-a-ternary-condition.md).
 *           snd_command.o .bss is one block addressed from the sFreeList pool word:
 *           +0 freeList, +4 finishedTag, +8 reserveList, +0xC reserveListEnd,
 *           +0x10 freeListEnd, +0x14 queueRead, +0x18 queueWrite, +0x1C waitingCount,
 *           +0x20 currentTag.
 *
 * symbols:
 *   InitPXI                          0x02089E74 arm
 *   SNDi_InitSharedWork              0x0208A1D0 arm
 *   SND_AllocCommand                 0x02089A78 arm
 *   SND_PushCommand                  0x02089B00 arm
 *   SND_FlushCommand                 0x02089B38 arm
 *   sCommandArray                    0x02151740 data
 *   sCommandBss                      0x0215146C data
 *   sSharedWork                      0x021514C0 data
 *   SNDi_SharedWork                  0x02152FA0 data
 */

#include "../include/G_SNDCommand.h"

typedef unsigned long u32;

typedef struct SNDCommand SNDCommand;

typedef struct SNDSharedWork {
    u32 opaque[160];
} SNDSharedWork;

typedef struct SndCommandBss {
    SNDCommand *freeList;
    u32 finishedTag;
    SNDCommand *reserveList;
    SNDCommand *reserveListEnd;
    SNDCommand *freeListEnd;
    int queueRead;
    int queueWrite;
    int waitingCount;
    u32 currentTag;
} SndCommandBss;

extern SndCommandBss sCommandBss;
extern struct SNDCommand sCommandArray[256];
extern SNDSharedWork sSharedWork;
extern SNDSharedWork *SNDi_SharedWork;

extern void InitPXI(void);
extern void SNDi_InitSharedWork(SNDSharedWork *work);
extern SNDCommand *SND_AllocCommand(u32 flags);
extern void SND_PushCommand(SNDCommand *command);
extern int SND_FlushCommand(u32 flags);

void func_020898A8(void)
{
    SNDCommand *command;
    int i;

    InitPXI();

    sCommandBss.freeList = &sCommandArray[0];
    for (i = 0; (i < 256 - 1) ? 1 : 0; i++) {
        sCommandArray[i].next = &sCommandArray[i + 1];
    }
    sCommandArray[256 - 1].next = 0;
    sCommandBss.freeListEnd = &sCommandArray[256 - 1];

    sCommandBss.reserveList = 0;
    sCommandBss.reserveListEnd = 0;

    sCommandBss.waitingCount = 0;
    sCommandBss.queueRead = 0;
    sCommandBss.queueWrite = 0;

    sCommandBss.currentTag = 1;
    sCommandBss.finishedTag = 0;

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
