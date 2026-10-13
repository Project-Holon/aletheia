/*
 * function: func_02077568
 * address:  0x02077568
 * packet:   pkt_02077568
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PXI_SendWordByFifo 0x02088610  arm
 *   SVC_WaitByLoop 0x02004490  thumb
 *
 * The verdict is EXACT*: 0x02077568 is the last labelled function in the
 * block and its follower has no label (it is the unlabelled save at
 * 0x020775B8, see docs/notes/pkt_02077568.c.txt), so the inferred extent runs
 * to 0x02077634.  Nothing in the compared bytes differs.
 *
 * The two constants are held in locals across the loop, which is what puts the
 * 0xe in r5 and the 0 in r4 for the tail probe while the entry probe still
 * materialises both as immediates.  The loop tests at the bottom, so it is a
 * do/while and not the obvious while.
 */

typedef unsigned int u32;

extern u32  PXI_SendWordByFifo(u32, u32, u32);
extern void SVC_WaitByLoop(u32);

void func_02077568(u32 a, u32 b)
{
    u32 n = 0xe;
    u32 z = 0;

    if (PXI_SendWordByFifo(n, a, z) == 0) return;
    do {
        SVC_WaitByLoop(b);
    } while (PXI_SendWordByFifo(n, a, z) != 0);
}
