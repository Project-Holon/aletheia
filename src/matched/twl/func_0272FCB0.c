/*
 * function: func_0272FCB0
 * address:  0x0272FCB0
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

void func_0272FCB0(int ch)
{
    int irq = func_02087988();
    volatile unsigned int *reg = (volatile unsigned int *)(0x0400411C + ch * 0x1C);
    while (*reg & 0x80000000) {
    }
    func_0208799C(irq);
}
