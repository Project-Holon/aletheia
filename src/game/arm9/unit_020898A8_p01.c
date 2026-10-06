/*
 * file:     unit_020898A8_p01.c
 * unit:     yes
 * function: func_02089A78, func_02089B00
 * address:  0x02089A78
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
 *   IsCommandAvailable       0x02089F48  arm
 *   AllocCommand             0x02089F00  arm
 *   SND_CountWaitingCommand  0x02089E34  arm
 *   SND_RecvCommandReply     0x02089978  arm
 *   SND_FlushCommand         0x02089B38  arm
 *   RequestCommandProc       0x02089ED8  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   sFreeList             0x0215146C  data
 */
typedef unsigned long u32;

typedef int BOOL;

typedef struct SNDCommand_02089A78 SNDCommand_02089A78;

typedef struct SNDCommand_02089B00 {
    struct SNDCommand_02089B00 *next;
    int id;
    u32 arg[4];
} SNDCommand_02089B00;

/* snd_command.o's .bss statics from sFreeList on, in their laid-out order */
typedef struct {
    SNDCommand_02089B00 *freeList;
    u32 finishedTag;
    SNDCommand_02089B00 *reserveList;
    SNDCommand_02089B00 *reserveListEnd;
    SNDCommand_02089B00 *freeListEnd;
    u32 unk14;
    int waitingCommandListQueueWrite;
    int waitingCommandListCount;
    u32 currentTag;
} SNDCommandState;

extern BOOL IsCommandAvailable(void);
extern SNDCommand_02089A78 *AllocCommand(void);
extern int SND_CountWaitingCommand(void);
extern const SNDCommand_02089A78 *SND_RecvCommandReply(u32 flags);
extern BOOL SND_FlushCommand(u32 flags);
extern void RequestCommandProc(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
SNDCommand_02089A78 *func_02089A78(u32 flags);
void func_02089B00(SNDCommand_02089B00 *command);
extern SNDCommandState sFreeList;


#define SND_COMMAND_BLOCK 0x1


/*
 * sdk:      SND_AllocCommand (snd_command.o)
 */
SNDCommand_02089A78 *func_02089A78(u32 flags)
{
    SNDCommand_02089A78 *command;

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
void func_02089B00(SNDCommand_02089B00 *command)
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
