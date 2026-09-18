/*
 * function: func_02036B98
 * address:  0x02036B98
 * packet:   pkt_02036B98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Scan the 0x14-stride records behind p's +0x18 pointer for one whose
 * halfword at +0x0E equals the argument; the count is p's word at +0x1C.  A
 * hit returns 1 from inside the loop (`moveq r0, #1` / `bxeq lr`), a miss
 * falls out to `mov r0, #0`.
 *
 * The three scratch registers are decided by declaration order alone: the
 * index declared first takes r2, the record cursor declared second takes r3
 * and the count declared last takes ip.  Any other order of the same three
 * declarations moves the count into r2 or the cursor into ip and misses by
 * seven instructions' worth of register names.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036B98.c \
 *       --func func_02036B98 --addr 0x02036B98 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

int func_02036B98(char *p, int v)
{
    int   i;
    char *e = *(char **)(p + 0x18);
    int   n = *(int *)(p + 0x1C);

    for (i = 0; i < n; i++, e += 0x14) {
        if (*(u16 *)(e + 0x0E) == v)
            return 1;
    }
    return 0;
}
