/*
 * function: func_02089A78
 * address:  0x02089A78
 * packet:   pkt_02089A78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_AllocCommand (snd_command.o)
 *
 * symbols:
 *   IsCommandAvailable       0x02089F48  arm
 *   AllocCommand             0x02089F00  arm
 *   SND_CountWaitingCommand  0x02089E34  arm
 *   SND_RecvCommandReply     0x02089978  arm
 *   SND_FlushCommand         0x02089B38  arm
 *   RequestCommandProc       0x02089ED8  arm
 */

typedef unsigned long u32;
typedef int BOOL;

typedef struct SNDCommand SNDCommand;

#define SND_COMMAND_BLOCK 0x1

extern BOOL IsCommandAvailable(void);
extern SNDCommand *AllocCommand(void);
extern int SND_CountWaitingCommand(void);
extern const SNDCommand *SND_RecvCommandReply(u32 flags);
extern BOOL SND_FlushCommand(u32 flags);
extern void RequestCommandProc(void);

SNDCommand *func_02089A78(u32 flags)
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
