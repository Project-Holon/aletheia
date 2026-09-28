/*
 * function: func_021782B4
 * address:  0x021782B4
 * packet:   pkt_ov009_021782B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_Auth_Start (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   func_020948E0  0x020948E0  arm
 *   func_0217956C  0x0217956C  arm  ov009
 *   func_02058518  0x02058518  arm
 *   func_02178A94  0x02178A94  arm  ov009
 *   func_0217967C  0x0217967C  arm  ov009
 *   func_02085A30  0x02085A30  arm
 *   func_02179718  0x02179718  arm  ov009
 *   g_021A2358  0x021A2358  data  ov009
 *   g_021A2374  0x021A2374  data  ov009
 *   g_021AB184  0x021AB184  data  ov009
 *   g_021AB190  0x021AB190  data  ov009
 *   g_02150FEC  0x02150FEC  data
 *
 * notes: DIFF, one instruction short. Target loads &DWCauthhttpparam from a second literal-pool entry for the DWC_Http_Create argument (pool holds the symbol twice) instead of reusing the base used for the .fc/.f10 stores; struct copy, array, volatile, inline wrapper and cast variants all fold it. Tried every dsi compiler (object stamp 4.0.0.1025 has no build).
 */

typedef struct DWCHttp DWCHttp;

typedef struct DWCHttpParam
{
    const char *url;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} DWCHttpParam;

typedef struct DWCAuth
{
    char pad0[0x1004];
    int result;
    char pad1008[0x1cc - 0x8];
    unsigned short ingamesn[26];
    char pad1200[0];
} DWCAuth;

typedef struct DWCWFCUtil
{
    int f0;
    char *auth;
} DWCWFCUtil;

typedef struct
{
    int f0;
    void *current;
} OSThreadInfo;

extern int func_020948E0(const char *, const char *);
extern int func_0217956C(DWCHttp *http, DWCHttpParam *param);
extern void func_02058518(void *buf);
extern int func_02178A94(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn);
extern int func_0217967C(DWCHttp *http);
extern unsigned long func_02085A30(void *thread);
extern void func_02179718(DWCHttp *http, unsigned long prio);

extern DWCHttpParam g_021A2358;
extern char g_021A2374[];
extern DWCWFCUtil g_021AB184;
extern char g_021AB190[];
extern OSThreadInfo g_02150FEC;

#define AUTH_RESULT (*(int *)(g_021AB184.auth + 0x1004))
#define AUTH_HTTP (*(DWCHttp **)(g_021AB184.auth + 0x1314))

int func_021782B4(int getwifiinfofromflash)
{
    if (func_020948E0(g_021A2358.url, g_021A2374) != 0)
        g_021A2358.f14 = 1;

    g_021A2358.fc = *(int *)(g_021AB184.auth + 0x120c);
    g_021A2358.f10 = *(int *)(g_021AB184.auth + 0x1210);
    if (func_0217956C(AUTH_HTTP, &g_021A2358) != 0)
        return 4;

    if (getwifiinfofromflash == 1)
        func_02058518(g_021AB190);

    AUTH_RESULT = func_02178A94(AUTH_HTTP, g_021AB184.auth + 0x1200, (unsigned short *)(g_021AB184.auth + 0x11cc));
    if (AUTH_RESULT != 0)
        return 4;

    if (func_0217967C(AUTH_HTTP) != 0)
        return 4;

    func_02179718(AUTH_HTTP, func_02085A30(g_02150FEC.current) - 1);
    return 0;
}
