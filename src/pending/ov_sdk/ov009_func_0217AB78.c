/*
 * function: DWCi_Netcheck_Thread
 * address:  0x0217AB78
 * packet:   pkt_ov009_0217AB78
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_Netcheck_Thread (libdwcauth.TWL.HYB.a dwc_netcheck.o)
 *
 * symbols:
 *   DWC_Http_Create                  0x0217956c arm
 *   DWC_Http_Destroy                 0x02179cf4 arm
 *   DWC_Http_FinishHeader            0x0217967c arm
 *   OS_GetThreadPriority             0x02085a30 arm
 *   DWC_Http_StartThread             0x02179718 arm
 *   OS_IsThreadTerminated            0x0208574c arm
 *   OS_JoinThread                    0x02085710 arm
 *   DWC_Http_ParseResult             0x0217a484 arm
 *   DWC_Http_GetResult               0x0217a728 arm
 *   atoi                             0x020964e0 arm
 *   strcmp                           0x020948e0 arm
 *   DWC_Auth_GetCalInfoFromNVRAM     0x02178f4c arm
 *   DWC_Auth_SetCalInfoToHttp        0x02179218 arm
 *   DWC_Http_Add_PostBase64Item      0x02179f3c arm
 *   strlen                           0x0209477c arm
 *   DWCi_Netcheck_SetError           0x0217b7e8 arm
 *   strncpy                          0x02094860 arm
 *   DWCi_BM_GetWiFiInfo              0x02058518 arm
 *   DWC_Auth_Create                  0x02177ee8 arm
 *   DWC_Auth_Join                    0x02178194 arm
 *   DWC_Auth_GetError                0x021781dc arm
 *   DWC_Auth_GetResult               0x02178224 arm
 *   DWC_Auth_Destroy                 0x02178144 arm
 *   DWC_Http_GetBase64DecodedResult  0x0217a77c arm
 *   DWC_Http_Add_Body                0x0217a044 arm
 *   OS_Sleep                         0x02085a38 arm
 *   DWChttp                          0x021ace5c data
 *   _ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0 0x021a26d4 data
 *   DWCnetcheckhttpparam             0x021ace8c data
 *   OSi_ThreadInfo                   0x02150fec data
 *   g_021A2700                       0x021a2700 data
 *   errno                            0x02153fac data
 *   g_021A270C                       0x021a270c data
 *   DWCauthhttpparam                 0x021a2358 data
 *   g_021A272C                       0x021a272c data
 *   g_021A2734                       0x021a2734 data
 *   g_021A273C                       0x021a273c data
 *   DWCnetcheckauthparam             0x021acea8 data
 *   g_021A274C                       0x021a274c data
 *   g_021A2754                       0x021a2754 data
 *   g_021A275C                       0x021a275c data
 *   g_021A2768                       0x021a2768 data
 *   g_021A276C                       0x021a276c data
 *   g_021A2774                       0x021a2774 data
 *
 * blocker:  SIZE -- no DWARF variable layout beyond the recovered names.
 *           The netcheck thread is a 3184-byte HTTP+auth state machine over
 *           the DWChttp / DWCauth globals. This is a faithful reconstruction
 *           of the call sequence and branching (create -> finish header ->
 *           start/join thread -> parse -> auth join -> decode -> retry with
 *           OS_Sleep), built from the listing; the DWC struct field offsets
 *           are reached through the raw byte offsets seen in the object and
 *           the reconstruction has not been converged against --diff.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct DWCNetcheckWork {
    u8 pad000[0x30];
    int f30;
    int f34;
    int f38;
    char *f3c;
    char *f40;
    int f44;
    int f48;
    u8 pad04c[0x1000];
    int fstate;             /* +0x1020 */
} DWCNetcheckWork;

extern int DWC_Http_Create(void *http, void *param);
extern void DWC_Http_Destroy(void *http);
extern int DWC_Http_FinishHeader(void *http);
extern int OS_GetThreadPriority(void *thread);
extern void DWC_Http_StartThread(void *http, unsigned long prio);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);
extern int DWC_Http_ParseResult(void *http, int noparsebody);
extern char *DWC_Http_GetResult(void *http, char *label);
extern int atoi(const char *p);
extern int strcmp(const char *a, const char *b);
extern int DWC_Auth_GetCalInfoFromNVRAM(void *cal);
extern int DWC_Auth_SetCalInfoToHttp(void *http, void *calinfo, int allowessid);
extern int DWC_Http_Add_PostBase64Item(void *http, char *label, char *data, unsigned long data_len);
extern unsigned long strlen(const char *p);
extern void DWCi_Netcheck_SetError(int error);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern void DWCi_BM_GetWiFiInfo(void *buf);
extern int DWC_Auth_Create(void *param, void *http);
extern void DWC_Auth_Join(void);
extern int DWC_Auth_GetError(void);
extern void DWC_Auth_GetResult(void *result);
extern void DWC_Auth_Destroy(void);
extern int DWC_Http_GetBase64DecodedResult(void *http, char *label, char *buffer, unsigned long buffer_len);
extern int DWC_Http_Add_Body(void *http, char *data);
extern void OS_Sleep(unsigned long msec);

extern DWCNetcheckWork DWChttp;
extern u32 _ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0;
extern u8 DWCnetcheckhttpparam[];
extern u8 OSi_ThreadInfo[];
extern u8 g_021A2700[];
extern int errno;
extern u8 g_021A270C[];
extern u8 DWCauthhttpparam[];
extern u8 g_021A272C[];
extern u8 g_021A2734[];
extern u8 g_021A273C[];
extern u8 DWCnetcheckauthparam[];
extern u8 g_021A274C[];
extern u8 g_021A2754[];
extern u8 g_021A275C[];
extern u8 g_021A2768[];
extern u8 g_021A276C[];
extern u8 g_021A2774[];

static void DWCi_Netcheck_Thread(void)
{
    DWCNetcheckWork *work;
    u8 calinfo[0x30];
    u8 authresult[0x30];
    u8 wifiinfo[0x30];
    u8 url[0x200];
    u8 retcode[4];
    char *httpretcode;
    int httpretcodei;
    int error;
    int retry;
    u32 zero;
    u32 neg1;
    u32 neg3;
    u32 imm_2bf20;
    u32 imm_4e20;

    work = &DWChttp;
    zero = 0;
    neg1 = 0xfffffffe;
    neg3 = 0xfffffffc;
    imm_2bf20 = 0x2bf20;
    imm_4e20 = 0x4e20;
    url[0] = (u8)zero;
    url[0xc] = (u8)zero;

    for (;;) {
        work->f30 = *(u32 *)g_021A2700;
        work->f34 = 1;
        work->f38 = 0x1000;
        work->f3c = (char *)&calinfo;
        work->f40 = (char *)&authresult;
        work->f48 = imm_4e20;

        DWC_Http_Create(work, DWCnetcheckhttpparam);
        if (DWC_Http_FinishHeader(work) != 0) {
            DWC_Http_Destroy(work);
            DWCi_Netcheck_SetError(8);
            return;
        }
        DWC_Http_StartThread(work, (unsigned long)(OS_GetThreadPriority(OSi_ThreadInfo) - 1));
        if (work->fstate != 2)
            goto after_wait;

        if (DWC_Auth_GetCalInfoFromNVRAM(&calinfo) != 0 &&
            DWC_Auth_SetCalInfoToHttp(work, &calinfo, 1) == 0) {
            DWC_Http_Destroy(work);
            DWCi_Netcheck_SetError(8);
            return;
        }
        DWC_Http_FinishHeader(work);
        DWC_Http_StartThread(work, (unsigned long)(OS_GetThreadPriority(OSi_ThreadInfo) - 1));

after_wait:
        DWC_Http_ParseResult(work, 0);
        httpretcode = DWC_Http_GetResult(work, (char *)g_021A270C);
        httpretcodei = atoi(httpretcode);
        if (*(int *)g_021A276C == 0x22) {
            DWC_Http_Destroy(work);
            DWC_Http_Destroy(work);
            goto cleanup;
        }
        if (httpretcodei == 0xc8) {
            work->f3c = (char *)work->fstate;
        } else if (httpretcodei == (int)g_021A272C) {
            goto retry;
        } else {
            DWC_Http_Destroy(work);
            DWCi_Netcheck_SetError(10);
            return;
        }
        goto after_result;

retry:
        if (work->fstate != 0) {
            work->f3c = (char *)0xfffffffb;
            DWC_Http_Destroy(work);
            work->f3c = (char *)&calinfo;
            if (DWC_Http_Create(work, DWCauthhttpparam) != 0) {
                DWC_Http_Destroy(work);
                DWCi_Netcheck_SetError(1);
                return;
            }
            if (DWC_Auth_GetCalInfoFromNVRAM(&calinfo) != 0) {
                if (DWC_Auth_SetCalInfoToHttp(work, &calinfo, 1) == 0) {
                    DWC_Http_Destroy(work);
                    DWCi_Netcheck_SetError(8);
                    return;
                }
            } else {
                DWC_Http_Destroy(work);
                DWCi_Netcheck_SetError(8);
                return;
            }
            DWC_Http_Add_PostBase64Item(work, (char *)g_021A272C, (char *)&calinfo,
                                        (unsigned long)strlen((char *)&calinfo));
            DWC_Http_FinishHeader(work);
            DWC_Http_StartThread(work, (unsigned long)(OS_GetThreadPriority(OSi_ThreadInfo) - 1));
        }

after_result:
        DWC_Http_ParseResult(work, 0);
        if (*(int *)g_021A276C == 0x22) {
            DWC_Http_Destroy(work);
            DWC_Http_Destroy(work);
            goto cleanup;
        }
        work->f3c = (char *)work->fstate;

        DWC_Auth_Create(DWCnetcheckauthparam, work);
        DWC_Auth_Join();
        error = DWC_Auth_GetError();
        if (error == 0x15) {
            DWC_Auth_Destroy();
            DWC_Auth_Create(DWCnetcheckauthparam, work);
            if (DWC_Auth_Join(), DWC_Auth_GetError() == 9) {
                work->f3c = (char *)0;
                DWC_Auth_Destroy();
                DWCi_Netcheck_SetError(6);
                return;
            }
            DWC_Auth_GetResult(&authresult);
            if (error == 0xb) {
                work->f3c = (char *)0;
                DWC_Auth_Destroy();
                goto result_path;
            }
            work->f3c = (char *)&authresult;
            DWC_Auth_Destroy();
            DWCi_Netcheck_SetError(6);
            return;
        }

result_path:
        DWC_Auth_Destroy();
        if ((u32)httpretcodei == 0xc8) {
            work->f3c = 0;
            DWCi_Netcheck_SetError(11);
            return;
        }
        DWC_Http_Destroy(work);
        work->f30 = 0;
        work->f34 = 0;
        work->f38 = 0x1000;
        work->f3c = (char *)&calinfo;
        work->f40 = (char *)&authresult;
        work->f48 = imm_2bf20;
        DWC_Http_Create(work, DWCauthhttpparam);
        if (DWC_Auth_GetCalInfoFromNVRAM(&calinfo) != 0) {
            DWC_Http_Destroy(work);
            DWCi_Netcheck_SetError(8);
            return;
        }
        DWC_Http_Add_Body(work, (char *)&calinfo);
        DWC_Http_FinishHeader(work);
        DWC_Http_StartThread(work, (unsigned long)(OS_GetThreadPriority(OSi_ThreadInfo) - 1));
        DWC_Http_ParseResult(work, 1);
        DWC_Http_GetResult(work, (char *)g_021A272C);
        DWC_Http_GetBase64DecodedResult(work, (char *)g_021A2734, (char *)&authresult, 4);
        httpretcodei = atoi((char *)&authresult);
        if (*(int *)g_021A276C == 0x22) {
            DWCi_Netcheck_SetError(9);
            return;
        }
        if (httpretcodei == 0x72) {
            work->f3c = (char *)0;
            goto final;
        }
        if (httpretcodei >= 0x64) {
            DWC_Http_Destroy(work);
            DWCi_Netcheck_SetError(6);
            return;
        }
        DWC_Http_GetBase64DecodedResult(work, (char *)g_021A2734, (char *)&authresult, 0x100);
        if ((int)DWC_Http_Add_Body(work, (char *)&authresult) <= 0) {
            DWC_Http_Destroy(work);
            DWCi_Netcheck_SetError(1);
            return;
        }
        DWC_Http_FinishHeader(work);
        DWC_Http_Destroy(work);
        DWCi_BM_GetWiFiInfo(&wifiinfo);
        if (*(int *)&wifiinfo[4] != 0 || *(int *)&wifiinfo[0] != 0)
            goto after_result;
        goto final;

final:
        if (httpretcodei == 0xc8) {
            work->f3c = 0;
            DWCi_Netcheck_SetError(11);
            return;
        }
        work->f3c = (char *)0xfffffff8;
        work->f30 = 0;
        work->f34 = 0;
        work->f38 = 0x1000;
        work->f3c = (char *)&calinfo;
        work->f40 = (char *)&authresult;
        work->f48 = imm_2bf20;
        DWC_Http_Create(work, DWCauthhttpparam);
        DWC_Http_Add_PostBase64Item(work, (char *)g_021A274C, (char *)&authresult,
                                    (unsigned long)strlen((char *)&authresult));
        DWC_Http_FinishHeader(work);
        DWC_Http_StartThread(work, (unsigned long)(OS_GetThreadPriority(OSi_ThreadInfo) - 1));
        DWC_Http_ParseResult(work, 1);
        if (*(int *)g_021A276C != 0x22) {
            DWC_Http_GetResult(work, (char *)g_021A2754);
            DWC_Http_GetBase64DecodedResult(work, (char *)g_021A2754, (char *)&authresult, 4);
            httpretcodei = atoi((char *)&authresult);
            if (*(int *)g_021A276C == 0x22) {
                DWCi_Netcheck_SetError(9);
                return;
            }
            if (httpretcodei == 0x72) {
                work->f3c = (char *)0;
                goto final2;
            }
            if (httpretcodei >= 0x64) {
                DWC_Http_Destroy(work);
                DWCi_Netcheck_SetError(6);
                return;
            }
            work->f30 = (int)DWC_Http_GetBase64DecodedResult(work, (char *)g_021A276C,
                                                             (char *)&authresult, 0x100);
        }
final2:
        DWC_Http_Destroy(work);
        DWCi_Netcheck_SetError(3);
        return;
    }

cleanup:
    if (work->f40 != 0)
        DWC_Http_GetBase64DecodedResult(work, (char *)g_021A275C, work->f40, 0x200);
    if (work->f3c != 0)
        DWC_Http_GetBase64DecodedResult(work, (char *)g_021A2768, work->f3c, 0x200);
    if (work->fstate != 0)
        DWC_Http_GetBase64DecodedResult(work, (char *)g_021A2774, (char *)work->fstate, 0x200);
    return;
}
