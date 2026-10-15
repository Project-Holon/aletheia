/*
 * file:     gssoap.c
 * unit:     yes
 * function: gsiExecuteSoap, gsiExecuteSoapWithTimeout, gsiExecuteSoapCustom, gsiSoapTaskHttpCompletedCallback, gsiSoapTaskThink, gsiSoapTaskExecute, gsiSoapTaskCancel, gsiSoapTaskCallback, gsiSoapTaskCleanup
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
 *   gsimalloc                  0x0217EAB0  arm ov009
 *   gsiCoreCreateTask                  0x0217CF24  arm ov009
 *   gsiCoreExecuteTask                  0x0217CE48  arm ov009
 *   gsifree                  0x0217EAE0  arm ov009
 *   gsXmlCreateStreamReader                  0x02181C2C  arm ov009
 *   gsXmlParseBuffer                  0x02181D10  arm ov009
 *   ghttpRequestThink                  0x021C2284  arm
 *   ZUKAN_DETAIL_AREA_ResetBlendAlpha                  0x021C2304  arm
 *   ghttpPostSetAutoFree                  0x021C2310  arm
 *   ghttpPostAddXml                  0x021C2338  arm
 *   ghttpGetExA                  0x021C20A4  arm
 *   ghttpCancelRequest                  0x021C22A4  arm
 *   gsXmlFreeReader  0x02181DA0  arm  ov009
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

extern void *gsimalloc(unsigned long size);
extern GSTask *gsiCoreCreateTask(void);
extern void gsiCoreExecuteTask(GSTask *theTask, unsigned int theTimeoutMs);
extern void gsifree(void *ptr);
extern void *gsXmlCreateStreamReader(void);
extern int gsXmlParseBuffer(void *stream, char *data, int len);
extern int ghttpRequestThink(int request);
extern void *ZUKAN_DETAIL_AREA_ResetBlendAlpha();
extern void ghttpPostSetAutoFree(void *post, int autoFree);
extern void ghttpPostAddXml();
extern int ghttpGetExA(char *URL, char *headers, char *buffer, int bufferSize, void *post, int throttle, int blocking, void *progressCallback, int (*completedCallback)(int, int, char *, int, void *), void *param);
extern void ghttpCancelRequest(int request);
void gsXmlFreeReader(int x);
void ghttpFreePostAndUpdateConnection(int x, int y);
void *gsiExecuteSoap(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void *theUserData);
GSSoapTask *gsiExecuteSoapWithTimeout(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, unsigned int theTimeoutMs, void *theUserData);
GSSoapTask *gsiExecuteSoapCustom(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void (*theCustomFunc)(void *, void *), void *theUserData);
int gsiSoapTaskHttpCompletedCallback(int request, int result, char *buffer, int bufferLen, void *param);
int gsiSoapTaskThink(void *theTask);
void gsiSoapTaskExecute(void *theTask);
void gsiSoapTaskCancel(void *theTask);
void gsiSoapTaskCallback(void *theTask);
int gsiSoapTaskCleanup(void *theTask);






/*
 * sdk:      gsiExecuteSoap (gssoap.o)
 */
void *gsiExecuteSoap(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void *theUserData)
{
    return gsiExecuteSoapWithTimeout(theURL, theService, theRequestSoap, theCallbackFunc, 0, theUserData);
}






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
    aCoreTask->cleanup = gsiSoapTaskCleanup;
    aCoreTask->cancel = gsiSoapTaskCancel;
    aCoreTask->obj = aSoapTask;
    aSoapTask->coreTask = aCoreTask;
    gsiCoreExecuteTask(aCoreTask, theTimeoutMs);
    return aSoapTask;
}





/*
 * sdk:      gsiExecuteSoapCustom (gssoap.o)
 */
GSSoapTask *gsiExecuteSoapCustom(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void (*theCustomFunc)(void *, void *), void *theUserData)
{
    GSSoapTask *aSoapTask;
    GSTask *aCoreTask;

    aSoapTask = (GSSoapTask *)gsimalloc(sizeof(GSSoapTask));
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
    aCoreTask = gsiCoreCreateTask();
    aCoreTask->callback = gsiSoapTaskCallback;
    aCoreTask->execute = gsiSoapTaskExecute;
    aCoreTask->think = gsiSoapTaskThink;
    aCoreTask->cleanup = gsiSoapTaskCleanup;
    aCoreTask->cancel = gsiSoapTaskCancel;
    aCoreTask->obj = aSoapTask;
    aSoapTask->coreTask = aCoreTask;
    gsiCoreExecuteTask(aCoreTask, 0);
    return aSoapTask;
}






int gsiSoapTaskHttpCompletedCallback(int request, int result, char *buffer, int bufferLen, void *param)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)param;
    int parseResult;

    aSoapTask->result = result;
    aSoapTask->completed = 1;
    aSoapTask->buffer = buffer;
    if (result == 0) {
        aSoapTask->stream = gsXmlCreateStreamReader();
        if (aSoapTask->stream == 0) {
            aSoapTask->result = 1;
        } else {
            parseResult = gsXmlParseBuffer(aSoapTask->stream, buffer, bufferLen);
            if (parseResult == 0)
                aSoapTask->result = 7;
        }
    }
    return 0;
}






/*
 * sdk:      gsiSoapTaskThink (gssoap.o)
 */
int gsiSoapTaskThink(void *theTask)
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
void gsiSoapTaskExecute(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;

    aSoapTask->post = ZUKAN_DETAIL_AREA_ResetBlendAlpha();
    if (aSoapTask->post == 0) {
        aSoapTask->completed = 1;
        aSoapTask->result = 1;
        return;
    }
    ghttpPostSetAutoFree(aSoapTask->post, 0);
    ghttpPostAddXml(aSoapTask->post, aSoapTask->request);
    if (aSoapTask->customFunc != 0)
        aSoapTask->customFunc(aSoapTask->post, aSoapTask->userData);
    aSoapTask->httpRequest = ghttpGetExA(aSoapTask->url, aSoapTask->service, 0, 0, aSoapTask->post, 0, 0, 0, gsiSoapTaskHttpCompletedCallback, aSoapTask);
}



/*
 * sdk:      gsiSoapTaskCancel (gssoap.o)
 */
void gsiSoapTaskCancel(void *theTask)
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
void gsiSoapTaskCallback(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;
    aSoapTask->callback(aSoapTask->result, aSoapTask->request, aSoapTask->stream, aSoapTask->userData);
}



/*
 * Destructor: releases three optional sub-objects then the object itself, and
 * always reports success.
 */
int gsiSoapTaskCleanup(void *theTask)
{
    GSSoapTask *p = (GSSoapTask *)theTask;

    if (p->stream)
        gsXmlFreeReader((int)p->stream);
    if (p->buffer)
        gsifree(p->buffer);
    if (p->post)
        ghttpFreePostAndUpdateConnection(p->httpRequest, (int)p->post);
    gsifree(p);
    return 1;
}
