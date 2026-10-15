/*
 * function: DWCi_Auth_FillResult
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
 *   atoi  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
 *   strtol  0x02095F40  arm
 *   strlen  0x0209477C  arm
 *   func_0217A7C8  0x0217A7C8  arm  ov009
 *   gDwcAuthGlobal     0x021AB184  data ov009
 *   errno     0x02153FAC  data
 *   gDwcAuthLabelDate     0x021A2394  data ov009
 *   gDwcAuthLabelHttpResult     0x021A239C  data ov009
 *   gDwcAuthLabelReturnCd     0x021A23A8  data ov009
 *   gDwcAuthLabelToken     0x021A23B4  data ov009
 *   gDwcAuthLabelLocator     0x021A23BC  data ov009
 *   gDwcAuthLabelChallenge     0x021A23C4  data ov009
 *   gDwcAuthLabelDateTime     0x021A23D0  data ov009
 *   gDwcAuthLabelSetCookie     0x021A23DC  data ov009
 */

#include "../include/G_DWCWFCUtil.h"

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

typedef struct DWCWFCUtil DWCWFCUtil;

extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
typedef signed int     s32;
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
extern s32 strtol(u32 a0, u32 *a1, u32 a2);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int func_0217A7C8(DWCHttp *http, char *label, char *buffer, int buffer_len);

extern struct DWCWFCUtil gDwcAuthGlobal;
extern int errno;
extern char gDwcAuthLabelDate[];
extern char gDwcAuthLabelHttpResult[];
extern char gDwcAuthLabelReturnCd[];
extern char gDwcAuthLabelToken[];
extern char gDwcAuthLabelLocator[];
extern char gDwcAuthLabelChallenge[];
extern char gDwcAuthLabelDateTime[];
extern char gDwcAuthLabelSetCookie[];

int DWCi_Auth_FillResult(void)
{
    char *endptr;
    int returncode;

    endptr = 0;
    endptr = func_0217A728(((DWCAuth *)gDwcAuthGlobal.auth)->http, gDwcAuthLabelDate);
    if (endptr != 0)
        func_02168250(endptr);

    endptr = 0;
    errno = 0;
    returncode = atoi((u32)func_0217A728(((DWCAuth *)gDwcAuthGlobal.auth)->http, gDwcAuthLabelHttpResult));
    if (errno == 0x22) {
        ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20101;
        return 12;
    }
    if (returncode != 200) {
        ((DWCAuth *)gDwcAuthGlobal.auth)->error = returncode + 23000;
        return 18;
    }
    if (func_0217A77C(((DWCAuth *)gDwcAuthGlobal.auth)->http, gDwcAuthLabelReturnCd, ((DWCAuth *)gDwcAuthGlobal.auth)->retcode, 4) <= 0) {
        ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20101;
        return 14;
    }
    returncode = strtol((u32)((DWCAuth *)gDwcAuthGlobal.auth)->retcode, (u32 *)(&endptr), 10);
    if (endptr != ((DWCAuth *)gDwcAuthGlobal.auth)->retcode + strlen((const u8 *)((DWCAuth *)gDwcAuthGlobal.auth)->retcode)) {
        ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20101;
        return 12;
    }
    ((DWCAuth *)gDwcAuthGlobal.auth)->error = returncode + 20000;
    if (returncode < 100) {
        ((DWCAuth *)gDwcAuthGlobal.auth)->f1052[0] = 0;
        ((DWCAuth *)gDwcAuthGlobal.auth)->f101f[0] = 0;
        ((DWCAuth *)gDwcAuthGlobal.auth)->f117f[0] = 0;
        ((DWCAuth *)gDwcAuthGlobal.auth)->f1010[0] = 0;
        ((DWCAuth *)gDwcAuthGlobal.auth)->f1188[0] = 0;
        func_0217A77C(((DWCAuth *)gDwcAuthGlobal.auth)->http, gDwcAuthLabelToken, ((DWCAuth *)gDwcAuthGlobal.auth)->f1052, 0x12d);
        func_0217A77C(((DWCAuth *)gDwcAuthGlobal.auth)->http, gDwcAuthLabelLocator, ((DWCAuth *)gDwcAuthGlobal.auth)->f101f, 0x33);
        func_0217A77C(((DWCAuth *)gDwcAuthGlobal.auth)->http, gDwcAuthLabelChallenge, ((DWCAuth *)gDwcAuthGlobal.auth)->f117f, 9);
        func_0217A77C(((DWCAuth *)gDwcAuthGlobal.auth)->http, gDwcAuthLabelDateTime, ((DWCAuth *)gDwcAuthGlobal.auth)->f1010, 0xf);
        func_0217A7C8(((DWCAuth *)gDwcAuthGlobal.auth)->http, gDwcAuthLabelSetCookie, ((DWCAuth *)gDwcAuthGlobal.auth)->f1188, 0x41);
        ((DWCAuth *)gDwcAuthGlobal.auth)->f11b3 = 0;
        if (returncode != 40)
            gDwcAuthGlobal.state = 1;
        else
            gDwcAuthGlobal.state = 2;
    }
    return 0;
}
