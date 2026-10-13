/*
 * function: OSi_DisableInterruptsAndHalt
 * address:  0x020882C0
 * packet:   pkt_020882C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_Halt  0x020882D0  arm
 */

extern void OS_DisableInterrupts(void);
extern void OS_Halt(void);

void OSi_DisableInterruptsAndHalt(void)
{
    OS_DisableInterrupts();
    while (1) {
        OS_Halt();
    }
}
