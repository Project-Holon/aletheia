/*
 * function: NNS_GfdResetVramTransferTaskQueue
 * address:  0x02061C30
 * packet:   pkt_02061C30
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled tail-call stub right after NNS_GfdInitVramTransferTaskQueue (same tail call to
 * NNSi_GfdResetVramTransferTaskQueue on the 0x02146B80 queue, without the two callback stores).
 * Front-end tell (docs/FRONTEND-PINS.md rule 2): the image issues the callee
 * pool load first, `ldr ip, [pc, #4]` at 0x02061C30, then `ldr r0, [pc, #4]`
 * at 0x02061C34. dsi/1.1p1 (and 1.1p1, 1.2) schedule the pool load after the
 * argument write (docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-
 * last-argument-write.md), the two loads transposed, 8 bytes out; the same C
 * under ../2.0/sp2 (also ../1.2/sp2, ../2.0/sp2p2) is 12 bytes, 0 mismatches.
 * Neighbour NNSi_GfdPopVramTransferTask carries the same ../2.0/sp2 pin.
 * Witness for ov131 P_STATUS_ExitGraphics.
 *
 * symbols:
 *   NNSi_GfdResetVramTransferTaskQueue  0x02061B5C  arm
 *   sVramTransferTaskQueue     0x02146B80  data
 */

#include "../include/G_Queue.h"

typedef unsigned char  u8;
extern void NNSi_GfdResetVramTransferTaskQueue(u8 *p);
extern struct Queue sVramTransferTaskQueue;

void NNS_GfdResetVramTransferTaskQueue(void)
{
    NNSi_GfdResetVramTransferTaskQueue((u8 *)((char *)&sVramTransferTaskQueue));
}
