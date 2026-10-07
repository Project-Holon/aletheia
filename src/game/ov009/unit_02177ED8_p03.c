/*
 * file:     unit_02177ED8_p03.c
 * unit:     yes
 * function: func_02178678, func_02178814
 * address:  0x02178678
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
 *   func_0217A484  0x0217A484  arm  ov009
 *   func_02058DD0  0x02058DD0  arm
 *   func_02058E20  0x02058E20  arm
 *   func_02058D88  0x02058D88  arm
 *   g_021AB184  0x021AB184  data  ov009
 *   g_021AB190  0x021AB190  data  ov009
 *   func_0217A728  0x0217A728  arm  ov009
 *   func_02168250  0x02168250  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
 *   func_02095F40  0x02095F40  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0217A7C8  0x0217A7C8  arm  ov009
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
#include "../../matched/include/G_DWCWFCUtil.h"

struct DWCHttp;
struct tagDWCWiFiInfo;
typedef struct DWCAuthParam
{
    unsigned short ingamesn[26];
    char gsbrcd[12];
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
} DWCAuthParam;

typedef struct DWCAuth_02178678
{
    char pad0[0x1004];
    int result;
    int error;
    char pad100c[0x11cc - 0x100c];
    DWCAuthParam param;
    char pad1214[0x1314 - 0x1214];
    void *http;
    char pad1318[0x13f4 - 0x1318];
} DWCAuth_02178678;

typedef struct DWCWFCUtil DWCWFCUtil;

typedef struct DWCHttp DWCHttp;

typedef struct DWCAuth_02178814 {
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
} DWCAuth_02178814;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_0217A484(struct DWCHttp *http, int noparsebody);
extern int func_02058DD0(struct tagDWCWiFiInfo *wifiinfo, void *work);
extern int func_02058E20(struct tagDWCWiFiInfo *wifiinfo);
extern int func_02058D88(void *work);
extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
extern int func_020964E0(u32 a0);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
extern s32 func_02095F40(u32 a0, u32 *a1, u32 a2);
extern int func_0209477C(const u8 *s);
extern int func_0217A7C8(DWCHttp *http, char *label, char *buffer, int buffer_len);
int func_02178678(void);
int func_02178814(void);
extern struct DWCWFCUtil g_021AB184;
extern char g_021AB190[];
extern int g_02153FAC;
extern char g_021A2394[];
extern char g_021A239C[];
extern char g_021A23A8[];
extern char g_021A23B4[];
extern char g_021A23BC[];
extern char g_021A23C4[];
extern char g_021A23D0[];
extern char g_021A23DC[];


/*
 * sdk:      DWCi_Auth_ParseHttp (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
int func_02178678(void)
{
    void *(*alloc)(unsigned long, long) = ((DWCAuth_02178678 *)g_021AB184.auth)->param.alloc;
    void (*free)(unsigned long, void *, long) = ((DWCAuth_02178678 *)g_021AB184.auth)->param.free;
    unsigned char *bmwork;

    if (func_0217A484(((DWCAuth_02178678 *)g_021AB184.auth)->http, 0) != 1)
    {
        ((DWCAuth_02178678 *)g_021AB184.auth)->error = 20100;
        return 14;
    }
    if (func_02178814() != 0)
        return 14;

    if (((DWCAuth_02178678 *)g_021AB184.auth)->error < 20100)
    {
        if (((DWCAuth_02178678 *)g_021AB184.auth)->error == 20002)
        {
            bmwork = (unsigned char *)alloc(0, 0x101f);
            if (bmwork == 0)
            {
                ((DWCAuth_02178678 *)g_021AB184.auth)->error = 20100;
                return 2;
            }
            if (func_02058DD0((struct tagDWCWiFiInfo *)g_021AB190, (void *)(((unsigned long)bmwork + 31) & ~31)) != 1)
            {
                free(0, bmwork, 0);
                ((DWCAuth_02178678 *)g_021AB184.auth)->error = 20100;
                return 15;
            }
            free(0, bmwork, 0);
        }
        return 21;
    }
    switch (((DWCAuth_02178678 *)g_021AB184.auth)->error)
    {
    case 20104:
        func_02058E20((struct tagDWCWiFiInfo *)g_021AB190);
        ((DWCAuth_02178678 *)g_021AB184.auth)->error = 20104;
        return 16;
    case 20108:
        bmwork = (unsigned char *)alloc(0, 0x1000);
        if (bmwork == 0)
        {
            ((DWCAuth_02178678 *)g_021AB184.auth)->error = 20108;
            return 17;
        }
        func_02058D88((void *)(((unsigned long)bmwork + 31) & ~31));
        free(0, bmwork, 0);
        ((DWCAuth_02178678 *)g_021AB184.auth)->error = 20108;
        return 17;
    default:
        return 18;
    }
}


/*
 * sdk:      DWCi_Auth_FillResult (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
int func_02178814(void)
{
    char *endptr;
    int returncode;

    endptr = 0;
    endptr = func_0217A728(((DWCAuth_02178814 *)g_021AB184.auth)->http, g_021A2394);
    if (endptr != 0)
        func_02168250(endptr);

    endptr = 0;
    g_02153FAC = 0;
    returncode = func_020964E0((u32)func_0217A728(((DWCAuth_02178814 *)g_021AB184.auth)->http, g_021A239C));
    if (g_02153FAC == 0x22) {
        ((DWCAuth_02178814 *)g_021AB184.auth)->error = 20101;
        return 12;
    }
    if (returncode != 200) {
        ((DWCAuth_02178814 *)g_021AB184.auth)->error = returncode + 23000;
        return 18;
    }
    if (func_0217A77C(((DWCAuth_02178814 *)g_021AB184.auth)->http, g_021A23A8, ((DWCAuth_02178814 *)g_021AB184.auth)->retcode, 4) <= 0) {
        ((DWCAuth_02178814 *)g_021AB184.auth)->error = 20101;
        return 14;
    }
    returncode = func_02095F40((u32)((DWCAuth_02178814 *)g_021AB184.auth)->retcode, (u32 *)(&endptr), 10);
    if (endptr != ((DWCAuth_02178814 *)g_021AB184.auth)->retcode + func_0209477C((const u8 *)((DWCAuth_02178814 *)g_021AB184.auth)->retcode)) {
        ((DWCAuth_02178814 *)g_021AB184.auth)->error = 20101;
        return 12;
    }
    ((DWCAuth_02178814 *)g_021AB184.auth)->error = returncode + 20000;
    if (returncode < 100) {
        ((DWCAuth_02178814 *)g_021AB184.auth)->f1052[0] = 0;
        ((DWCAuth_02178814 *)g_021AB184.auth)->f101f[0] = 0;
        ((DWCAuth_02178814 *)g_021AB184.auth)->f117f[0] = 0;
        ((DWCAuth_02178814 *)g_021AB184.auth)->f1010[0] = 0;
        ((DWCAuth_02178814 *)g_021AB184.auth)->f1188[0] = 0;
        func_0217A77C(((DWCAuth_02178814 *)g_021AB184.auth)->http, g_021A23B4, ((DWCAuth_02178814 *)g_021AB184.auth)->f1052, 0x12d);
        func_0217A77C(((DWCAuth_02178814 *)g_021AB184.auth)->http, g_021A23BC, ((DWCAuth_02178814 *)g_021AB184.auth)->f101f, 0x33);
        func_0217A77C(((DWCAuth_02178814 *)g_021AB184.auth)->http, g_021A23C4, ((DWCAuth_02178814 *)g_021AB184.auth)->f117f, 9);
        func_0217A77C(((DWCAuth_02178814 *)g_021AB184.auth)->http, g_021A23D0, ((DWCAuth_02178814 *)g_021AB184.auth)->f1010, 0xf);
        func_0217A7C8(((DWCAuth_02178814 *)g_021AB184.auth)->http, g_021A23DC, ((DWCAuth_02178814 *)g_021AB184.auth)->f1188, 0x41);
        ((DWCAuth_02178814 *)g_021AB184.auth)->f11b3 = 0;
        if (returncode != 40)
            g_021AB184.state = 1;
        else
            g_021AB184.state = 2;
    }
    return 0;
}
