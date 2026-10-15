/*
 * file:     gscore.c
 * unit:     yes
 * function: gsiCoreGetManager, gsiCoreAtExitShutdown, gsCoreInitialize, gsiCoreTaskDispatchCallback, gsCoreTaskThink, gsCoreThink, gsCoreShutdown, gsCoreIsShutdown, gsiCoreExecuteTask, gsiCoreCancelTask, gsiCoreCreateTask
 * address:  0x0217CA20
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Address of the module state object.
 *
 * symbols:
 *   gGSCoreManager  0x021ACFD4  data
 *   msleep  0x0217F2BC  arm  ov009
 *   func_0217F0B4  0x0217F0B4  arm  ov009
 *   gsiInitializeCriticalSection  0x0217F0FC  arm  ov009
 *   MSL_C_LIB_LockRegisterDestructor  0x020912A8  arm
 *   gsiEnterCriticalSection  0x0217F108  arm  ov009
 *   gsiLeaveCriticalSection  0x0217F114  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   ghttpStartup  0x021C1FF8  arm  ov114
 *   current_time  0x0217F264  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02184324  0x02184324  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   ghttpCleanup                  0x021C204C  arm ov114
 *   func_021841B0                  0x021841B0  arm ov009
 *   func_0217F0D8                  0x0217F0D8  arm ov009
 *   func_02184234                  0x02184234  arm ov009
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   MSL_C_LIB_MemsetPtr                  0x020923B0  arm
 *   gsiDeleteCriticalSection  0x0217F120  arm
 */
typedef unsigned char u8;

typedef unsigned long u32;

typedef struct {
    unsigned int mRefCount;
    volatile int mIsStaticInitComplete;
    int mIsInitialized;
    int mIsShuttingDown;
    u8  mQueueCrit[0x18];
    void *mTaskArray;
} GSCoreMgr;

typedef struct GSTask {
    int mId;
    unsigned int mTimeout;
    unsigned int mStartTime;
    int mAutoThink;
    int mIsStarted;
    int mIsRunning;
    int mIsCanceled;
    int mIsCallbackPending;
    void *mTaskData;
    void (*mExecuteFunc)(void *);
    void (*mCallbackFunc)(void *, int);
    void (*mCancelFunc)(void *);
    int (*mCleanupFunc)(void *);
    int (*mThinkFunc)(void *);
} GSTask;

extern void gsiDeleteCriticalSection(void *p);
extern void msleep(unsigned int msec);
extern unsigned int func_0217F0B4(unsigned int *value);
extern void gsiInitializeCriticalSection(void *mutex);
extern u32 MSL_C_LIB_LockRegisterDestructor(u32 a0);
extern void gsiEnterCriticalSection(void *mutex);
extern void gsiLeaveCriticalSection(void *mutex);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void ghttpStartup(void);
extern unsigned int current_time(void);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_02184324(void *array, int n);
extern void func_0217EAE0(void *ptr);
extern void ghttpCleanup(void);
extern void func_021841B0(void *array);
extern unsigned int func_0217F0D8(unsigned int *value);
extern void func_02184234(void *array, void *elem);
extern void *func_0217EAB0(unsigned long size);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, unsigned long n);
void *gsiCoreGetManager(void);
void gsiCoreAtExitShutdown(void);
void gsCoreInitialize(void);
void gsiCoreTaskDispatchCallback(GSTask *theTask, int theResult);
int gsCoreTaskThink(GSTask *theTask);
void gsCoreThink(unsigned int theMS);
void gsCoreShutdown(void);
int gsCoreIsShutdown(void);
void gsiCoreExecuteTask(GSTask *theTask, unsigned int theTimeoutMs);
void gsiCoreCancelTask(GSTask *theTask);
GSTask *gsiCoreCreateTask(void);
extern char gGSCoreManager[];


void *gsiCoreGetManager(void)
{
    return gGSCoreManager;
}







/*
 * Calls gsiDeleteCriticalSection on the block sixteen bytes into the result.
 */
void gsiCoreAtExitShutdown(void)
{
    gsiDeleteCriticalSection((char *)gsiCoreGetManager() + 0x10);
}








void gsCoreInitialize(void)
{
    GSCoreMgr *aCore = (void *)gsiCoreGetManager();

    while (aCore->mIsShuttingDown)
        msleep(100);
    if (func_0217F0B4(&aCore->mRefCount) == 1) {
        if (!aCore->mIsStaticInitComplete) {
            gsiInitializeCriticalSection(aCore->mQueueCrit);
            MSL_C_LIB_LockRegisterDestructor((u32)gsiCoreAtExitShutdown);
            aCore->mIsStaticInitComplete = 1;
        }
        gsiEnterCriticalSection(aCore->mQueueCrit);
        gsiLeaveCriticalSection(aCore->mQueueCrit);
        while (aCore->mIsShuttingDown)
            msleep(100);
        aCore->mTaskArray = func_02184144(4, 10, 0);
        ghttpStartup();
        aCore->mIsInitialized = 1;
    } else {
        while (!aCore->mIsStaticInitComplete)
            msleep(100);
        gsiEnterCriticalSection(aCore->mQueueCrit);
        gsiLeaveCriticalSection(aCore->mQueueCrit);
        while (!aCore->mIsInitialized)
            msleep(100);
    }
}








/*
 * sdk:      gsiCoreTaskDispatchCallback (gscore.o)
 */
void gsiCoreTaskDispatchCallback(GSTask *theTask, int theResult)
{
    if (theTask->mIsCallbackPending) {
        void (*cb)(void *, int);
        theTask->mIsCallbackPending = 0;
        cb = theTask->mCallbackFunc;
        if (cb != 0)
            cb(theTask->mTaskData, theResult);
    }
}






/*
 * sdk:      gsCoreTaskThink (libdwcgscommon.TWL.HYB.a(gscore.o))
 */
int gsCoreTaskThink(GSTask *theTask)
{
    GSCoreMgr *aCore = (void *)gsiCoreGetManager();
    int aResult = 0;
    int i;
    int removeTask;
    int len;

    if (theTask == 0)
        return 4;
    if (theTask->mIsRunning && theTask->mThinkFunc)
        aResult = theTask->mThinkFunc(theTask->mTaskData);
    if (!theTask->mIsCanceled && aResult == 1) {
        if (theTask->mTimeout != 0) {
            if (current_time() - theTask->mStartTime > theTask->mTimeout) {
                gsiCoreCancelTask(theTask);
                gsiCoreTaskDispatchCallback(theTask, 3);
            }
        }
    } else if (aResult != 1) {
        removeTask = 1;
        if (theTask->mIsRunning) {
            gsiCoreTaskDispatchCallback(theTask, aResult);
            theTask->mIsRunning = 0;
        }
        if (theTask->mCleanupFunc)
            removeTask = theTask->mCleanupFunc(theTask->mTaskData);
        if (removeTask) {
            gsiEnterCriticalSection(aCore->mQueueCrit);
            len = func_02184200(aCore->mTaskArray);
            for (i = 0; i < len; i++) {
                if (*(GSTask **)func_02184208(aCore->mTaskArray, i) == theTask) {
                    func_02184324(aCore->mTaskArray, i);
                    func_0217EAE0(theTask);
                    break;
                }
            }
            gsiLeaveCriticalSection(aCore->mQueueCrit);
            return 4;
        }
    }
    return 1;
}







/*
 * sdk:      gsCoreThink (gscore.o)
 * evidence: +0x98 calls 0x021C204C, where symbols_sdk.json has two rows
 *           (ov016 procInit1, ov114 ghttpCleanup).  The vendor object
 *           libdwcgscommon.TWL.HYB.a(gscore.o) carries a PC24 relocation at
 *           +0x98 naming ghttpCleanup, and the only catalog row with that
 *           name is ov114 (libdwcgsghttp ghttpmain.o) at 0x021C204C, so the
 *           hint is ov114 (tools/sdkobj.py --region ov009 0x0217CCCC).
 */
void gsCoreThink(unsigned int theMS)
{
    GSCoreMgr *aCore = (void *)gsiCoreGetManager();
    int i;
    unsigned int aStartTime;
    int allTasksAreDead = 1;
    int len;
    GSTask *task;

    if (aCore->mIsInitialized == 0)
        return;
    gsiEnterCriticalSection(aCore->mQueueCrit);
    aStartTime = current_time();
    len = func_02184200(aCore->mTaskArray);
    if (len > 0)
        allTasksAreDead = 0;
    for (i = len - 1; i >= 0; i--) {
        task = *(GSTask **)func_02184208(aCore->mTaskArray, i);
        if (task->mAutoThink != 0)
            gsCoreTaskThink(task);
        if (theMS != 0 && current_time() - aStartTime > theMS)
            break;
    }
    if (aCore->mIsShuttingDown != 0 && allTasksAreDead) {
        ghttpCleanup();
        if (aCore->mTaskArray != 0) {
            func_021841B0(aCore->mTaskArray);
            aCore->mTaskArray = 0;
        }
        aCore->mIsShuttingDown = 0;
    }
    gsiLeaveCriticalSection(aCore->mQueueCrit);
}








/*
 * sdk:      gsCoreShutdown (gscore.o)
 */
void gsCoreShutdown(void)
{
    GSCoreMgr *aCore = (void *)gsiCoreGetManager();
    int i;
    int len;

    if (aCore->mIsInitialized == 0)
        return;
    gsiEnterCriticalSection(aCore->mQueueCrit);
    if (func_0217F0D8(&aCore->mRefCount) != 0) {
        gsiLeaveCriticalSection(aCore->mQueueCrit);
        return;
    }
    aCore->mIsShuttingDown = 1;
    len = func_02184200(aCore->mTaskArray);
    for (i = 0; i < len; i++)
        gsiCoreCancelTask(*(GSTask **)func_02184208(aCore->mTaskArray, i));
    gsiLeaveCriticalSection(aCore->mQueueCrit);
}








/*
 * sdk:      gsCoreIsShutdown (gscore.o)
 */
int gsCoreIsShutdown(void)
{
    GSCoreMgr *aCore = (void *)gsiCoreGetManager();
    if (aCore->mIsShuttingDown != 0)
        return 1;
    if (aCore->mRefCount == 0)
        return 2;
    return 0;
}






/*
 * sdk:      gsiCoreExecuteTask (gscore.o)
 */
void gsiCoreExecuteTask(GSTask *theTask, unsigned int theTimeoutMs)
{
    GSCoreMgr *aCore = (void *)gsiCoreGetManager();
    theTask->mIsCallbackPending = 1;
    theTask->mIsStarted = 1;
    theTask->mIsRunning = 1;
    theTask->mTimeout = theTimeoutMs;
    theTask->mStartTime = current_time();
    if (theTask->mExecuteFunc != 0)
        theTask->mExecuteFunc(theTask->mTaskData);
    gsiEnterCriticalSection(aCore->mQueueCrit);
    func_02184234(aCore->mTaskArray, &theTask);
    gsiLeaveCriticalSection(aCore->mQueueCrit);
}




/*
 * sdk:      gsiCoreCancelTask (gscore.o)
 */
void gsiCoreCancelTask(GSTask *theTask)
{
    GSCoreMgr *aCore = (void *)gsiCoreGetManager();
    gsiEnterCriticalSection(aCore->mQueueCrit);
    if (theTask->mIsRunning != 0 && theTask->mIsCanceled == 0) {
        theTask->mIsCanceled = 1;
        if (theTask->mCancelFunc != 0)
            theTask->mCancelFunc(theTask->mTaskData);
    }
    gsiLeaveCriticalSection(aCore->mQueueCrit);
}



/*
 * sdk:      gsiCoreCreateTask (gscore.o)
 */
GSTask *gsiCoreCreateTask(void)
{
    GSTask *aTask = (GSTask *)func_0217EAB0(sizeof(GSTask));
    if (aTask == 0)
        return 0;
    MSL_C_LIB_MemsetPtr(aTask, 0, sizeof(GSTask));
    aTask->mAutoThink = 1;
    return aTask;
}
