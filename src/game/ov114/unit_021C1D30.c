/*
 * file:     unit_021C1D30.c
 * unit:     yes
 * function: func_021C1D30, func_021C1DEC, func_021C1FF8, func_021C204C, func_021C20A4
 * address:  0x021C1D30
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
 *   func_021C3BAC                    0x021c3bac arm  ov114
 *   func_021C3D10                    0x021c3d10 arm  ov114
 *   func_021C3E10                    0x021c3e10 arm  ov114
 *   func_021C3EC0                    0x021c3ec0 arm  ov114
 *   func_021C4150                    0x021c4150 arm  ov114
 *   func_021C4384                    0x021c4384 arm  ov114
 *   func_021C4684                    0x021c4684 arm  ov114
 *   func_021C4764                    0x021c4764 arm  ov114
 *   func_021C492C                    0x021c492c arm  ov114
 *   func_021C4E7C                    0x021c4e7c arm  ov114
 *   func_021C5430                    0x021c5430 arm  ov114
 *   func_0217D254                    0x0217d254 arm  ov009
 *   func_021C0E58                    0x021c0e58 arm  ov114
 *   func_0217EF50                    0x0217ef50 arm  ov009
 *   func_021C0B4C                    0x021c0b4c arm  ov114
 *   func_021C0244                    0x021c0244 arm  ov114
 *   func_021C0C14                    0x021c0c14 arm  ov114
 *   g_021CED74                       0x021ced74 data
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
 *   msleep                    0x0217f2bc arm  ov009
 */
#include "../../matched/include/G_GHIThrottle.h"

struct Ctx;
#include "ghttp_types.h"


extern void func_021C3BAC(GHIConnection *connection);
extern void func_021C3D10(GHIConnection *connection);
extern void func_021C3E10(GHIConnection *connection);
extern void func_021C3EC0(GHIConnection *connection);
extern void func_021C4150(GHIConnection *connection);
extern void func_021C4384(GHIConnection *connection);
extern void func_021C4684(GHIConnection *connection);
extern void func_021C4764(GHIConnection *connection);
extern void func_021C492C(GHIConnection *connection);
extern void func_021C4E7C(GHIConnection *connection);
extern void func_021C5430(GHIConnection *connection);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_021C0E58(GHIConnection *connection);
extern int func_0217EF50(int sock);
extern int func_021C0B4C(GHIConnection *connection);
extern void func_021C0244(struct Ctx *ctx);
extern int func_021C0C14(GHIConnection *connection);
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
extern void msleep(unsigned int msec);
void func_021C1D30(GHIConnection *connection);
int func_021C1DEC(GHIConnection *connection);
void func_021C1FF8(void);
void func_021C204C(void);
int func_021C20A4(const char *URL, const char *headers, char *buffer, int bufferSize, void *post, int throttle, int blocking, GHTTPProgressCallback progressCallback, GHTTPCompletedCallback completedCallback, void *param);
extern char g_021CED74[];
extern int g_021D3B64;
extern struct GHIThrottle g_021CE5AC;
extern int g_021CE5B0;
extern void *g_021D3B2C;


void func_021C1D30(GHIConnection *connection)
{
	switch (connection->statusCode / 100) {
	case 1:
	case 2:
	case 3:
		return;
	case 4:
		switch (connection->statusCode) {
		case 401:
			connection->result = 9;
			break;
		case 403:
			connection->result = 10;
			break;
		case 404:
		case 410:
			connection->result = 11;
			break;
		default:
			connection->result = 8;
			break;
		}
		break;
	case 5:
		connection->result = 12;
		break;
	}
}


/*
 * sdk:      ghiProcessConnection (ghttpmain.o, static)
 */
int func_021C1DEC(GHIConnection *connection)
{
    int completed;

    if (connection->processing)
        return 0;
    connection->processing = 1;

    if (connection->state == 0)
        func_021C3BAC((GHIConnection *)connection);
    if (connection->state == 1)
        func_021C3D10((GHIConnection *)connection);
    if (connection->state == 2)
        func_021C3E10((GHIConnection *)connection);
    if (connection->state == 3)
        func_021C3EC0((GHIConnection *)connection);
    if (connection->state == 4)
        func_021C4150((GHIConnection *)connection);
    if (connection->state == 5)
        func_021C4384((GHIConnection *)connection);
    if (connection->state == 6)
        func_021C4684((GHIConnection *)connection);
    if (connection->state == 7)
        func_021C4764((GHIConnection *)connection);
    if (connection->state == 8)
        func_021C492C((GHIConnection *)connection);
    if (connection->state == 9)
        func_021C4E7C((GHIConnection *)connection);
    if (connection->state == 10)
        func_021C5430((GHIConnection *)connection);
    if (connection->state == 11)
        func_0217D254(8, (char *)3, 0x10, g_021CED74);

    if (connection->redirectURL)
        func_021C0E58((GHIConnection *)connection);

    completed = connection->completed;
    if (connection->result == 0x12 && !completed) {
        if (!func_0217EF50(connection->socket))
            connection->completed = 1;
    }

    if (connection->completed) {
        if (connection->handleStatus == 1) {
            func_021C1D30((GHIConnection *)connection);
            if (!func_021C0B4C((GHIConnection *)connection)) {
                connection->processing = 0;
                connection->state = 11;
                return 0;
            }
            func_021C0244((struct Ctx *)connection);
            if (!func_021C0C14((GHIConnection *)connection)) {
                connection->processing = 0;
                return 0;
            }
        } else {
            if (!func_021C0B4C((GHIConnection *)connection)) {
                connection->processing = 0;
                connection->state = 11;
                return 0;
            }
            func_021C0244((struct Ctx *)connection);
            if (!func_021C0C14((GHIConnection *)connection)) {
                connection->processing = 0;
                return 0;
            }
        }
    } else {
        connection->processing = 0;
    }

    return completed;
}


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
        bResult = func_021BFC54((int)connection, (int *)&connection->getFileBuffer, buffer, bufferSize);
    else
        bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)&connection->getFileBuffer, 0x800, 0x800);
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
        while (!func_021C1DEC((GHIConnection *)connection))
            msleep(10);
        return 0;
    }

    return connection->request;
}
