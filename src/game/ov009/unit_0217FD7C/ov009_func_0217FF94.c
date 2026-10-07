/*
 * function: func_0217FF94
 * address:  0x0217FF94
 * packet:   pkt_ov009_0217FF94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiSoapTaskExecute (gssoap.o)
 *
 * symbols:
 *   func_021C2304                  0x021C2304  arm
 *   func_021C2310                  0x021C2310  arm
 *   func_021C2338                  0x021C2338  arm
 *   func_021C20A4                  0x021C20A4  arm
 *   func_0217FF14                  0x0217FF14  arm ov009
 */

typedef struct GSSoapTask {
    void (*callback)(int, void *, void *, void *);
    void (*customFunc)(void *, void *);
    char *url;
    char *headers;
    void *request;
    void *stream;
    char *buffer;
    void *post;
    void *userData;
    void *coreTask;
    int httpRequest;
    int result;
    int completed;
} GSSoapTask;

extern void *func_021C2304();
extern void func_021C2310(void *post, int autoFree);
extern void func_021C2338();
extern int func_021C20A4(char *URL, char *headers, char *buffer, int bufferSize, void *post, int throttle, int blocking, void *progressCallback, int (*completedCallback)(int, int, char *, int, void *), void *param);
extern int func_0217FF14(int request, int result, char *buffer, int bufferLen, void *param);

void func_0217FF94(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;

    aSoapTask->post = func_021C2304();
    if (aSoapTask->post == 0) {
        aSoapTask->completed = 1;
        aSoapTask->result = 1;
        return;
    }
    func_021C2310(aSoapTask->post, 0);
    func_021C2338(aSoapTask->post, aSoapTask->request);
    if (aSoapTask->customFunc != 0)
        aSoapTask->customFunc(aSoapTask->post, aSoapTask->userData);
    aSoapTask->httpRequest = func_021C20A4(aSoapTask->url, aSoapTask->headers, 0, 0, aSoapTask->post, 0, 0, 0, func_0217FF14, aSoapTask);
}
