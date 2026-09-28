/*
 * function: func_0208C6FC
 * address:  0x0208C6FC
 * packet:   pkt_0208C6FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PMi_InsertList (libspi.TWL.HYB.a pm.o)
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

void func_0208C6FC(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info, int priority, int method)
{
    PMiGenCallbackInfo *p;
    PMiGenCallbackInfo *pre;
    unsigned long intr;

    if (!listp) {
        return;
    }
    info->priority = priority;
    intr = OS_DisableInterrupts();
    pre = 0;
    p = *listp;
    while (p) {
        if (method == 0 && p->priority > priority) {
            break;
        }
        if (method == 1 && p->priority >= priority) {
            break;
        }
        pre = p;
        p = p->next;
    }
    if (p) {
        info->next = p;
    } else {
        info->next = 0;
    }
    if (pre) {
        pre->next = info;
    } else {
        *listp = info;
    }
    OS_RestoreInterrupts(intr);
}
