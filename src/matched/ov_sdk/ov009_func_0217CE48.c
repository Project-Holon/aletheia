/*
 * function: func_0217CE48
 * address:  0x0217CE48
 * packet:   pkt_ov009_0217CE48
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiCoreExecuteTask (gscore.o)
 *
 * symbols:
 *   gsiCoreGetManager                  0x0217CA20  arm ov009
 *   func_0217F264                  0x0217F264  arm ov009
 *   gsiEnterCriticalSection                  0x0217F108  arm ov009
 *   func_02184234                  0x02184234  arm ov009
 *   gsiLeaveCriticalSection                  0x0217F114  arm ov009
 */

typedef struct GSCoreMgr {
    char pad0[0x10];
    int cs;
    char pad14[0x28 - 0x14];
    void *tasks;
} GSCoreMgr;
typedef struct GSTask {
    char pad0[4];
    unsigned int timeout;
    unsigned int startTime;
    char pad0c[4];
    int f10;
    int f14;
    char pad18[4];
    int f1c;
    void *obj20;
    void (*cb24)(void *);
} GSTask;

extern void *gsiCoreGetManager(void);
extern unsigned int func_0217F264(void);
extern void gsiEnterCriticalSection(void *cs);
extern void func_02184234(void *array, void *elem);
extern void gsiLeaveCriticalSection(void *cs);

void func_0217CE48(GSTask *theTask, unsigned int theTimeoutMs)
{
    GSCoreMgr *aCore = gsiCoreGetManager();
    theTask->f1c = 1;
    theTask->f10 = 1;
    theTask->f14 = 1;
    theTask->timeout = theTimeoutMs;
    theTask->startTime = func_0217F264();
    if (theTask->cb24 != 0)
        theTask->cb24(theTask->obj20);
    gsiEnterCriticalSection(&aCore->cs);
    func_02184234(aCore->tasks, &theTask);
    gsiLeaveCriticalSection(&aCore->cs);
}
