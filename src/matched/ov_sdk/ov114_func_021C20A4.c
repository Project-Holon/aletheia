/*
 * function: ghttpGetExA
 * address:  0x021C20A4
 * packet:   pkt_ov114_021C20A4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghttpGetExA (ghttpmain.o)
 *
 * symbols:
 *   ghttpStartup                    0x021c1ff8 arm  ov114
 *   ghiNewConnection                    0x021c0998 arm  ov114
 *   goastrdup                    0x0217f1e0 arm  ov009
 *   ghiFreeConnection                    0x021c0d40 arm  ov114
 *   ghiInitFixedBuffer                    0x021bfc54 arm  ov114
 *   ghiInitBuffer                    0x021bfbd0 arm  ov114
 *   ghiPostInitState                    0x021c2a78 arm  ov114
 *   ghiProcessConnection                    0x021c1dec arm  ov114
 *   msleep                    0x0217f2bc arm  ov009
 *   gGhttpInitCount                       0x021d3b64 data
 */

typedef void (*GHTTPProgressCallbackFn)(int request, int state, const char *buffer,
                                      int bufferLen, int bytesReceived,
                                      int totalSize, void *param);
typedef int (*GHTTPCompletedCallbackFn)(int request, int result, char *buffer,
                                      int bufferLen, void *param);

typedef struct GHIConnection {
    int inUse;                  /* +0x000 */
    int request;                /* +0x004 */
    char pad8[0xc - 0x8];
    int type;                   /* +0x00c */
    char pad10[0x14 - 0x10];
    char *URL;                  /* +0x014 */
    char pad18[0x2c - 0x18];
    char *sendHeaders;          /* +0x02c */
    char pad30[0x38 - 0x30];
    int blocking;               /* +0x038 */
    char pad3c[0x44 - 0x3c];
    GHTTPProgressCallbackFn progressCallback;   /* +0x044 */
    GHTTPCompletedCallbackFn completedCallback; /* +0x048 */
    void *callbackParam;        /* +0x04c */
    char pad50[0xe8 - 0x50];
    char getFileBuffer[0x24];   /* +0x0e8 */
    int userBufferSupplied;     /* +0x10c */
    char pad110[0x15c - 0x110];
    int throttle;               /* +0x15c */
    char pad160[0x164 - 0x160];
    void *post;                 /* +0x164 */
} GHIConnection;

extern void ghttpStartup(void);
extern GHIConnection *ghiNewConnection(void);
extern char *goastrdup(const char *src);
extern int ghiFreeConnection(GHIConnection *connection);
extern int ghiInitFixedBuffer(int a, int *out, char *buf, int n);
extern int ghiInitBuffer(unsigned int a0, unsigned int *a1, int a2, int a3);
extern int ghiPostInitState(GHIConnection *connection);
extern int ghiProcessConnection(GHIConnection *connection);
extern void msleep(unsigned int msec);
extern int gGhttpInitCount;

int ghttpGetExA(const char *URL, const char *headers, char *buffer, int bufferSize,
                  void *post, int throttle, int blocking,
                  GHTTPProgressCallbackFn progressCallback,
                  GHTTPCompletedCallbackFn completedCallback, void *param)
{
    GHIConnection *connection;
    int bResult;

    if (!URL || !*URL)
        return -1;
    if (bufferSize < 0)
        return -1;
    if (buffer && !bufferSize)
        return -1;

    if (!gGhttpInitCount)
        ghttpStartup();

    connection = ghiNewConnection();
    if (!connection)
        return -1;

    connection->type = 0;
    connection->URL = goastrdup(URL);
    if (!connection->URL) {
        ghiFreeConnection(connection);
        return -1;
    }
    if (headers && *headers) {
        connection->sendHeaders = goastrdup(headers);
        if (!connection->sendHeaders) {
            ghiFreeConnection(connection);
            return -1;
        }
    }
    connection->post = post;
    connection->blocking = blocking;
    connection->progressCallback = progressCallback;
    connection->completedCallback = completedCallback;
    connection->callbackParam = param;
    connection->throttle = throttle;
    connection->userBufferSupplied = (buffer != 0);

    if (connection->userBufferSupplied)
        bResult = ghiInitFixedBuffer((int)connection, (int *)connection->getFileBuffer, buffer, bufferSize);
    else
        bResult = ghiInitBuffer((unsigned int)connection, (unsigned int *)connection->getFileBuffer, 0x800, 0x800);
    if (!bResult) {
        ghiFreeConnection(connection);
        return -1;
    }

    if (post) {
        if (!ghiPostInitState(connection)) {
            ghiFreeConnection(connection);
            return -1;
        }
    }

    if (blocking) {
        while (!ghiProcessConnection(connection))
            msleep(10);
        return 0;
    }

    return connection->request;
}
