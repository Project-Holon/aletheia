/*
 * function: IsCommandAvailable
 * address:  0x02089F48
 * packet:   pkt_02089F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IsCommandAvailable (snd_command.o)
 *
 * symbols:
 *   OS_IsRunOnEmulator    0x02085D24  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned long u32;
typedef int BOOL;

extern BOOL OS_IsRunOnEmulator(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

#define REG_EMU_COMMAND (*(volatile u32 *)0x04FFF200)

BOOL IsCommandAvailable(void)
{
    unsigned long prev_mode;
    u32 res;

    if (!OS_IsRunOnEmulator()) {
        return 1;
    }
    prev_mode = OS_DisableInterrupts();
    REG_EMU_COMMAND = 0x10;
    res = REG_EMU_COMMAND;
    (void)OS_RestoreInterrupts(prev_mode);
    return (res != 0) ? 1 : 0;
}
