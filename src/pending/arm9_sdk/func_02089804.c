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
 * symbols:
 *   SND_AllocCommand 0x02089A78 arm
 *   SND_PushCommand  0x02089B00 arm
 *
 * snd_interface.o PushCommand_impl.  Allocate a command block, fill in the
 * id and four arguments, then hand it to the command queue.  No-op if the
 * allocator is dry.
 */

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    unsigned int arg[4];
} SNDCommand;

extern SNDCommand *SND_AllocCommand(int flag);
extern void SND_PushCommand(SNDCommand *command);

void func_02089804(int id, int arg0, int arg1, int arg2, int arg3)
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
