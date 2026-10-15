/*
 * function: NVRAMi_SyncCallback
 * address:  0x02084260
 * packet:   pkt_02084260
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NVRAMi_SyncCallback (libnvram.TWL.HYB.a nvram.o)
 *
 * symbols:
 *   OS_SendMessage                 0x02085DBC  arm
 *   OS_Terminate                   0x02088234  arm
 */

struct OSMessageQueue;

int OS_SendMessage(struct OSMessageQueue *mq, void *msg, long flags);
void OS_Terminate(void);

void NVRAMi_SyncCallback(int result, void *arg)
{
    if (!OS_SendMessage((struct OSMessageQueue *)arg, (void *)result, 0)) {
        OS_Terminate();
    }
}
