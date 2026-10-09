/*
 * file:     unit_02180410_p06.c
 * unit:     yes
 * function: func_02180E48
 * address:  0x02180E48
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0xc of the block func_02180404 returns.
 *
 * symbols:

 */

extern char *func_02180404(void);

int func_02180E48(void)
{
    return *(int *)(func_02180404() + 0xc);
}

