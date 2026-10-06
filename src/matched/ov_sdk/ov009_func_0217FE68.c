/*
 * function: func_0217FE68
 * address:  0x0217FE68
 * packet:   pkt_ov009_0217FE68
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiExecuteSoapCustom (gssoap.o)
 *
 * symbols:
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   func_0217CF24                  0x0217CF24  arm ov009
 *   func_0217CE48                  0x0217CE48  arm ov009
 *   func_0217FF94                  0x0217FF94  arm ov009
 *   func_0218005C                  0x0218005C  arm ov009
 *   func_0217FF70                  0x0217FF70  arm ov009
 *   func_02180080                  0x02180080  arm ov009
 *   func_0218002C                  0x0218002C  arm ov009
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
extern void *func_0217EAB0(unsigned long size);
extern GSTask *func_0217CF24(void);
extern void func_0217CE48(GSTask *theTask, unsigned int theTimeoutMs);
extern void func_0217FF94(void *theTask);
extern void func_0218005C(void *theTask);
extern int func_0217FF70(void *theTask);
extern int func_02180080(int *p);
extern void func_0218002C(void *theTask);

GSSoapTask *func_0217FE68(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void (*theCustomFunc)(void *, void *), void *theUserData)
{
    GSSoapTask *aSoapTask;
    GSTask *aCoreTask;

    aSoapTask = (GSSoapTask *)func_0217EAB0(sizeof(GSSoapTask));
    aSoapTask->callback = theCallbackFunc;
    aSoapTask->customFunc = theCustomFunc;
    aSoapTask->url = theURL;
    aSoapTask->service = theService;
    aSoapTask->request = theRequestSoap;
    aSoapTask->post = 0;
    aSoapTask->stream = 0;
    aSoapTask->buffer = 0;
    aSoapTask->userData = theUserData;
    aSoapTask->result = 0;
    aSoapTask->completed = 0;
    aCoreTask = func_0217CF24();
    aCoreTask->callback = func_0218005C;
    aCoreTask->execute = func_0217FF94;
    aCoreTask->think = func_0217FF70;
    aCoreTask->cleanup = (int (*)(void *))func_02180080;
    aCoreTask->cancel = func_0218002C;
    aCoreTask->obj = aSoapTask;
    aSoapTask->coreTask = aCoreTask;
    func_0217CE48(aCoreTask, 0);
    return aSoapTask;
}
