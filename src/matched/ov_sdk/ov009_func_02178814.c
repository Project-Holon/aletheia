/*
 * function: func_02178814
 * address:  0x02178814
 * packet:   pkt_ov009_02178814
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_FillResult (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   func_0217A728  0x0217A728  arm  ov009
 *   func_02168250  0x02168250  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
 *   func_02095F40  0x02095F40  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0217A7C8  0x0217A7C8  arm  ov009
 *   g_021AB184     0x021AB184  data ov009
 *   g_02153FAC     0x02153FAC  data
 *   g_021A2394     0x021A2394  data ov009
 *   g_021A239C     0x021A239C  data ov009
 *   g_021A23A8     0x021A23A8  data ov009
 *   g_021A23B4     0x021A23B4  data ov009
 *   g_021A23BC     0x021A23BC  data ov009
 *   g_021A23C4     0x021A23C4  data ov009
 *   g_021A23D0     0x021A23D0  data ov009
 *   g_021A23DC     0x021A23DC  data ov009
 */

typedef struct DWCHttp DWCHttp;

typedef struct DWCAuth {
    char pad0[0x1008];
    int error;
    char retcode[4];
    char f1010[0xf];
    char f101f[0x33];
    char f1052[0x12d];
    char f117f[9];
    char f1188[0x2b];
    char f11b3;
    char pad11b4[0x160];
    DWCHttp *http;
} DWCAuth;

typedef struct DWCWFCUtil {
    int f0;
    DWCAuth *auth;
    int state;
} DWCWFCUtil;

extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
extern int func_020964E0(const char *s);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
extern long func_02095F40(const char *s, char **endptr, int base);
extern unsigned long func_0209477C(const char *s);
extern int func_0217A7C8(DWCHttp *http, char *label, char *buffer, int buffer_len);

extern DWCWFCUtil g_021AB184;
extern int g_02153FAC;
extern char g_021A2394[];
extern char g_021A239C[];
extern char g_021A23A8[];
extern char g_021A23B4[];
extern char g_021A23BC[];
extern char g_021A23C4[];
extern char g_021A23D0[];
extern char g_021A23DC[];

int func_02178814(void)
{
    char *endptr;
    int returncode;

    endptr = 0;
    endptr = func_0217A728(g_021AB184.auth->http, g_021A2394);
    if (endptr != 0)
        func_02168250(endptr);

    endptr = 0;
    g_02153FAC = 0;
    returncode = func_020964E0(func_0217A728(g_021AB184.auth->http, g_021A239C));
    if (g_02153FAC == 0x22) {
        g_021AB184.auth->error = 20101;
        return 12;
    }
    if (returncode != 200) {
        g_021AB184.auth->error = returncode + 23000;
        return 18;
    }
    if (func_0217A77C(g_021AB184.auth->http, g_021A23A8, g_021AB184.auth->retcode, 4) <= 0) {
        g_021AB184.auth->error = 20101;
        return 14;
    }
    returncode = func_02095F40(g_021AB184.auth->retcode, &endptr, 10);
    if (endptr != g_021AB184.auth->retcode + func_0209477C(g_021AB184.auth->retcode)) {
        g_021AB184.auth->error = 20101;
        return 12;
    }
    g_021AB184.auth->error = returncode + 20000;
    if (returncode < 100) {
        g_021AB184.auth->f1052[0] = 0;
        g_021AB184.auth->f101f[0] = 0;
        g_021AB184.auth->f117f[0] = 0;
        g_021AB184.auth->f1010[0] = 0;
        g_021AB184.auth->f1188[0] = 0;
        func_0217A77C(g_021AB184.auth->http, g_021A23B4, g_021AB184.auth->f1052, 0x12d);
        func_0217A77C(g_021AB184.auth->http, g_021A23BC, g_021AB184.auth->f101f, 0x33);
        func_0217A77C(g_021AB184.auth->http, g_021A23C4, g_021AB184.auth->f117f, 9);
        func_0217A77C(g_021AB184.auth->http, g_021A23D0, g_021AB184.auth->f1010, 0xf);
        func_0217A7C8(g_021AB184.auth->http, g_021A23DC, g_021AB184.auth->f1188, 0x41);
        g_021AB184.auth->f11b3 = 0;
        if (returncode != 40)
            g_021AB184.state = 1;
        else
            g_021AB184.state = 2;
    }
    return 0;
}
