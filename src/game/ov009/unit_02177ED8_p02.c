/*
 * file:     unit_02177ED8_p02.c
 * unit:     yes
 * function: func_021782B4, func_021783BC
 * address:  0x021782B4
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
 *   func_020948E0  0x020948E0  arm
 *   func_0217956C  0x0217956C  arm  ov009
 *   func_02058518  0x02058518  arm
 *   func_02178A94  0x02178A94  arm  ov009
 *   func_0217967C  0x0217967C  arm  ov009
 *   func_02085A30  0x02085A30  arm
 *   func_02179718  0x02179718  arm  ov009
 *   g_021A2358  0x021A2358  data  ov009
 *   g_021A2358_arg  0x021A2358  data  ov009
 *   g_021A2374  0x021A2374  data  ov009
 *   g_021AB184  0x021AB184  data  ov009
 *   g_021AB190  0x021AB190  data  ov009
 *   g_02150FEC  0x02150FEC  data
 *   func_0208574C  0x0208574C  arm
 *   func_02085710  0x02085710  arm
 *   func_02178C48  0x02178C48  arm  ov009
 *   func_02178678  0x02178678  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_02085A38  0x02085A38  arm
 *   func_02179CF4  0x02179CF4  arm  ov009
 */
#include "../../matched/include/G_DWCWFCUtil.h"
#include "../../matched/include/G_DWCHttpParam.h"

#define AUTH_RESULT (*(int *)(((char *)g_021AB184.auth) + 0x1004))
#define AUTH_HTTP (*(DWCHttp_021782B4 **)(((char *)g_021AB184.auth) + 0x1314))
struct tagDWCWiFiInfo;
typedef struct DWCHttp_021782B4 DWCHttp_021782B4;

typedef struct DWCHttpParam DWCHttpParam;

typedef struct DWCAuth_021782B4
{
    char pad0[0x1004];
    int result;
    char pad1008[0x1cc - 0x8];
    unsigned short ingamesn[26];
    char pad1200[0];
} DWCAuth_021782B4;

typedef struct DWCWFCUtil DWCWFCUtil;

typedef struct
{
    int f0;
    void *current;
} OSThreadInfo;

typedef struct OSThread OSThread;

typedef struct OSMutex { char pad[0x18]; } OSMutex;

typedef struct DWCHttp_021783BC {
    char pad0[0x1020];
    int state;
    char pad1024[0xb50];
    char thread[0x6c];
    int thread_started;
} DWCHttp_021783BC;

typedef struct DWCAuth_021783BC {
    char pad0[0x1004];
    int result;
    int error;
    char pad100c[0x308];
    DWCHttp_021783BC *http;
    char pad1318[0xc0];
    OSMutex mutex;
    int abort;
} DWCAuth_021783BC;

extern int func_020948E0(const char *, const char *);
extern int func_0217956C(struct DWCHttp_021782B4 *http, struct DWCHttpParam *param);
extern void func_02058518(struct tagDWCWiFiInfo *buf);
extern int func_02178A94(DWCHttp_021782B4 *http, char *gsbrcd, unsigned short *ingamesn);
extern int func_0217967C(char *http);
extern unsigned long func_02085A30(void *thread);
extern void func_02179718(char *http, unsigned long prio);
extern int func_0208574C(void *thread);
extern void func_02085710(void *thread);
extern void func_02178C48(int error);
extern int func_02178678(void);
extern unsigned long long func_020870D0(void);
extern void func_02086028(OSMutex *mutex);
extern void func_02086078(OSMutex *mutex);
extern void func_02085A38(unsigned long msec);
extern void func_02179CF4(char *http);
int func_021782B4(int getwifiinfofromflash);
void func_021783BC(void);
extern struct DWCHttpParam g_021A2358;
extern struct DWCHttpParam g_021A2358_arg;
extern char g_021A2374[];
extern struct DWCWFCUtil g_021AB184;
extern char g_021AB190[];
extern OSThreadInfo g_02150FEC;


/*
 * sdk:      DWCi_Auth_Start (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * The pool carried 0x021A2358 twice: once for the url/f14/fc/f10 accesses and
 * once for the DWC_Http_Create argument, so the source named the struct through
 * two externs (docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-*).
 * With one name 1.1p1 CSEs both uses into a callee-saved register and the
 * function comes out one instruction (8 bytes) short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_021782B4.c \
 *       --func func_021782B4 --addr 0x021782B4 --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */
int func_021782B4(int getwifiinfofromflash)
{
    if (func_020948E0(g_021A2358.url, g_021A2374) != 0)
        g_021A2358.f14 = 1;

    g_021A2358.fc = *(int *)(((char *)g_021AB184.auth) + 0x120c);
    g_021A2358.f10 = *(int *)(((char *)g_021AB184.auth) + 0x1210);
    if (func_0217956C(AUTH_HTTP, &g_021A2358_arg) != 0)
        return 4;

    if (getwifiinfofromflash == 1)
        func_02058518((struct tagDWCWiFiInfo *)g_021AB190);

    AUTH_RESULT = func_02178A94(AUTH_HTTP, ((char *)g_021AB184.auth) + 0x1200, (unsigned short *)(((char *)g_021AB184.auth) + 0x11cc));
    if (AUTH_RESULT != 0)
        return 4;

    if (func_0217967C((char *)AUTH_HTTP) != 0)
        return 4;

    func_02179718((char *)AUTH_HTTP, func_02085A30(g_02150FEC.current) - 1);
    return 0;
}


/*
 * sdk:      DWCi_Auth_Thread (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
void func_021783BC(void)
{
    int retrycount = 0;
    unsigned long long startwait;
    int result_httpparse;
    int getwifiinfofromflash;

    for (;;) {
        if (((DWCAuth_021783BC *)g_021AB184.auth)->http->thread_started != 0
            && !func_0208574C(((DWCAuth_021783BC *)g_021AB184.auth)->http->thread))
            func_02085710(((DWCAuth_021783BC *)g_021AB184.auth)->http->thread);

        if (((DWCAuth_021783BC *)g_021AB184.auth)->http->state != 8) {
            ((DWCAuth_021783BC *)g_021AB184.auth)->error = 20100;
            if (((DWCAuth_021783BC *)g_021AB184.auth)->http->state == 7) {
                func_02178C48(20);
                return;
            }
            if (retrycount > 2) {
                if (((DWCAuth_021783BC *)g_021AB184.auth)->http->state == 2)
                    func_02178C48(9);
                else if (((DWCAuth_021783BC *)g_021AB184.auth)->http->state == 3)
                    func_02178C48(11);
                else
                    func_02178C48(13);
                return;
            }
            retrycount++;
            getwifiinfofromflash = 1;
        } else {
            result_httpparse = func_02178678();
            switch (result_httpparse) {
            case 21:
                func_02178C48(21);
                return;
            case 16:
                if (retrycount > 2) {
                    func_02178C48(16);
                    return;
                }
                retrycount++;
                getwifiinfofromflash = 0;
                break;
            case 17:
                func_02178C48(result_httpparse);
                return;
            default:
                if (retrycount >= 2) {
                    func_02178C48(result_httpparse);
                    return;
                }
                retrycount++;
                getwifiinfofromflash = 1;
                break;
            }
        }

        startwait = func_020870D0();
        while (((func_020870D0() - startwait) << 6) / 33514 < 5000) {
            func_02086028(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
            if (((DWCAuth_021783BC *)g_021AB184.auth)->abort == 1) {
                ((DWCAuth_021783BC *)g_021AB184.auth)->error = 20100;
                func_02086078(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
                func_02178C48(20);
                return;
            }
            func_02086078(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
            func_02085A38(5000);
        }

        func_02179CF4((char *)((DWCAuth_021783BC *)g_021AB184.auth)->http);
        func_02086028(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
        ((DWCAuth_021783BC *)g_021AB184.auth)->result = func_021782B4(getwifiinfofromflash);
        if (((DWCAuth_021783BC *)g_021AB184.auth)->result != 0) {
            ((DWCAuth_021783BC *)g_021AB184.auth)->error = 20100;
            func_02086078(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
            return;
        }
        func_02086078(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
    }
}
