/*
 * function: func_021F89D0
 * address:  0x021F89D0
 * packet:   pkt_021F89D0
 * region:   ov184
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Blocker: register allocation.  The original keeps the table pointer in
 *   r6, i in r4 and 0 in r7 and recomputes `a + i*4 + 4`; mwcc folds a+4
 *   into a base register and swaps the rest.
 *
 * symbols:
 *   func_021FC0C8   0x021FC0C8  thumb
 *   func_021FBDA4   0x021FBDA4  thumb
 *   func_021FB494   0x021FB494  thumb
 *
 * If the lead handle is live, flush the two sub-slots and clear them.
 */


extern void func_021FC0C8(int, int);
extern void func_021FBDA4(int, int);
extern void func_021FB494(int);

void func_021F89D0(int *a, char *p)
{
    int i;
    if (a[1] != 0) {
        func_021FC0C8(*(int *)(p + 0xC), 6);
        func_021FBDA4(*(int *)(p + 0xC), 0x17);
        for (i = 0; i < 2; i++) {
            func_021FB494(*(int *)((char *)a + 4 + i * 4));
            *(int *)((char *)a + 4 + i * 4) = 0;
        }
    }
}
