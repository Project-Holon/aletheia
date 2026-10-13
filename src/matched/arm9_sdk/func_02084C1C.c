/*
 * function: func_02084C1C
 * address:  0x02084C1C
 * packet:   pkt_02084C1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   SVC_WaitByLoop    0x02004490  thumb
 */

extern int func_02084CFC(int a, int b, int c, int d);
extern void SVC_WaitByLoop(int v);
void func_02084C1C(int a, int b, int c, int d)
{
    if (func_02084CFC(a, b, c, d) <= 0)
        return;
    do {
        SVC_WaitByLoop(0x400);
    } while (func_02084CFC(a, b, c, d) > 0);
}
