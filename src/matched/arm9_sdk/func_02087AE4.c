/*
 * function: OS_WaitVBlankIntr
 * address:  0x02087AE4
 * packet:   pkt_02087AE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   SVC_WaitByLoop    0x02004490  thumb
 */

extern void SVC_WaitByLoop(int v);
typedef unsigned int   u32;
extern void func_0208459C(int clear, u32 irqFlags);
void OS_WaitVBlankIntr(void)
{
    SVC_WaitByLoop(1);
    func_0208459C(1, 1);
}
