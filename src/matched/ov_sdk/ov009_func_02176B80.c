/*
 * function: func_02176B80
 * address:  0x02176B80
 * packet:   pkt_ov009_02176B80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CleanupReliableQueue (libdwcmatch.TWL.HYB.a dwc_reliable.o)
 *
 * symbols:
 *   DWC_Free    0x0205A1B0  arm
 *   g_021AB178  0x021AB178  data
 */

typedef struct SendQueue {
    struct SendQueue *f0;
    void *f4;
    int f8;
    struct SendQueue *fC;
} SendQueue;

typedef struct QueueInfo {
    SendQueue *head;
    SendQueue *tail;
} QueueInfo;

extern void DWC_Free(int kind, void *p, int size);
extern QueueInfo g_021AB178;

void func_02176B80(void)
{
    SendQueue *it;

    while ((it = g_021AB178.head) != 0) {
        g_021AB178.head = it->fC;
        DWC_Free(4, it->f4, it->f8);
        DWC_Free(4, it, 0);
    }
    g_021AB178.head = 0;
    g_021AB178.tail = 0;
}
