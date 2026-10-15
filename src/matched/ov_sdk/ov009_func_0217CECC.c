/*
 * function: gsiCoreCancelTask
 * address:  0x0217CECC
 * packet:   pkt_ov009_0217CECC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiCoreCancelTask (gscore.o)
 *
 * symbols:
 *   gsiCoreGetManager                  0x0217CA20  arm ov009
 *   gsiEnterCriticalSection                  0x0217F108  arm ov009
 *   gsiLeaveCriticalSection                  0x0217F114  arm ov009
 */

typedef struct GSCoreMgr {
    char pad0[0x10];
    int cs;
} GSCoreMgr;
typedef struct GSTask {
    char pad0[0x14];
    int f14;
    int f18;
    void *obj1c;
    void *obj20;
    char pad24[8];
    void (*cb2c)(void *);
} GSTask;

extern void *gsiCoreGetManager(void);
extern void gsiEnterCriticalSection(void *cs);
extern void gsiLeaveCriticalSection(void *cs);

void gsiCoreCancelTask(GSTask *theTask)
{
    GSCoreMgr *aCore = gsiCoreGetManager();
    gsiEnterCriticalSection(&aCore->cs);
    if (theTask->f14 != 0 && theTask->f18 == 0) {
        theTask->f18 = 1;
        if (theTask->cb2c != 0)
            theTask->cb2c(theTask->obj20);
    }
    gsiLeaveCriticalSection(&aCore->cs);
}
