/*
 * function: func_021783BC
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
 *   func_021782B4  0x021782B4  arm  ov009
 *   g_021AB184     0x021AB184  data ov009
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

extern int func_0208574C(void *thread);
extern void func_02085710(void *thread);
extern void func_02178C48(int error);
extern int func_02178678(void);
extern unsigned long long func_020870D0(void);
extern void func_02086028(OSMutex *mutex);
extern void func_02086078(OSMutex *mutex);
extern void func_02085A38(unsigned long msec);
extern void func_02179CF4(char *http);
extern int func_021782B4(int getwifiinfofromflash);

extern struct DWCWFCUtil g_021AB184;

void func_021783BC(void)
{
    int retrycount = 0;
    unsigned long long startwait;
    int result_httpparse;
    int getwifiinfofromflash;

    for (;;) {
        if (((DWCAuth *)g_021AB184.auth)->http->thread_started != 0
            && !func_0208574C(((DWCAuth *)g_021AB184.auth)->http->thread))
            func_02085710(((DWCAuth *)g_021AB184.auth)->http->thread);

        if (((DWCAuth *)g_021AB184.auth)->http->state != 8) {
            ((DWCAuth *)g_021AB184.auth)->error = 20100;
            if (((DWCAuth *)g_021AB184.auth)->http->state == 7) {
                func_02178C48(20);
                return;
            }
            if (retrycount > 2) {
                if (((DWCAuth *)g_021AB184.auth)->http->state == 2)
                    func_02178C48(9);
                else if (((DWCAuth *)g_021AB184.auth)->http->state == 3)
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
            func_02086028(&((DWCAuth *)g_021AB184.auth)->mutex);
            if (((DWCAuth *)g_021AB184.auth)->abort == 1) {
                ((DWCAuth *)g_021AB184.auth)->error = 20100;
                func_02086078(&((DWCAuth *)g_021AB184.auth)->mutex);
                func_02178C48(20);
                return;
            }
            func_02086078(&((DWCAuth *)g_021AB184.auth)->mutex);
            func_02085A38(5000);
        }

        func_02179CF4((char *)((DWCAuth *)g_021AB184.auth)->http);
        func_02086028(&((DWCAuth *)g_021AB184.auth)->mutex);
        ((DWCAuth *)g_021AB184.auth)->result = func_021782B4(getwifiinfofromflash);
        if (((DWCAuth *)g_021AB184.auth)->result != 0) {
            ((DWCAuth *)g_021AB184.auth)->error = 20100;
            func_02086078(&((DWCAuth *)g_021AB184.auth)->mutex);
            return;
        }
        func_02086078(&((DWCAuth *)g_021AB184.auth)->mutex);
    }
}
