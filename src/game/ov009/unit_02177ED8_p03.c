/*
 * file:     unit_02177ED8_p03.c
 * unit:     yes
 * function: func_021782B4, func_021783BC, func_02178678, func_02178814, func_02178A94
 * address:  0x021782B4
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
 *   func_020948E0  0x020948E0  arm
 *   func_0217956C  0x0217956C  arm  ov009
 *   func_02058518  0x02058518  arm
 *   func_0217967C  0x0217967C  arm  ov009
 *   func_02085A30  0x02085A30  arm
 *   func_02179718  0x02179718  arm  ov009
 *   g_021A2358  0x021A2358  data  ov009
 *   g_021A2358_arg  0x021A2358  data  ov009
 *   g_021A2374  0x021A2374  data  ov009
 *   g_021AB184  0x021AB184  data  ov009
 *   g_021AB190  0x021AB190  data  ov009
 *   g_02150FEC  0x02150FEC  data
 *   func_0208574C  0x0208574C  arm
 *   func_02085710  0x02085710  arm
 *   func_02178C48  0x02178C48  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_02085A38  0x02085A38  arm
 *   func_02179CF4  0x02179CF4  arm  ov009
 *   func_0217A484  0x0217A484  arm  ov009
 *   func_02058DD0  0x02058DD0  arm
 *   func_02058E20  0x02058E20  arm
 *   func_02058D88  0x02058D88  arm
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
 *   func_02179F3C  0x02179F3C  arm  ov009
 *   func_02178F78  0x02178F78  arm  ov009
 *   func_02179218  0x02179218  arm  ov009
 *   func_02096578  0x02096578  arm
 *   g_021A23E8  0x021A23E8  data  ov009
 *   g_021A23F4  0x021A23F4  data  ov009
 *   g_021A23FC  0x021A23FC  data  ov009
 *   g_021A2404  0x021A2404  data  ov009
 *   g_021ACE70  0x021ACE70  data  ov009
 *   g_021A240C  0x021A240C  data  ov009
 *   g_021A2410  0x021A2410  data  ov009
 *   g_021A2418  0x021A2418  data  ov009
 */
#include "../../matched/include/G_DWCWFCUtil.h"
#include "../../matched/include/G_DWCHttpParam.h"
#include "../../matched/include/G_DWCWFCUtil.h"

#define AUTH_RESULT (*(int *)(((char *)g_021AB184.auth) + 0x1004))
#define AUTH_HTTP (*(DWCHttp_021782B4 **)(((char *)g_021AB184.auth) + 0x1314))
struct tagDWCWiFiInfo;
struct DWCHttp;
struct DWCWiFiInfo;
typedef struct DWCHttp_021782B4 DWCHttp_021782B4;

typedef struct DWCHttpParam DWCHttpParam;

typedef struct DWCAuth_021782B4
{
    char pad0[0x1004];
    int result;
    char pad1008[0x1cc - 0x8];
    unsigned short ingamesn[26];
    char pad1200[0];
} DWCAuth_021782B4;

typedef struct DWCWFCUtil DWCWFCUtil;

typedef struct
{
    int f0;
    void *current;
} OSThreadInfo;

typedef struct OSThread OSThread;

typedef struct OSMutex { char pad[0x18]; } OSMutex;

typedef struct DWCHttp_021783BC {
    char pad0[0x1020];
    int state;
    char pad1024[0xb50];
    char thread[0x6c];
    int thread_started;
} DWCHttp_021783BC;

typedef struct DWCAuth_021783BC {
    char pad0[0x1004];
    int result;
    int error;
    char pad100c[0x308];
    DWCHttp_021783BC *http;
    char pad1318[0xc0];
    OSMutex mutex;
    int abort;
} DWCAuth_021783BC;

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

typedef struct DWCCalInfo
{
    char data[0x94];
} DWCCalInfo;

typedef unsigned short u16;

extern int func_020948E0(const char *, const char *);
extern int func_0217956C(struct DWCHttp_021782B4 *http, struct DWCHttpParam *param);
extern void func_02058518(struct tagDWCWiFiInfo *buf);
extern int func_0217967C(char *http);
extern unsigned long func_02085A30(void *thread);
extern void func_02179718(char *http, unsigned long prio);
extern int func_0208574C(void *thread);
extern void func_02085710(void *thread);
extern void func_02178C48(int error);
extern unsigned long long func_020870D0(void);
extern void func_02086028(OSMutex *mutex);
extern void func_02086078(OSMutex *mutex);
extern void func_02085A38(unsigned long msec);
extern void func_02179CF4(char *http);
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
extern int func_02179F3C(struct DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int func_02178F78(struct DWCCalInfo *cal, struct DWCWiFiInfo *wifiinfo);
extern int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int func_02096578(const u16 *s);
int func_021782B4(int getwifiinfofromflash);
void func_021783BC(void);
int func_02178678(void);
int func_02178814(void);
int func_02178A94(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn);
extern struct DWCHttpParam g_021A2358;
extern struct DWCHttpParam g_021A2358_arg;
extern char g_021A2374[];
extern struct DWCWFCUtil g_021AB184;
extern char g_021AB190[];
extern OSThreadInfo g_02150FEC;
extern int g_02153FAC;
extern char g_021A2394[];
extern char g_021A239C[];
extern char g_021A23A8[];
extern char g_021A23B4[];
extern char g_021A23BC[];
extern char g_021A23C4[];
extern char g_021A23D0[];
extern char g_021A23DC[];
extern char g_021A23E8[];
extern char g_021A23F4[];
extern char g_021A23FC[];
extern char g_021A2404[];
extern int g_021ACE70;
extern char g_021A240C[];
extern char g_021A2410[];
extern char g_021A2418[];




/*
 * sdk:      DWCi_Auth_Start (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * The pool carried 0x021A2358 twice: once for the url/f14/fc/f10 accesses and
 * once for the DWC_Http_Create argument, so the source named the struct through
 * two externs (docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-*).
 * With one name 1.1p1 CSEs both uses into a callee-saved register and the
 * function comes out one instruction (8 bytes) short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_021782B4.c \
 *       --func func_021782B4 --addr 0x021782B4 --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */
int func_021782B4(int getwifiinfofromflash)
{
    if (func_020948E0(g_021A2358.url, g_021A2374) != 0)
        g_021A2358.f14 = 1;

    g_021A2358.fc = *(int *)(((char *)g_021AB184.auth) + 0x120c);
    g_021A2358.f10 = *(int *)(((char *)g_021AB184.auth) + 0x1210);
    if (func_0217956C(AUTH_HTTP, &g_021A2358_arg) != 0)
        return 4;

    if (getwifiinfofromflash == 1)
        func_02058518((struct tagDWCWiFiInfo *)g_021AB190);

    AUTH_RESULT = func_02178A94((DWCHttp *)AUTH_HTTP, ((char *)g_021AB184.auth) + 0x1200, (unsigned short *)(((char *)g_021AB184.auth) + 0x11cc));
    if (AUTH_RESULT != 0)
        return 4;

    if (func_0217967C((char *)AUTH_HTTP) != 0)
        return 4;

    func_02179718((char *)AUTH_HTTP, func_02085A30(g_02150FEC.current) - 1);
    return 0;
}




/*
 * sdk:      DWCi_Auth_Thread (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
void func_021783BC(void)
{
    int retrycount = 0;
    unsigned long long startwait;
    int result_httpparse;
    int getwifiinfofromflash;

    for (;;) {
        if (((DWCAuth_021783BC *)g_021AB184.auth)->http->thread_started != 0
            && !func_0208574C(((DWCAuth_021783BC *)g_021AB184.auth)->http->thread))
            func_02085710(((DWCAuth_021783BC *)g_021AB184.auth)->http->thread);

        if (((DWCAuth_021783BC *)g_021AB184.auth)->http->state != 8) {
            ((DWCAuth_021783BC *)g_021AB184.auth)->error = 20100;
            if (((DWCAuth_021783BC *)g_021AB184.auth)->http->state == 7) {
                func_02178C48(20);
                return;
            }
            if (retrycount > 2) {
                if (((DWCAuth_021783BC *)g_021AB184.auth)->http->state == 2)
                    func_02178C48(9);
                else if (((DWCAuth_021783BC *)g_021AB184.auth)->http->state == 3)
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
            func_02086028(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
            if (((DWCAuth_021783BC *)g_021AB184.auth)->abort == 1) {
                ((DWCAuth_021783BC *)g_021AB184.auth)->error = 20100;
                func_02086078(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
                func_02178C48(20);
                return;
            }
            func_02086078(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
            func_02085A38(5000);
        }

        func_02179CF4((char *)((DWCAuth_021783BC *)g_021AB184.auth)->http);
        func_02086028(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
        ((DWCAuth_021783BC *)g_021AB184.auth)->result = func_021782B4(getwifiinfofromflash);
        if (((DWCAuth_021783BC *)g_021AB184.auth)->result != 0) {
            ((DWCAuth_021783BC *)g_021AB184.auth)->error = 20100;
            func_02086078(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
            return;
        }
        func_02086078(&((DWCAuth_021783BC *)g_021AB184.auth)->mutex);
    }
}




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


/*
 * sdk:      DWCi_Auth_Prepare_FirstPost (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
int func_02178A94(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn)
{
    DWCCalInfo calinfo;

    if (g_021AB184.userid == 0)
    {
        if (func_02179F3C(http, g_021A23F4, g_021A23E8, func_0209477C((const u8 *)g_021A23E8)) != 0)
            return 8;
    }
    else
    {
        if (func_02179F3C(http, g_021A23F4, g_021A23FC, func_0209477C((const u8 *)g_021A23FC)) != 0)
            return 8;
        if (func_02179F3C(http, g_021A2404, gsbrcd, func_0209477C((const u8 *)gsbrcd)) != 0)
            return 8;
    }

    if (!func_02178F78(&calinfo, (struct DWCWiFiInfo *)g_021AB190))
        return 5;
    if (!func_02179218(http, &calinfo, g_021ACE70))
        return 8;

    if (g_021AB184.f0 == 1)
    {
        if (func_02179F3C(http, g_021A2410, g_021A240C, func_0209477C((const u8 *)g_021A240C)) != 0)
            return 8;
    }

    if (func_02096578(ingamesn) != 0)
    {
        if (func_02179F3C(http, g_021A2418, (char *)ingamesn, func_02096578(ingamesn) * 2) != 0)
            return 8;
    }
    return 0;
}
