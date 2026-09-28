/*
 * function: func_02089DBC
 * address:  0x02089DBC
 * packet:   pkt_02089DBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_CountFreeCommand (snd_command.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   sFreeList             0x0215146C  data
 */

typedef struct SNDCommand {
    struct SNDCommand *next;
} SNDCommand;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern SNDCommand *sFreeList;

int func_02089DBC(void)
{
    unsigned long bak_psr = OS_DisableInterrupts();
    SNDCommand *command;
    int count = 0;

    for (command = sFreeList; command != 0; command = command->next) {
        count++;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return count;
}
