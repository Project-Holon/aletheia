/*
 * function: func_02089804
 * address:  0x02089804
 * packet:   pkt_02089804
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PushCommand_impl (snd_interface.o)
 *
 * symbols:
 *   SND_AllocCommand  0x02089A78  arm
 *   SND_PushCommand   0x02089B00  arm
 */

typedef unsigned long u32;

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    u32 arg[4];
} SNDCommand;

extern SNDCommand *SND_AllocCommand(u32 flags);
extern void SND_PushCommand(SNDCommand *command);

void func_02089804(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    SNDCommand *command = SND_AllocCommand(1);

    if (command == 0) {
        return;
    }
    command->id = id;
    command->arg[0] = arg0;
    command->arg[1] = arg1;
    command->arg[2] = arg2;
    command->arg[3] = arg3;
    SND_PushCommand(command);
}
