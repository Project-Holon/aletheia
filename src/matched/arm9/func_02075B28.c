/*
 * unit:     no
 * function: NNSi_SndTrackListUnlinkElem
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
 *   NNS_FndAppendListObject  0x020604AC  arm
 */

int NNSi_SndTrackListUnlinkElem(void *a0){ int t0 = OS_DisableInterrupts(); int t1 = NNS_FndAppendListObject((int)0x214EA9C, (int)a0); int t2 = OS_RestoreInterrupts((int)t0); return t2; }
