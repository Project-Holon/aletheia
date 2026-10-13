/*
 * function: MI_WaitNDma
 * address:  0x0272FCB0
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 */

int OS_DisableInterrupts(void);
void OS_RestoreInterrupts(int);

void MI_WaitNDma(int ch)
{
    int irq = OS_DisableInterrupts();
    volatile unsigned int *reg = (volatile unsigned int *)(0x0400411C + ch * 0x1C);
    while (*reg & 0x80000000) {
    }
    OS_RestoreInterrupts(irq);
}
