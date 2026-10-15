/*
 * function: OSi_DoLockByWord
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
 *   OSi_DoTryLockByWord  0x02084CFC  arm
 */

extern int OSi_DoTryLockByWord(int a, int b, int c, int d);
extern void SVC_WaitByLoop(int v);
void OSi_DoLockByWord(int a, int b, int c, int d)
{
    if (OSi_DoTryLockByWord(a, b, c, d) <= 0)
        return;
    do {
        SVC_WaitByLoop(0x400);
    } while (OSi_DoTryLockByWord(a, b, c, d) > 0);
}
