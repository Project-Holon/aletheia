/*
 * function: func_0217CA40
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
 *   func_0217CA20  0x0217CA20  arm  ov009
 *   func_0217F2BC  0x0217F2BC  arm  ov009
 *   func_0217F0B4  0x0217F0B4  arm  ov009
 *   func_0217F0FC  0x0217F0FC  arm  ov009
 *   func_020912A8  0x020912A8  arm
 *   func_0217F108  0x0217F108  arm  ov009
 *   func_0217F114  0x0217F114  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_021C1FF8  0x021C1FF8  arm  ov114
 *   func_0217CA2C  0x0217CA2C  arm  ov009
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

extern GSCoreMgr *func_0217CA20(void);
extern void func_0217F2BC();
extern unsigned int func_0217F0B4(unsigned int *value);
extern void func_0217F0FC();
extern void func_020912A8();
extern void func_0217F108();
extern void func_0217F114();
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void func_021C1FF8(void);
extern void func_0217CA2C(void);

void func_0217CA40(void)
{
    GSCoreMgr *aCore = func_0217CA20();

    while (aCore->mIsShuttingDown)
        func_0217F2BC(100);
    if (func_0217F0B4(&aCore->mRefCount) == 1) {
        if (!aCore->mIsStaticInitComplete) {
            func_0217F0FC(aCore->mQueueCrit);
            func_020912A8(func_0217CA2C);
            aCore->mIsStaticInitComplete = 1;
        }
        func_0217F108(aCore->mQueueCrit);
        func_0217F114(aCore->mQueueCrit);
        while (aCore->mIsShuttingDown)
            func_0217F2BC(100);
        aCore->mTaskArray = func_02184144(4, 10, 0);
        func_021C1FF8();
        aCore->mIsInitialized = 1;
    } else {
        while (!aCore->mIsStaticInitComplete)
            func_0217F2BC(100);
        func_0217F108(aCore->mQueueCrit);
        func_0217F114(aCore->mQueueCrit);
        while (!aCore->mIsInitialized)
            func_0217F2BC(100);
    }
}
