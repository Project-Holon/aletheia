/*
 * function: gsCoreShutdown
 * address:  0x0217CD94
 * packet:   pkt_ov009_0217CD94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsCoreShutdown (gscore.o)
 *
 * symbols:
 *   gsiCoreGetManager                  0x0217CA20  arm ov009
 *   gsiEnterCriticalSection                  0x0217F108  arm ov009
 *   gsiInterlockedDecrement                  0x0217F0D8  arm ov009
 *   gsiLeaveCriticalSection                  0x0217F114  arm ov009
 *   ArrayLength                  0x02184200  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   gsiCoreCancelTask                  0x0217CECC  arm ov009
 */

typedef struct GSTask GSTask;
typedef struct GSCoreMgr {
    unsigned int refs;
    char pad4[4];
    int active;
    int shutdown;
    int cs;
    char pad14[0x28 - 0x14];
    void *tasks;
} GSCoreMgr;

extern void *gsiCoreGetManager(void);
extern void gsiEnterCriticalSection(void *cs);
extern unsigned int gsiInterlockedDecrement(unsigned int *value);
extern void gsiLeaveCriticalSection(void *cs);
extern int ArrayLength(const int *p);
extern void *func_02184208(void *array, int n);
extern void gsiCoreCancelTask(struct GSTask *theTask);

void gsCoreShutdown(void)
{
    GSCoreMgr *aCore = gsiCoreGetManager();
    int i;
    int len;

    if (aCore->active == 0)
        return;
    gsiEnterCriticalSection(&aCore->cs);
    if (gsiInterlockedDecrement(&aCore->refs) != 0) {
        gsiLeaveCriticalSection(&aCore->cs);
        return;
    }
    aCore->shutdown = 1;
    len = ArrayLength(aCore->tasks);
    for (i = 0; i < len; i++)
        gsiCoreCancelTask(*(GSTask **)func_02184208(aCore->tasks, i));
    gsiLeaveCriticalSection(&aCore->cs);
}
