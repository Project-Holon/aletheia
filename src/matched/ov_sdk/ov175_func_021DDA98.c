/*
 * function: sakeiExecuteRequest
 * address:  0x021DDA98
 * packet:   pkt_ov175_021DDA98
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeiExecuteRequest (sakerequest.o)
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   func_0217FD7C  0x0217FD7C  arm  ov009
 *   sakeiSoapCallback  0x021DD84C  arm  ov175
 *   gDwcGdbStorageServerUrl  0x021E4C88  data
 *   sServerUrlFormat  0x021E387C  data
 */

typedef struct SAKEInternal {
    unsigned char pad0[4];
    char gameName[1];
} SAKEInternal;

typedef struct GSSoapTask {
    unsigned char pad0[0x24];
    int f24;
} GSSoapTask;

typedef struct SAKEService {
    unsigned char pad0[8];
    char *serviceName;
    unsigned char padC[0x18];
    int f24;
} SAKEService;

typedef struct SAKERequestInternal {
    SAKEInternal *sake;
    unsigned char pad4[0x14];
    void *soapRequest;
    unsigned char pad1C[4];
    SAKEService *service;
} SAKERequestInternal;

extern char gDwcGdbStorageServerUrl[128];
extern char sServerUrlFormat[];
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern GSSoapTask *func_0217FD7C(char *url, char *service, void *soap, void (*callback)(int, void *, void *), void *userData);
extern void sakeiSoapCallback(int httpResult, int unused, void *responseData, void *userData);

void sakeiExecuteRequest(SAKERequestInternal *request)
{
    GSSoapTask *soapTask;

    if (!gDwcGdbStorageServerUrl[0])
        func_02084F80(gDwcGdbStorageServerUrl, 128, sServerUrlFormat, request->sake->gameName);
    soapTask = func_0217FD7C(gDwcGdbStorageServerUrl, request->service->serviceName, request->soapRequest, (void (*)(int,  void *, void *))sakeiSoapCallback, request);
    if (soapTask)
        request->service->f24 = soapTask->f24;
    else
        request->service->f24 = 0;
}
