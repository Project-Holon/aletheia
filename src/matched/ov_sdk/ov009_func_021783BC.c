/*
 * function: DWCi_Auth_Thread
 * address:  0x021783BC
 * packet:   pkt_ov009_021783BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_Thread (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_JoinThread  0x02085710  arm
 *   DWCi_Auth_SetError  0x02178C48  arm  ov009
 *   DWCi_Auth_ParseHttp  0x02178678  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   OS_Sleep  0x02085A38  arm
 *   DWC_Http_Destroy  0x02179CF4  arm  ov009
 *   DWCi_Auth_Start  0x021782B4  arm  ov009
 *   gDwcAuthGlobal     0x021AB184  data ov009
 */

#include "../include/G_DWCWFCUtil.h"

typedef struct OSThread OSThread;
typedef struct OSMutex { char pad[0x18]; } OSMutex;

typedef struct DWCHttp {
    char pad0[0x1020];
    int state;
    char pad1024[0xb50];
    char thread[0x6c];
    int thread_started;
} DWCHttp;

typedef struct DWCAuth {
    char pad0[0x1004];
    int result;
    int error;
    char pad100c[0x308];
    DWCHttp *http;
    char pad1318[0xc0];
    OSMutex mutex;
    int abort;
} DWCAuth;

typedef struct DWCWFCUtil DWCWFCUtil;

extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);
extern void DWCi_Auth_SetError(int error);
extern int DWCi_Auth_ParseHttp(void);
extern unsigned long long func_020870D0(void);
extern void OS_LockMutex(OSMutex *mutex);
extern void func_02086078(OSMutex *mutex);
extern void OS_Sleep(unsigned long msec);
extern void DWC_Http_Destroy(char *http);
extern int DWCi_Auth_Start(int getwifiinfofromflash);

extern struct DWCWFCUtil gDwcAuthGlobal;

void DWCi_Auth_Thread(void)
{
    int retrycount = 0;
    unsigned long long startwait;
    int result_httpparse;
    int getwifiinfofromflash;

    for (;;) {
        if (((DWCAuth *)gDwcAuthGlobal.auth)->http->thread_started != 0
            && !OS_IsThreadTerminated(((DWCAuth *)gDwcAuthGlobal.auth)->http->thread))
            OS_JoinThread(((DWCAuth *)gDwcAuthGlobal.auth)->http->thread);

        if (((DWCAuth *)gDwcAuthGlobal.auth)->http->state != 8) {
            ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20100;
            if (((DWCAuth *)gDwcAuthGlobal.auth)->http->state == 7) {
                DWCi_Auth_SetError(20);
                return;
            }
            if (retrycount > 2) {
                if (((DWCAuth *)gDwcAuthGlobal.auth)->http->state == 2)
                    DWCi_Auth_SetError(9);
                else if (((DWCAuth *)gDwcAuthGlobal.auth)->http->state == 3)
                    DWCi_Auth_SetError(11);
                else
                    DWCi_Auth_SetError(13);
                return;
            }
            retrycount++;
            getwifiinfofromflash = 1;
        } else {
            result_httpparse = DWCi_Auth_ParseHttp();
            switch (result_httpparse) {
            case 21:
                DWCi_Auth_SetError(21);
                return;
            case 16:
                if (retrycount > 2) {
                    DWCi_Auth_SetError(16);
                    return;
                }
                retrycount++;
                getwifiinfofromflash = 0;
                break;
            case 17:
                DWCi_Auth_SetError(result_httpparse);
                return;
            default:
                if (retrycount >= 2) {
                    DWCi_Auth_SetError(result_httpparse);
                    return;
                }
                retrycount++;
                getwifiinfofromflash = 1;
                break;
            }
        }

        startwait = func_020870D0();
        while (((func_020870D0() - startwait) << 6) / 33514 < 5000) {
            OS_LockMutex(&((DWCAuth *)gDwcAuthGlobal.auth)->mutex);
            if (((DWCAuth *)gDwcAuthGlobal.auth)->abort == 1) {
                ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20100;
                func_02086078(&((DWCAuth *)gDwcAuthGlobal.auth)->mutex);
                DWCi_Auth_SetError(20);
                return;
            }
            func_02086078(&((DWCAuth *)gDwcAuthGlobal.auth)->mutex);
            OS_Sleep(5000);
        }

        DWC_Http_Destroy((char *)((DWCAuth *)gDwcAuthGlobal.auth)->http);
        OS_LockMutex(&((DWCAuth *)gDwcAuthGlobal.auth)->mutex);
        ((DWCAuth *)gDwcAuthGlobal.auth)->result = DWCi_Auth_Start(getwifiinfofromflash);
        if (((DWCAuth *)gDwcAuthGlobal.auth)->result != 0) {
            ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20100;
            func_02086078(&((DWCAuth *)gDwcAuthGlobal.auth)->mutex);
            return;
        }
        func_02086078(&((DWCAuth *)gDwcAuthGlobal.auth)->mutex);
    }
}
