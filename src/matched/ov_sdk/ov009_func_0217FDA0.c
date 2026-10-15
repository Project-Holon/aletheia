/*
 * function: gsiExecuteSoapWithTimeout
 * address:  0x0217FDA0
 * packet:   pkt_ov009_0217FDA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiExecuteSoapWithTimeout (gssoap.o)
 *
 * symbols:
 *   gsimalloc                  0x0217EAB0  arm ov009
 *   gsiCoreCreateTask                  0x0217CF24  arm ov009
 *   gsiCoreExecuteTask                  0x0217CE48  arm ov009
 *   gsifree                  0x0217EAE0  arm ov009
 *   gsiSoapTaskExecute                  0x0217FF94  arm ov009
 *   gsiSoapTaskCallback                  0x0218005C  arm ov009
 *   gsiSoapTaskThink                  0x0217FF70  arm ov009
 *   gsiSoapTaskCleanup                  0x02180080  arm ov009
 *   gsiSoapTaskCancel                  0x0218002C  arm ov009
 */

typedef struct GSTask {
    char pad0[0x20];
    void *obj;
    void (*execute)(void *);
    void (*callback)(void *);
    void (*cancel)(void *);
    int (*cleanup)(void *);
    int (*think)(void *);
} GSTask;
typedef struct GSSoapTask {
    void (*callback)(int, void *, void *, void *);
    void (*customFunc)(void *, void *);
    char *url;
    char *service;
    void *request;
    void *stream;
    char *buffer;
    void *post;
    void *userData;
    GSTask *coreTask;
    int httpRequest;
    int result;
    int completed;
} GSSoapTask;
typedef void (*GSSoapCallback)(int, void *, void *, void *);
extern void *gsimalloc(unsigned long size);
extern GSTask *gsiCoreCreateTask(void);
extern void gsiCoreExecuteTask(GSTask *theTask, unsigned int theTimeoutMs);
extern void gsifree(void *ptr);
extern void gsiSoapTaskExecute(void *theTask);
extern void gsiSoapTaskCallback(void *theTask);
extern int gsiSoapTaskThink(void *theTask);
extern int gsiSoapTaskCleanup(int *p);
extern void gsiSoapTaskCancel(void *theTask);

GSSoapTask *gsiExecuteSoapWithTimeout(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, unsigned int theTimeoutMs, void *theUserData)
{
    GSSoapTask *aSoapTask;
    GSTask *aCoreTask;

    aSoapTask = (GSSoapTask *)gsimalloc(sizeof(GSSoapTask));
    if (aSoapTask == 0)
        return 0;
    aSoapTask->callback = theCallbackFunc;
    aSoapTask->customFunc = 0;
    aSoapTask->url = theURL;
    aSoapTask->service = theService;
    aSoapTask->request = theRequestSoap;
    aSoapTask->post = 0;
    aSoapTask->stream = 0;
    aSoapTask->buffer = 0;
    aSoapTask->userData = theUserData;
    aSoapTask->result = 0;
    aSoapTask->completed = 0;
    aCoreTask = gsiCoreCreateTask();
    if (aCoreTask == 0) {
        gsifree(aSoapTask);
        return 0;
    }
    aCoreTask->callback = gsiSoapTaskCallback;
    aCoreTask->execute = gsiSoapTaskExecute;
    aCoreTask->think = gsiSoapTaskThink;
    aCoreTask->cleanup = (int (*)(void *))gsiSoapTaskCleanup;
    aCoreTask->cancel = gsiSoapTaskCancel;
    aCoreTask->obj = aSoapTask;
    aSoapTask->coreTask = aCoreTask;
    gsiCoreExecuteTask(aCoreTask, theTimeoutMs);
    return aSoapTask;
}
