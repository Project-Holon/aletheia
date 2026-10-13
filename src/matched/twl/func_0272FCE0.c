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
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */

int func_02087988(void);
void func_0208799C(int);

void MI_StopNDma(int ch)
{
    int irq = func_02087988();
    volatile unsigned int *reg = (volatile unsigned int *)(0x04004000 + 0x11C + ch * 0x1C);
    *reg &= ~0x80000000;
    (void)*reg;
    (void)*reg;
    func_0208799C(irq);
}
