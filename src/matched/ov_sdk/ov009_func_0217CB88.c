/*
 * function: func_0217CB88
 * address:  0x0217CB88
 * packet:   pkt_ov009_0217CB88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsCoreTaskThink (libdwcgscommon.TWL.HYB.a(gscore.o))
 *
 * symbols:
 *   func_0217CA20  0x0217CA20  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217CECC  0x0217CECC  arm  ov009
 *   func_0217CB5C  0x0217CB5C  arm  ov009
 *   func_0217F108  0x0217F108  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02184324  0x02184324  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_0217F114  0x0217F114  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    unsigned int mRefCount;
    int mIsStaticInitComplete;
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

extern void *func_0217CA20(void);
extern unsigned int func_0217F264(void);
extern void func_0217CECC(GSTask *theTask);
extern void func_0217CB5C(GSTask *theTask, int theResult);
extern void func_0217F108(void *mutex);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_02184324(void *array, int n);
extern void func_0217EAE0(void *ptr);
extern void func_0217F114(void *mutex);

int func_0217CB88(GSTask *theTask)
{
    GSCoreMgr *aCore = func_0217CA20();
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
            if (func_0217F264() - theTask->mStartTime > theTask->mTimeout) {
                func_0217CECC(theTask);
                func_0217CB5C(theTask, 3);
            }
        }
    } else if (aResult != 1) {
        removeTask = 1;
        if (theTask->mIsRunning) {
            func_0217CB5C(theTask, aResult);
            theTask->mIsRunning = 0;
        }
        if (theTask->mCleanupFunc)
            removeTask = theTask->mCleanupFunc(theTask->mTaskData);
        if (removeTask) {
            func_0217F108(aCore->mQueueCrit);
            len = func_02184200(aCore->mTaskArray);
            for (i = 0; i < len; i++) {
                if (*(GSTask **)func_02184208(aCore->mTaskArray, i) == theTask) {
                    func_02184324(aCore->mTaskArray, i);
                    func_0217EAE0(theTask);
                    break;
                }
            }
            func_0217F114(aCore->mQueueCrit);
            return 4;
        }
    }
    return 1;
}
