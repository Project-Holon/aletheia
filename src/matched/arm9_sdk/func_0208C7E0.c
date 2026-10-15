/*
 * function: PMi_ExecuteList
 * address:  0x0208C7E0
 * packet:   pkt_0208C7E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PMi_ExecuteList.
 */

typedef struct PMGenCallbackInfo {
    void (*callback)(void *arg);
    void *arg;
    int _pad;
    struct PMGenCallbackInfo *next;
} PMGenCallbackInfo;

void PMi_ExecuteList(PMGenCallbackInfo *listp)
{
    while (listp) {
        (listp->callback)(listp->arg);
        listp = listp->next;
    }
}
