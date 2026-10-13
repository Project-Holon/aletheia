/*
 * unit:     no
 * function: NNS_GfdRegisterNewVramTransferTask
 * address:  0x02061CA4
 * packet:   pkt_02061C0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sVramTransferTaskQueue     0x02146B80  data
 *   NNSi_GfdRingIsFull  0x02061860  arm
 *   NNSi_GfdGetTailVramTransferTask  0x02061BC0  arm
 *   NNSi_GfdPushVramTransferTask  0x02061B74  arm
 *
 * Pushes one four-word request onto the queue object at 0x02146B80 and adds
 * its size field to the queue's running byte total at +0x10. NNSi_GfdRingIsFull
 * is the "queue full" test: a non-zero answer makes this return 0 without
 * touching anything, which is why the failure path is a `movne r0, #0` fused
 * into the conditional epilogue rather than a branch.
 *
 * The middle two stores land as one `stmib r4, {r7, r8}` and that ordering is
 * the whole tell for the argument mapping: `stm` writes the lowest-numbered
 * register to the lowest address, so +4 takes r7 (the third argument) and +8
 * takes r8 (the second). Writing the two fields in numeric field order
 * instead swaps the two arguments and still produces an `stmib`, so the
 * verdict stays SIZE-clean and the diff is only two bytes.
 *
 * This was capped at MATCH until 0x02061B74, the queue push, was matched in
 * src/matched/NNSi_GfdPushVramTransferTask.c; that entry is the witness the `bl` needed.
 * NNSi_GfdGetTailVramTransferTask is likewise a matched entry now.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_GfdRegisterNewVramTransferTask.c \
 *       --func NNS_GfdRegisterNewVramTransferTask --addr 0x02061CA4 --cc 1.1p1 --arm
 */

#include "../include/G_Queue.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Req {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    s32 size;
};

extern struct Queue sVramTransferTaskQueue;

extern int NNSi_GfdRingIsFull(u8 *p);
extern u32 NNSi_GfdGetTailVramTransferTask(u8 *p);
extern int NNSi_GfdPushVramTransferTask(char *p);

s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size)
{
    struct Req *req;

    if (NNSi_GfdRingIsFull((u8 *)(&sVramTransferTaskQueue)) != 0) {
        return 0;
    }

    req = (struct Req *)NNSi_GfdGetTailVramTransferTask((u8 *)(&sVramTransferTaskQueue));
    req->unk_00 = p;
    req->unk_04 = b;
    req->unk_08 = a;
    req->size = size;
    NNSi_GfdPushVramTransferTask((char *)(&sVramTransferTaskQueue));
    sVramTransferTaskQueue.total += req->size;
    return 1;
}
