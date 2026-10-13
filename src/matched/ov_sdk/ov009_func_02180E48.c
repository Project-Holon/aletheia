/*
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
 * Word at +0xc of the block gsUdpEngineContext returns.
 *
 * symbols:
 *   gsUdpEngineContext  0x02180404  arm

 */

extern char *gsUdpEngineContext(void);

int func_02180E48(void)
{
    return *(int *)(gsUdpEngineContext() + 0xc);
}

