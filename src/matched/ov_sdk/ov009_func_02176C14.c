/*
 * function: DWCi_ProcessReliableQueueEx
 * address:  0x02176C14
 * packet:   pkt_ov009_02176C14
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessReliableQueueEx (libdwcmatch.TWL.HYB.a dwc_reliable.o)
 *
 * symbols:
 *   DWC_Free    0x0205A1B0  arm
 *   gDwcReliableQueue  0x021AB178  data
 */

typedef struct SendQueue {
    void *f0;
    unsigned char *f4;
    int f8;
    struct SendQueue *fC;
} SendQueue;

typedef struct QueueInfo {
    SendQueue *head;
    int total;
} QueueInfo;

extern void DWC_Free(int kind, void *p, int size);
extern QueueInfo gDwcReliableQueue;

int DWCi_ProcessReliableQueueEx(int (*func)(void *, unsigned char *, int, int))
{
    SendQueue *it;
    int retrycount;
    int res;

    for (it = gDwcReliableQueue.head; it != 0; it = it->fC) {
        retrycount = 0;
        do {
            res = func(it->f0, it->f4, it->f8, 1);
            if (res == 0) {
                gDwcReliableQueue.total -= it->f8;
                DWC_Free(4, it->f4, it->f8);
                it->f4 = 0;
                it->f8 = 0;
                it->f0 = 0;
                break;
            }
            retrycount++;
        } while (retrycount < 3);
        if (retrycount == 3)
            break;
    }
    for (it = gDwcReliableQueue.head; it != 0; it = gDwcReliableQueue.head) {
        if (it->f4 != 0)
            break;
        gDwcReliableQueue.head = it->fC;
        DWC_Free(4, it, 0);
    }
    return it == 0;
}
