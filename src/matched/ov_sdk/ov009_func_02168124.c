/*
 * function: DWC_NASLoginProcess
 * address:  0x02168124
 * packet:   pkt_ov009_02168124
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NASLoginProcess (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 *
 * symbols:
 *   DWC_Auth_GetError  0x021781DC  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWC_Auth_GetResult  0x02178224  arm  ov009
 *   DWC_Auth_Destroy  0x02178144  arm  ov009
 *   DWC_Auth_Create  0x02177EE8  arm  ov009
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_02059F54  0x02059F54  arm
 *   gDwcNasCnt  0x021AA830  data
 */

typedef struct {
    int returncode;
    char retcode[4];
    char datetime[15];
    char locator[51];
    char token[301];
    char challenge[9];
    char cookie[65];
} AuthResult;

typedef struct {
    unsigned char http[0x1c50];
    unsigned char authparam[0x48];
    AuthResult result;
} NalCnt;

extern int DWC_Auth_GetError(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
struct DWCAuthParam;
extern void DWC_Auth_GetResult(int *result);
extern void DWC_Auth_Destroy(void);
extern int DWC_Auth_Create(struct DWCAuthParam *param, void *http);
extern void func_0205A1B0(int name, void *ptr, unsigned long size);
extern void func_02059F54(int error, int errorCode);
extern NalCnt *gDwcNasCnt;

int DWC_NASLoginProcess(void)
{
    AuthResult result;

    if (gDwcNasCnt == 0)
        return 0;
    switch (DWC_Auth_GetError()) {
    case 0:
        return 2;
    case 0x15:
        MI_CpuFill8(&result, 0, sizeof(result));
        DWC_Auth_GetResult((int *)(&result));
        DWC_Auth_Destroy();
        if (result.returncode == 20002) {
            DWC_Auth_Create((struct DWCAuthParam *)gDwcNasCnt->authparam, gDwcNasCnt->http);
            return 2;
        }
        func_0205A1B0(4, gDwcNasCnt, 7772);
        gDwcNasCnt = 0;
        return 3;
    case 0x14:
        DWC_Auth_Destroy();
        func_0205A1B0(4, gDwcNasCnt, 7772);
        gDwcNasCnt = 0;
        return 5;
    default:
        DWC_Auth_GetResult((int *)(&result));
        DWC_Auth_Destroy();
        func_0205A1B0(4, gDwcNasCnt, 7772);
        gDwcNasCnt = 0;
        func_02059F54(2, result.returncode);
        return 4;
    }
}
