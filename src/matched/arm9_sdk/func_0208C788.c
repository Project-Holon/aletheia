/*
 * function: func_0208C788
 * address:  0x0208C788
 * packet:   pkt_0208C788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PMi_DeleteList (libspi.TWL.HYB.a pm.o)
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 */

typedef struct PMiGenCallbackInfo {
    void (*callback)(void *);
    void *arg;
    int priority;
    struct PMiGenCallbackInfo *next;
} PMiGenCallbackInfo;

unsigned long OS_DisableInterrupts(void);
unsigned long OS_RestoreInterrupts(unsigned long state);

void func_0208C788(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info)
{
    PMiGenCallbackInfo *pre;
    PMiGenCallbackInfo *p;
    unsigned long intr;

    if (!listp) {
        return;
    }
    intr = OS_DisableInterrupts();
    pre = p = *listp;
    while (p) {
        if (p == info) {
            if (p == pre) {
                *listp = p->next;
            } else {
                pre->next = p->next;
            }
            break;
        }
        pre = p;
        p = p->next;
    }
    OS_RestoreInterrupts(intr);
}
