/*
 * file:     unit_021C1D30_p01.c
 * unit:     yes
 * function: func_021C1FF8, func_021C204C, func_021C20A4
 * address:  0x021C1FF8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0370  0x021C0370  arm  ov114
 *   func_021C0368  0x021C0368  arm  ov114
 *   func_021C0374  0x021C0374  arm  ov114
 *   g_021D3B64  0x021D3B64  data
 *   g_021CE5AC  0x021CE5AC  data
 *   g_021CE5B0  0x021CE5B0  data
 *   func_021C0FB0  0x021C0FB0  arm  ov114
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021C036C  0x021C036C  arm  ov114
 *   g_021D3B2C  0x021D3B2C  data
 *   func_021C0998                    0x021c0998 arm  ov114
 *   func_0217F1E0                    0x0217f1e0 arm  ov009
 *   func_021C0D40                    0x021c0d40 arm  ov114
 *   func_021BFC54                    0x021bfc54 arm  ov114
 *   func_021BFBD0                    0x021bfbd0 arm  ov114
 *   func_021C2A78                    0x021c2a78 arm  ov114
 *   func_021C1DEC                    0x021c1dec arm  ov114
 *   func_0217F2BC                    0x0217f2bc arm  ov009
 */
#include "../../matched/include/G_GHIThrottle.h"

typedef void (*GHTTPProgressCallback)(int request, int state, const char *buffer,
                                      int bufferLen, int bytesReceived,
                                      int totalSize, void *param);

typedef int (*GHTTPCompletedCallback)(int request, int result, char *buffer,
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
    GHTTPProgressCallback progressCallback;   /* +0x044 */
    GHTTPCompletedCallback completedCallback; /* +0x048 */
    void *callbackParam;        /* +0x04c */
    char pad50[0xe8 - 0x50];
    char getFileBuffer[0x24];   /* +0x0e8 */
    int userBufferSupplied;     /* +0x10c */
    char pad110[0x15c - 0x110];
    int throttle;               /* +0x15c */
    char pad160[0x164 - 0x160];
    void *post;                 /* +0x164 */
} GHIConnection;

extern void func_021C0370(void);
extern void func_021C0368(void);
extern void func_021C0374(void);
extern void func_021C0FB0(void);
extern void func_0217EAE0(void *ptr);
extern void func_021C036C(void);
extern GHIConnection *func_021C0998(void);
extern char *func_0217F1E0(const char *src);
extern int func_021C0D40(GHIConnection *connection);
extern int func_021BFC54(int a, int *out, char *buf, int n);
extern int func_021BFBD0(unsigned int a0, unsigned int *a1, int a2, int a3);
extern int func_021C2A78(GHIConnection *connection);
extern int func_021C1DEC(GHIConnection *connection);
extern void func_0217F2BC(unsigned int msec);
void func_021C1FF8(void);
void func_021C204C(void);
int func_021C20A4(const char *URL, const char *headers, char *buffer, int bufferSize, void *post, int throttle, int blocking, GHTTPProgressCallback progressCallback, GHTTPCompletedCallback completedCallback, void *param);
extern int g_021D3B64;
extern struct GHIThrottle g_021CE5AC;
extern int g_021CE5B0;
extern void *g_021D3B2C;


/*
 * sdk:      ghttpStartup (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 */
void func_021C1FF8(void)
{
	func_021C0370();
	if (++g_021D3B64 == 1) {
		func_021C0368();
		g_021CE5B0 = 125;
		(*(int *)&g_021CE5AC) = 250;
	} else {
		func_021C0374();
	}
}


/*
 * sdk:      ghttpCleanup (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 */
void func_021C204C(void)
{
	func_021C0370();
	if (--g_021D3B64 == 0) {
		func_021C0FB0();
		if (g_021D3B2C != 0) {
			func_0217EAE0(g_021D3B2C);
			g_021D3B2C = 0;
		}
		func_021C0374();
		func_021C036C();
	} else {
		func_021C0374();
	}
}


/*
 * sdk:      ghttpGetExA (ghttpmain.o)
 */
int func_021C20A4(const char *URL, const char *headers, char *buffer, int bufferSize,
                  void *post, int throttle, int blocking,
                  GHTTPProgressCallback progressCallback,
                  GHTTPCompletedCallback completedCallback, void *param)
{
    GHIConnection *connection;
    int bResult;

    if (!URL || !*URL)
        return -1;
    if (bufferSize < 0)
        return -1;
    if (buffer && !bufferSize)
        return -1;

    if (!g_021D3B64)
        func_021C1FF8();

    connection = func_021C0998();
    if (!connection)
        return -1;

    connection->type = 0;
    connection->URL = func_0217F1E0(URL);
    if (!connection->URL) {
        func_021C0D40(connection);
        return -1;
    }
    if (headers && *headers) {
        connection->sendHeaders = func_0217F1E0(headers);
        if (!connection->sendHeaders) {
            func_021C0D40(connection);
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
        bResult = func_021BFC54((int)connection, (int *)connection->getFileBuffer, buffer, bufferSize);
    else
        bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)connection->getFileBuffer, 0x800, 0x800);
    if (!bResult) {
        func_021C0D40(connection);
        return -1;
    }

    if (post) {
        if (!func_021C2A78(connection)) {
            func_021C0D40(connection);
            return -1;
        }
    }

    if (blocking) {
        while (!func_021C1DEC(connection))
            func_0217F2BC(10);
        return 0;
    }

    return connection->request;
}
