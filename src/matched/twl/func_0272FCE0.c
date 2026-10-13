/*
 * function: MI_StopNDma
 * address:  0x0272FCE0
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

void MI_StopNDma(int ch)
{
    int irq = OS_DisableInterrupts();
    volatile unsigned int *reg = (volatile unsigned int *)(0x04004000 + 0x11C + ch * 0x1C);
    *reg &= ~0x80000000;
    (void)*reg;
    (void)*reg;
    OS_RestoreInterrupts(irq);
}
