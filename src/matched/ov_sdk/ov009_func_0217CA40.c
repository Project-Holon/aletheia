/*
 * function: gsCoreInitialize
 * address:  0x0217CA40
 * packet:   pkt_ov009_0217CA40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    mIsStaticInitComplete is declared volatile: without it mwcc hoists the field load above the refcount branch (both arms read it) and the image keeps one load per arm. sdkobj renders the DWARF member as plain int.
 *
 * sdk:      gsCoreInitialize (libdwcgscommon.TWL.HYB.a(gscore.o))
 *
 * symbols:
 *   gsiCoreGetManager  0x0217CA20  arm  ov009
 *   msleep  0x0217F2BC  arm  ov009
 *   gsiInterlockedIncrement  0x0217F0B4  arm  ov009
 *   gsiInitializeCriticalSection  0x0217F0FC  arm  ov009
 *   MSL_C_LIB_LockRegisterDestructor  0x020912A8  arm
 *   gsiEnterCriticalSection  0x0217F108  arm  ov009
 *   gsiLeaveCriticalSection  0x0217F114  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   ghttpStartup  0x021C1FF8  arm  ov114
 *   gsiCoreAtExitShutdown  0x0217CA2C  arm  ov009
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

extern void *gsiCoreGetManager(void);
extern void msleep(unsigned int msec);
extern unsigned int gsiInterlockedIncrement(unsigned int *value);
extern void gsiInitializeCriticalSection(void *mutex);
extern u32 MSL_C_LIB_LockRegisterDestructor(u32 a0);
extern void gsiEnterCriticalSection(void *mutex);
extern void gsiLeaveCriticalSection(void *mutex);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void ghttpStartup(void);
extern void gsiCoreAtExitShutdown(void);

void gsCoreInitialize(void)
{
    GSCoreMgr *aCore = gsiCoreGetManager();

    while (aCore->mIsShuttingDown)
        msleep(100);
    if (gsiInterlockedIncrement(&aCore->mRefCount) == 1) {
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
