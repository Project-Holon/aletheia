/*
 * function: func_0217C448
 * address:  0x0217C448
 * packet:   pkt_ov009_0217C448
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Svl_ParseHttp (libdwcauth.TWL.HYB.a dwc_svl.o)
 *
 * symbols:
 *   func_0217A484  0x0217A484  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   func_0217A728  0x0217A728  arm  ov009
 *   func_02168250  0x02168250  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
 *   g_021ACEF4     0x021ACEF4  data ov009
 *   g_021A2874     0x021A2874  data ov009
 *   g_021A287C     0x021A287C  data ov009
 *   g_02153FAC     0x02153FAC  data
 *   g_021A2888     0x021A2888  data ov009
 *   g_021A2894     0x021A2894  data ov009
 *   g_021A289C     0x021A289C  data ov009
 *   g_021A28AC     0x021A28AC  data ov009
 */

typedef struct DWCHttp {
    char pad0[0x1c50];
} DWCHttp;

typedef struct DWCSvlResult {
    int status;
    char svlhost[65];
    char svltoken[301];
} DWCSvlResult;

typedef struct DWCSvlIntWorkarea {
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    DWCHttp http;
    DWCSvlResult *result;
} DWCSvlIntWorkarea;

extern int func_0217A484(DWCHttp *http, int noparsebody);
extern void func_02059F54(int error, int errorCode);
extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);

extern DWCSvlIntWorkarea *g_021ACEF4;
extern char g_021A2874[];
extern char g_021A287C[];
extern int g_02153FAC;
extern char g_021A2888[];
extern char g_021A2894[];
extern char g_021A289C[];
extern char g_021A28AC[];

int func_0217C448(void)
{
    char *strp;
    int httpretcode;
    char retcode[4];
    DWCHttp *DWChttp = &g_021ACEF4->http;

    if (!func_0217A484(DWChttp, 0)) {
        func_02059F54(15, -25101);
        return 0;
    }

    strp = func_0217A728(DWChttp, g_021A2874);
    if (strp != 0)
        func_02168250(strp);

    strp = func_0217A728(DWChttp, g_021A287C);
    if (strp == 0) {
        func_02059F54(15, -25101);
        return 0;
    }
    httpretcode = func_020964E0((u32)strp);
    if (g_02153FAC == 34) {
        func_02059F54(15, -25101);
        return 0;
    }
    if (httpretcode != 200) {
        func_02059F54(15, -25000 - httpretcode);
        return 0;
    }

    if (func_0217A77C(DWChttp, g_021A2888, retcode, 4) <= 0) {
        func_02059F54(15, -25101);
        return 0;
    }
    httpretcode = func_020964E0((u32)retcode);
    if (g_02153FAC == 34) {
        func_02059F54(15, -25101);
        return 0;
    }
    if (httpretcode >= 100) {
        func_02059F54(15, -24000 - httpretcode);
        return 0;
    }

    if (func_0217A77C(DWChttp, g_021A2894, g_021ACEF4->result->svlhost, 64) < 0
        || func_0217A77C(DWChttp, g_021A289C, g_021ACEF4->result->svltoken, 300) < 0
        || func_0217A77C(DWChttp, g_021A28AC, retcode, 1) < 0) {
        func_02059F54(15, -25101);
        return 0;
    }

    g_021ACEF4->result->status = (retcode[0] == 'Y') ? 1 : 0;
    return 1;
}
