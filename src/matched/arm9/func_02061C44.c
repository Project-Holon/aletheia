/*
 * function: NNS_GfdDoVramTransfer
 * address:  0x02061C44
 * packet:   pkt_02061C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   sVramTransferTaskQueue  0x02146B80  data
 *   NNSi_GfdGetHeadVramTransferTask  0x02061BB0  arm
 *   NNSi_GfdPopVramTransferTask  0x02061BD0  arm
 *   NNSi_GfdRunVramTransferTask  0x02061B2C  arm
 *
 * Drain loop over the 0x02146B80 work record: fetch the head node, pump the
 * record's one-step state machine, and for as long as it reports progress
 * dispose of the node and subtract its size field from the record's running
 * byte total at +0x10, then fetch the next head.
 *
 * Blocked at MATCH on the `matched` class: NNSi_GfdRunVramTransferTask (PC24 at +0x0028)
 * and NNSi_GfdPopVramTransferTask (PC24 at +0x0018 and +0x004c) each have their only
 * branch inside 0x02061C44..0x02061CA0, so both sites stay wildcarded.  Both
 * callees are documented dead ends in docs/notes/pkt_02061B2C.c.txt and
 * docs/notes/pkt_02061BD0.c.txt (16 and 6 concrete bytes of instruction
 * selection residue respectively), so neither can ever be filed EXACT and
 * neither can attest this file.  Every concrete byte here reproduces.
 */

#include "../include/G_Queue.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Node {
    char pad_00[0xc];
    u32  f0c;   /* 0x0c, byte size consumed */
} Node;

extern struct Queue sVramTransferTaskQueue;
extern u32 NNSi_GfdGetHeadVramTransferTask(u8 *p);
struct Obj02061BD0;
extern u32 NNSi_GfdPopVramTransferTask(struct Obj02061BD0 *p);
extern void NNSi_GfdRunVramTransferTask(u32 *s);

void NNS_GfdDoVramTransfer(void)
{
    Node *n = (Node *)NNSi_GfdGetHeadVramTransferTask((u8 *)(&sVramTransferTaskQueue));

    while (NNSi_GfdPopVramTransferTask((struct Obj02061BD0 *)(&sVramTransferTaskQueue)) != 0) {
        NNSi_GfdRunVramTransferTask((u32 *)n);
        sVramTransferTaskQueue.total -= n->f0c;
        n = (Node *)NNSi_GfdGetHeadVramTransferTask((u8 *)(&sVramTransferTaskQueue));
    }
}
