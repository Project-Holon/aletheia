/*
 * file:     gssoap.c
 * unit:     yes
 * function: func_0217FD7C, func_0217FDA0, func_0217FE68, func_0217FF14, func_0217FF70, func_0217FF94, func_0218002C, func_0218005C, func_02180080
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
 *   func_02181C2C                  0x02181C2C  arm ov009
 *   func_02181D10                  0x02181D10  arm ov009
 *   ghttpRequestThink                  0x021C2284  arm
 *   func_021C2304                  0x021C2304  arm
 *   ghttpPostSetAutoFree                  0x021C2310  arm
 *   ghttpPostAddXml                  0x021C2338  arm
 *   ghttpGetExA                  0x021C20A4  arm
 *   ghttpCancelRequest                  0x021C22A4  arm
 *   func_02181DA0  0x02181DA0  arm  ov009
 *   ghttpFreePostAndUpdateConnection  0x021C2324  arm  ov114
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

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_0217EAB0(unsigned long size);
extern GSTask *func_0217CF24(void);
extern void func_0217CE48(GSTask *theTask, unsigned int theTimeoutMs);
extern void func_0217EAE0(void *ptr);
extern void *func_02181C2C(void);
extern int func_02181D10(void *stream, char *data, int len);
extern int ghttpRequestThink(int request);
extern void *func_021C2304();
extern void ghttpPostSetAutoFree(void *post, int autoFree);
extern void ghttpPostAddXml();
extern int ghttpGetExA(char *URL, char *headers, char *buffer, int bufferSize, void *post, int throttle, int blocking, void *progressCallback, int (*completedCallback)(int, int, char *, int, void *), void *param);
extern void ghttpCancelRequest(int request);
void func_02181DA0(int x);
void ghttpFreePostAndUpdateConnection(int x, int y);
void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void *theUserData);
GSSoapTask *func_0217FDA0(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, unsigned int theTimeoutMs, void *theUserData);
GSSoapTask *func_0217FE68(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void (*theCustomFunc)(void *, void *), void *theUserData);
int func_0217FF14(int request, int result, char *buffer, int bufferLen, void *param);
int func_0217FF70(void *theTask);
void func_0217FF94(void *theTask);
void func_0218002C(void *theTask);
void func_0218005C(void *theTask);
int func_02180080(void *theTask);






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
    aCoreTask->cleanup = func_02180080;
    aCoreTask->cancel = func_0218002C;
    aCoreTask->obj = aSoapTask;
    aSoapTask->coreTask = aCoreTask;
    func_0217CE48(aCoreTask, theTimeoutMs);
    return aSoapTask;
}





/*
 * sdk:      gsiExecuteSoapCustom (gssoap.o)
 */
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
    aCoreTask->cleanup = func_02180080;
    aCoreTask->cancel = func_0218002C;
    aCoreTask->obj = aSoapTask;
    aSoapTask->coreTask = aCoreTask;
    func_0217CE48(aCoreTask, 0);
    return aSoapTask;
}






int func_0217FF14(int request, int result, char *buffer, int bufferLen, void *param)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)param;
    int parseResult;

    aSoapTask->result = result;
    aSoapTask->completed = 1;
    aSoapTask->buffer = buffer;
    if (result == 0) {
        aSoapTask->stream = func_02181C2C();
        if (aSoapTask->stream == 0) {
            aSoapTask->result = 1;
        } else {
            parseResult = func_02181D10(aSoapTask->stream, buffer, bufferLen);
            if (parseResult == 0)
                aSoapTask->result = 7;
        }
    }
    return 0;
}






/*
 * sdk:      gsiSoapTaskThink (gssoap.o)
 */
int func_0217FF70(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;
    if (aSoapTask->completed != 0)
        return 4;
    ghttpRequestThink(aSoapTask->httpRequest);
    return 1;
}





/*
 * sdk:      gsiSoapTaskExecute (gssoap.o)
 */
void func_0217FF94(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;

    aSoapTask->post = func_021C2304();
    if (aSoapTask->post == 0) {
        aSoapTask->completed = 1;
        aSoapTask->result = 1;
        return;
    }
    ghttpPostSetAutoFree(aSoapTask->post, 0);
    ghttpPostAddXml(aSoapTask->post, aSoapTask->request);
    if (aSoapTask->customFunc != 0)
        aSoapTask->customFunc(aSoapTask->post, aSoapTask->userData);
    aSoapTask->httpRequest = ghttpGetExA(aSoapTask->url, aSoapTask->service, 0, 0, aSoapTask->post, 0, 0, 0, func_0217FF14, aSoapTask);
}



/*
 * sdk:      gsiSoapTaskCancel (gssoap.o)
 */
void func_0218002C(void *theTask)
{
    GSSoapTask *soapTask = (GSSoapTask *)theTask;
    if (soapTask->completed != 0)
        return;
    if (soapTask->httpRequest >= 0)
        ghttpCancelRequest(soapTask->httpRequest);
    soapTask->result = 18;
}



/*
 * sdk:      gsiSoapTaskCallback (gssoap.o)
 */
void func_0218005C(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;
    aSoapTask->callback(aSoapTask->result, aSoapTask->request, aSoapTask->stream, aSoapTask->userData);
}



/*
 * Destructor: releases three optional sub-objects then the object itself, and
 * always reports success.
 */
int func_02180080(void *theTask)
{
    GSSoapTask *p = (GSSoapTask *)theTask;

    if (p->stream)
        func_02181DA0((int)p->stream);
    if (p->buffer)
        func_0217EAE0(p->buffer);
    if (p->post)
        ghttpFreePostAndUpdateConnection(p->httpRequest, (int)p->post);
    func_0217EAE0(p);
    return 1;
}
