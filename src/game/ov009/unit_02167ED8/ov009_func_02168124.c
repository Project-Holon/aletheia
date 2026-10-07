/*
 * function: func_02168124
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
 *   func_021781DC  0x021781DC  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_02178224  0x02178224  arm  ov009
 *   func_02178144  0x02178144  arm  ov009
 *   func_02177EE8  0x02177EE8  arm  ov009
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_02059F54  0x02059F54  arm
 *   g_021AA830  0x021AA830  data
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

extern int func_021781DC(void);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
struct DWCAuthParam;
extern void func_02178224(int *result);
extern void func_02178144(void);
extern int func_02177EE8(struct DWCAuthParam *param, void *http);
extern void func_0205A1B0(int name, void *ptr, unsigned long size);
extern void func_02059F54(int error, int errorCode);
extern NalCnt *g_021AA830;

int func_02168124(void)
{
    AuthResult result;

    if (g_021AA830 == 0)
        return 0;
    switch (func_021781DC()) {
    case 0:
        return 2;
    case 0x15:
        func_02082BCC(&result, 0, sizeof(result));
        func_02178224((int *)(&result));
        func_02178144();
        if (result.returncode == 20002) {
            func_02177EE8((struct DWCAuthParam *)g_021AA830->authparam, g_021AA830->http);
            return 2;
        }
        func_0205A1B0(4, g_021AA830, 7772);
        g_021AA830 = 0;
        return 3;
    case 0x14:
        func_02178144();
        func_0205A1B0(4, g_021AA830, 7772);
        g_021AA830 = 0;
        return 5;
    default:
        func_02178224((int *)(&result));
        func_02178144();
        func_0205A1B0(4, g_021AA830, 7772);
        g_021AA830 = 0;
        func_02059F54(2, result.returncode);
        return 4;
    }
}
