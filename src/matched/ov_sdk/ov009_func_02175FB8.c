/*
 * function: DWCi_GetHostStatus
 * address:  0x02175FB8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte at +0x16 of the block func_02175F3C returns.
 *
 * symbols:

 */

extern int func_02175F3C(void);

static unsigned char DWCi_GetHostStatus(void)
{
    return *(unsigned char *)(func_02175F3C() + 0x16);
}

