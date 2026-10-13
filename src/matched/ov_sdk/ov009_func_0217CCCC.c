/*
 * function: func_0217CCCC
 * address:  0x0217CCCC
 * packet:   pkt_ov009_0217CCCC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsCoreThink (gscore.o)
 * evidence: +0x98 calls 0x021C204C, where symbols_sdk.json has two rows
 *           (ov016 procInit1, ov114 ghttpCleanup).  The vendor object
 *           libdwcgscommon.TWL.HYB.a(gscore.o) carries a PC24 relocation at
 *           +0x98 naming ghttpCleanup, and the only catalog row with that
 *           name is ov114 (libdwcgsghttp ghttpmain.o) at 0x021C204C, so the
 *           hint is ov114 (tools/sdkobj.py --region ov009 0x0217CCCC).
 *
 * symbols:
 *   gsiCoreGetManager                  0x0217CA20  arm ov009
 *   gsiEnterCriticalSection                  0x0217F108  arm ov009
 *   func_0217F264                  0x0217F264  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_0217CB88                  0x0217CB88  arm ov009
 *   func_021C204C                  0x021C204C  arm ov114
 *   func_021841B0                  0x021841B0  arm ov009
 *   gsiLeaveCriticalSection                  0x0217F114  arm ov009
 */

typedef struct GSTask {
    char pad0[0xc];
    int b0c;
} GSTask;
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
extern unsigned int func_0217F264(void);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_0217CB88(GSTask *theTask);
extern void func_021C204C(void);
extern void func_021841B0(void *array);
extern void gsiLeaveCriticalSection(void *cs);

void func_0217CCCC(unsigned int theMS)
{
    GSCoreMgr *aCore = gsiCoreGetManager();
    int i;
    unsigned int aStartTime;
    int allTasksAreDead = 1;
    int len;
    GSTask *task;

    if (aCore->active == 0)
        return;
    gsiEnterCriticalSection(&aCore->cs);
    aStartTime = func_0217F264();
    len = func_02184200(aCore->tasks);
    if (len > 0)
        allTasksAreDead = 0;
    for (i = len - 1; i >= 0; i--) {
        task = *(GSTask **)func_02184208(aCore->tasks, i);
        if (task->b0c != 0)
            func_0217CB88(task);
        if (theMS != 0 && func_0217F264() - aStartTime > theMS)
            break;
    }
    if (aCore->shutdown != 0 && allTasksAreDead) {
        func_021C204C();
        if (aCore->tasks != 0) {
            func_021841B0(aCore->tasks);
            aCore->tasks = 0;
        }
        aCore->shutdown = 0;
    }
    gsiLeaveCriticalSection(&aCore->cs);
}
