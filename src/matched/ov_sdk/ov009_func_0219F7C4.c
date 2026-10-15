/*
 * function: SBServerListNth
 * address:  0x0219F7C4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at the block func_02184208 returns, on the word at +4.
 *
 * symbols:

 */

extern char *func_02184208(int v);

int SBServerListNth(int *p)
{
    return *(int *)func_02184208(p[1]);
}

