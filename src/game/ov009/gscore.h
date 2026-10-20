#ifndef GAME_OV009_GSCORE_H
#define GAME_OV009_GSCORE_H

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

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gscore.c, prototypes copied from their definitions. */

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
/* END mkheaders: generated region */

#endif
