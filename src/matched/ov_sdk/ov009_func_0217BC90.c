/*
 * function: DWC_CheckProfanityProcess
 * address:  0x0217BC90
 * packet:   pkt_ov009_0217BC90
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CheckProfanityProcess (libdwcauth.TWL.HYB.a dwc_prof.o)
 *
 * symbols:
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   DWC_AC_GetApType  0x0205BDD0  arm
 *   DWCi_Prof_ParseResponse  0x0217BDA8  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   DWC_Http_Destroy  0x02179CF4  arm  ov009
 *   func_0205A1B0  0x0205A1B0  arm
 *   g_021ACEF0     0x021ACEF0  data ov009
 */

typedef struct OSThread {
    char pad0[0x6c];
    int id;
    char pad70[0x50];
} OSThread;

typedef struct DWCHttp {
    char pad0[0x1020];
    int error;
    char pad1024[0xb50];
    OSThread thread;
    char mutex[0x18];
    int abort;
} DWCHttp;

typedef struct DWCProfWorkarea {
    DWCHttp http;
    int http_initialized;
    char url[257];
    char *result;
    int *badwordsnum;
    int wordsnum;
} DWCProfWorkarea;

extern int OS_IsThreadTerminated(OSThread *thread);
extern unsigned char DWC_AC_GetApType(void);
extern int DWCi_Prof_ParseResponse(void);
extern void func_02059F54(int error, int errorCode);
extern void DWC_Http_Destroy(char *http);
extern void func_0205A1B0(int name, void *ptr, long size);

extern DWCProfWorkarea *g_021ACEF0;

int DWC_CheckProfanityProcess(void)
{
    int retval;
    unsigned char aptype;

    if (g_021ACEF0 == 0 || g_021ACEF0->http.thread.id == 0)
        return 0;
    if (OS_IsThreadTerminated(&g_021ACEF0->http.thread) == 1) {
        aptype = DWC_AC_GetApType();
        if (aptype == 0xff || aptype > 99)
            aptype = 99;

        switch (g_021ACEF0->http.error) {
        case 8:
            if (DWCi_Prof_ParseResponse() == 0)
                retval = 3;
            else
                retval = 2;
            break;
        case 2:
            func_02059F54(8, -52100 - aptype);
            retval = 3;
            break;
        case 3:
        case 4:
        case 6:
            func_02059F54(18, -33010);
            retval = 3;
            break;
        default:
            func_02059F54(18, -33030);
            retval = 3;
            break;
        }
    } else {
        return 1;
    }

    DWC_Http_Destroy((char *)(&g_021ACEF0->http));
    func_0205A1B0(0, g_021ACEF0, 0);
    g_021ACEF0 = 0;
    return retval;
}
