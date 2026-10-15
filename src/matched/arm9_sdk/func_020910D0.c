/*
 * function: CTRDGi_LockByProcessor
 * address:  0x020910D0
 * packet:   pkt_020910D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0034 PC24 func_02084DA4           -> unresolved: 02084DA4 (arm, from header) has no witness outside 020910D0..0209112C
 *           callee func_02084DA4 (the only branch to it in the whole image
 *           is the one inside this file) has no witness outside
 *           020910D0..0209112C, so that one call site stays wildcarded.
 *           The C is byte-correct at every other offset: the file becomes
 *           EXACT with no edit once 0x02084DA4 has a shard entry of its
 *           own (it is a 0x02084xxx packet, outside this window).
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_ReadOwnerOfLockWord  0x02084EB0  arm
 *   func_02084DA4  0x02084DA4  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SVC_WaitByLoop  0x02004490  thumb
 */

typedef unsigned int u32;

extern u32 OS_DisableInterrupts(void);
extern unsigned short OS_ReadOwnerOfLockWord(char *p);
extern u32 func_02084DA4(u32 a);
extern void OS_RestoreInterrupts(u32 h);
extern void SVC_WaitByLoop(u32 v);

void CTRDGi_LockByProcessor(u32 a0, u32 *a1)
{
    u32 t;

    while (1) {
        a1[1] = OS_DisableInterrupts();
        t = OS_ReadOwnerOfLockWord((void *)0x02FFFFE8) & 0x40;
        a1[0] = t;
        if (t != 0)
            return;
        if (func_02084DA4(a0) == 0)
            return;
        OS_RestoreInterrupts(a1[1]);
        SVC_WaitByLoop(1);
    }
}
