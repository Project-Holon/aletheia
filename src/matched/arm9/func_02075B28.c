/*
 * unit:     no
 * function: func_02075B28
 * address:  0x02075B28
 * packet:   pkt_02075AB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

int func_02075B28(void *a0){ int t0 = OS_DisableInterrupts(); int t1 = func_020604AC((int)0x214EA9C, (int)a0); int t2 = OS_RestoreInterrupts((int)t0); return t2; }
