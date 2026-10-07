/*
 * file:     unit_0217FD7C_p01.c
 * unit:     yes
 * function: func_0217FD7C, func_0217FDA0
 * address:  0x0217FD7C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   func_0217CF24                  0x0217CF24  arm ov009
 *   func_0217CE48                  0x0217CE48  arm ov009
 *   func_0217EAE0                  0x0217EAE0  arm ov009
 *   func_0217FF94                  0x0217FF94  arm ov009
 *   func_0218005C                  0x0218005C  arm ov009
 *   func_0217FF70                  0x0217FF70  arm ov009
 *   func_02180080                  0x02180080  arm ov009
 *   func_0218002C                  0x0218002C  arm ov009
 */
typedef void (*GSSoapCallback)(int, void *, void *, void *);

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

extern void *func_0217EAB0(unsigned long size);
extern GSTask *func_0217CF24(void);
extern void func_0217CE48(GSTask *theTask, unsigned int theTimeoutMs);
extern void func_0217EAE0(void *ptr);
extern void func_0217FF94(void *theTask);
extern void func_0218005C(void *theTask);
extern int func_0217FF70(void *theTask);
extern int func_02180080(int *p);
extern void func_0218002C(void *theTask);
void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void *theUserData);
GSSoapTask *func_0217FDA0(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, unsigned int theTimeoutMs, void *theUserData);


/*
 * sdk:      gsiExecuteSoap (gssoap.o)
 */
void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void *theUserData)
{
    return func_0217FDA0(theURL, theService, theRequestSoap, theCallbackFunc, 0, theUserData);
}


GSSoapTask *func_0217FDA0(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, unsigned int theTimeoutMs, void *theUserData)
{
    GSSoapTask *aSoapTask;
    GSTask *aCoreTask;

    aSoapTask = (GSSoapTask *)func_0217EAB0(sizeof(GSSoapTask));
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
    aCoreTask = func_0217CF24();
    if (aCoreTask == 0) {
        func_0217EAE0(aSoapTask);
        return 0;
    }
    aCoreTask->callback = func_0218005C;
    aCoreTask->execute = func_0217FF94;
    aCoreTask->think = func_0217FF70;
    aCoreTask->cleanup = (int (*)(void *))func_02180080;
    aCoreTask->cancel = func_0218002C;
    aCoreTask->obj = aSoapTask;
    aSoapTask->coreTask = aCoreTask;
    func_0217CE48(aCoreTask, theTimeoutMs);
    return aSoapTask;
}
