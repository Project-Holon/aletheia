/*
 * function: func_0206E5EC
 * address:  0x0206E5EC
 * packet:   pkt_0206E394
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 2 bytes: the original's guard is unsigned (`popls`) and its loop bound unsigned (`bcc`); `int` spellings give pople/blt and unsigned spellings emit a duplicated exit
 *
 * The entry count is re-read every turn (the callee can change it), and the
 * counter starts before the zero test, hence the `movs`/`popls` pair.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E5EC.c \
 *       --func func_0206E5EC --addr 0x0206E5EC --cc 1.1p1 --arm
 */

extern void func_0206E4FC(void *p, int i, int a);

void func_0206E5EC(void *p, int a)
{
    int i;

    if (*(unsigned char *)((char *)p + 24) == 0)
        return;
    for (i = 0; i < *(unsigned char *)((char *)p + 24); i++)
        func_0206E4FC(p, i, a);
}
