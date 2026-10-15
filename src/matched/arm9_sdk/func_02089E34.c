/*
 * function: SND_CountWaitingCommand
 * address:  0x02089E34
 * packet:   pkt_02089E34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     snd_command.o SND_CountWaitingCommand.
 *
 * symbols:
 *   SND_CountFreeCommand      0x02089DBC  arm
 *   SND_CountReservedCommand  0x02089DF8  arm
 */

int SND_CountFreeCommand(void);
int SND_CountReservedCommand(void);

int SND_CountWaitingCommand(void)
{
    int freeCount = SND_CountFreeCommand();
    int reservedCount = SND_CountReservedCommand();

    return 0x100 - freeCount - reservedCount;
}
