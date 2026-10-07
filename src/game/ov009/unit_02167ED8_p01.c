/*
 * file:     unit_02167ED8_p01.c
 * unit:     yes
 * function: func_02167ED8, func_02167FA8
 * address:  0x02167ED8
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
 */
#include "../../matched/include/G_NasTimeDiff_.h"

struct RTCDate;
struct RTCTime;
struct DWCSvlResult;
typedef struct AuthId {
    int f0[4];
    int f10;
} AuthId;

typedef unsigned char  u8;

extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);
extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
extern void func_020891E0(struct RTCDate *date, struct RTCTime *time, long long sec);
extern void func_02058FB4(AuthId *id);
extern int func_0217C070(void *alloc, void *free);
extern int func_0209477C(const u8 *s);
extern int func_0217C144(char *svc, struct DWCSvlResult *result);
extern void func_0217C104(void);
extern void DWC_Alloc(void);
extern void DWC_Free(void);
int func_02167ED8(void *date, void *time);
int func_02167FA8(char *svl, void *result);
extern struct NasTimeDiff_ g_021AA834;
extern long long g_021AA838;
extern long long g_021AA840;
extern char g_021A1F6C[];


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
