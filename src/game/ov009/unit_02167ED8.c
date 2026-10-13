/*
 * file:     unit_02167ED8.c
 * unit:     yes
 * function: func_02167ED8, func_02167FA8, func_02168040, func_02168064, func_02168124
 * address:  0x02167ED8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020889C0  0x020889C0  arm
 *   func_02089004  0x02089004  arm
 *   func_020891E0  0x020891E0  arm
 *   g_021AA834     0x021AA834  data
 *   g_021AA838     0x021AA838  data
 *   g_021AA840     0x021AA840  data
 *   func_02058FB4  0x02058FB4  arm
 *   func_0217C070  0x0217C070  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_0217C144  0x0217C144  arm  ov009
 *   func_0217C104  0x0217C104  arm  ov009
 *   DWC_Alloc      0x0205A16C  arm
 *   DWC_Free       0x0205A1B0  arm
 *   g_021A1F6C     0x021A1F6C  data
 *   func_0217C384  0x0217C384  arm  ov009
 *   OS_Terminate   0x02088234  arm
 *   DWCi_SetError  0x02059F54  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02177EE8  0x02177EE8  arm  ov009
 *   g_021AA830     0x021AA830  data
 *   g_021A1F74     0x021A1F74  data
 *   func_021781DC  0x021781DC  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02178224  0x02178224  arm  ov009
 *   func_02178144  0x02178144  arm  ov009
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_02059F54  0x02059F54  arm
 */
#include "../../matched/include/G_NasTimeDiff_.h"

struct RTCDate;
struct RTCTime;
struct DWCSvlResult;
struct DWCAuthParam;
typedef struct AuthId {
    int f0[4];
    int f10;
} AuthId;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int returncode;
    char retcode[4];
    char datetime[15];
    char locator[51];
    char token[301];
    char challenge[9];
    char cookie[65];
} AuthResult;

typedef struct NalCnt {
    unsigned char http[0x1C50];
    unsigned char auth[0x1C84 - 0x1C50];
    unsigned char id[0x1C90 - 0x1C84];
    void *(*alloc)(int, int);
    void (*free)(int, void *, unsigned long);
    AuthResult result;
} NalCnt;

extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);
extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
extern void func_020891E0(struct RTCDate *date, struct RTCTime *time, long long sec);
extern void func_02058FB4(AuthId *id);
extern int func_0217C070(void *(*alloc)(int, int), void (*free)(int, void *, unsigned long));
extern int func_0209477C(const u8 *s);
extern int func_0217C144(char *svc, struct DWCSvlResult *result);
extern void func_0217C104(void);
extern int func_0217C384(void);
extern void *DWC_Alloc(int kind, int size);
extern void DWC_Free(int name, void *ptr, unsigned long size);
extern void OS_Terminate(void);
extern void DWCi_SetError(int kind, int code);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(void *src, void *dst, unsigned long size);
extern int func_02177EE8(struct DWCAuthParam *param, void *http);
extern int func_021781DC(void);
extern void func_02178224(int *result);
extern void func_02178144(void);
extern struct NasTimeDiff_ g_021AA834;
extern long long g_021AA838;
extern long long g_021AA840;
extern char g_021A1F6C[];
extern char g_021A1F74[];
extern NalCnt *g_021AA830;
int func_02167ED8(void *date, void *time);
int func_02167FA8(char *svl, void *result);
int func_02168040(void);
int func_02168064(void);
int func_02168124(void);

/*
 * sdk:      DWC_GetDateTime (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 */
int func_02167ED8(void *date, void *time)
{
    long long localsec;

    if ((*(int *)&g_021AA834) == 0)
        return 0;
    if (func_020889C0(date, time) != 0)
        return 0;
    localsec = func_02089004(date, time);
    if (localsec == -1LL)
        return 0;
    if (localsec < g_021AA838)
        localsec += 3155760000LL;
    localsec -= g_021AA840;
    if (localsec < 0 || localsec > 3155759999LL)
        return 0;
    func_020891E0(date, time, localsec);
    return 1;
}



/*
 * sdk:      DWC_SVLGetTokenAsync (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 */
int func_02167FA8(char *svl, void *result)
{
    AuthId id;
    int flag;

    func_02058FB4(&id);
    if (id.f10 == 0)
        return 0;
    if (func_0217C070(DWC_Alloc, DWC_Free) == 0)
        return 0;
    if (func_0209477C((const u8 *)svl) == 0)
        flag = func_0217C144(g_021A1F6C, result);
    else
        flag = func_0217C144(svl, result);
    if (flag != 0)
        return 1;
    func_0217C104();
    return 0;
}


/*
 * Calls func_0217C104 when func_0217C384 returns 3 to 5.
 */
int func_02168040(void)
{
    int v = func_0217C384();
    if ((u32)(v - 3) <= 2) func_0217C104();
    return v;
}


/*
 * sdk:      DWC_NASLoginAsync (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 */
int func_02168064(void)
{
    if (g_021AA830 != 0)
        OS_Terminate();
    g_021AA830 = DWC_Alloc(4, 0x1E5C);
    if (g_021AA830 == 0) {
        DWCi_SetError(9, -20100);
        return 0;
    }
    MI_CpuFill8(g_021AA830, 0, 0x1E5C);
    MI_CpuCopy8(g_021A1F74, g_021AA830->id, 9);
    g_021AA830->alloc = DWC_Alloc;
    g_021AA830->free = DWC_Free;
    func_02177EE8((struct DWCAuthParam *)g_021AA830->auth, g_021AA830);
    return 1;
}


/*
 * sdk:      DWC_NASLoginProcess (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 */
int func_02168124(void)
{
    AuthResult result;

    if (g_021AA830 == 0)
        return 0;
    switch (func_021781DC()) {
    case 0:
        return 2;
    case 0x15:
        MI_CpuFill8(&result, 0, sizeof(result));
        func_02178224((int *)(&result));
        func_02178144();
        if (result.returncode == 20002) {
            func_02177EE8((struct DWCAuthParam *)g_021AA830->auth, g_021AA830->http);
            return 2;
        }
        DWC_Free(4, g_021AA830, 7772);
        g_021AA830 = 0;
        return 3;
    case 0x14:
        func_02178144();
        DWC_Free(4, g_021AA830, 7772);
        g_021AA830 = 0;
        return 5;
    default:
        func_02178224((int *)(&result));
        func_02178144();
        DWC_Free(4, g_021AA830, 7772);
        g_021AA830 = 0;
        DWCi_SetError(2, result.returncode);
        return 4;
    }
}
