/*
 * function: func_0216A4D4
 * address:  0x0216A4D4
 * packet:   pkt_ov009_0216A4D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPConnectCallback (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   DWCi_Np_GetConsoleIdPrefix  0x02167E94  arm  ov009
 *   func_02167E88  0x02167E88  arm  ov009
 *   func_02084F80  0x02084F80  arm
 *   func_02185CB4  0x02185CB4  arm  ov009
 *   func_0216A460  0x0216A460  arm  ov009
 *   func_02178F00  0x02178F00  arm  ov009
 *   func_02059408  0x02059408  arm
 *   func_02167EA0  0x02167EA0  arm  ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   DWCi_GT2Startup  0x0216BA4C  arm  ov009
 *   func_02176AA8  0x02176AA8  arm  ov009
 *   func_02176ABC  0x02176ABC  arm  ov009
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   func_02185BD8  0x02185BD8  arm  ov009
 *   func_0216A8F4  0x0216A8F4  arm  ov009
 *   g_021AA874  0x021AA874  data
 *   @16552  0x021A201C  data
 */

typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct DWCstAccUserData {
    char pad[0x1c];
    int gs_profile_id;      /* +0x1c */
} DWCstAccUserData;

typedef struct DWCstLoginControl {
    void **pGpObj;          /* +0x00 */
    int state;              /* +0x04 */
    int productID;          /* +0x08 */
    u32 gamecode;           /* +0x0c */
    unsigned short *playerName; /* +0x10 */
    void (*callback)(int error, int profileID, void *param); /* +0x14 */
    void *param;            /* +0x18 */
    DWCstAccUserData *userdata; /* +0x1c */
    void *bmwork;           /* +0x20 */
    void *http;             /* +0x24 */
    u64 startTick;          /* +0x28 */
    u32 connectFlag;        /* +0x30 */
} DWCstLoginControl;

typedef struct GPConnectResponseArg {
    int result;             /* +0x00 */
    int profile;            /* +0x04 */
    char uniquenick[21];    /* +0x08 */
} GPConnectResponseArg;

extern DWCstLoginControl *g_021AA874;

extern void *DWCi_Np_GetConsoleIdPrefix(void);
extern long long func_02167E88(void);
extern int func_02084F80(char *dst, u32 len, const char *fmt, ...);
extern int func_02185CB4(void **connection, int info, char *value);
extern int func_0216A460(int result);
extern u64 func_02178F00(void);
extern void func_02059408(u64 num, int bitnum, char *result);
extern char *func_02167EA0(void);
extern int func_0216F20C(int matchType);
extern int DWCi_GT2Startup(void);
extern void func_02176AA8(int profileID);
extern void func_02176ABC(void);
extern void func_0216A3B8(int error, int errorCode);
extern int func_02185BD8(void **connection, int profile, int checkCache, int blocking,
                         void (*callback)(void **, void *, void *), void *param);
extern void func_0216A8F4(void **pconnection, void *arg, void *param);

static void func_0216A4D4(void **pconnection, GPConnectResponseArg *arg)
{
    int gpResult;
    char firstname[31];
    char aimname[51];

    g_021AA874->connectFlag = 0;

    func_02084F80(firstname, sizeof(firstname), "%s:%016llu", DWCi_Np_GetConsoleIdPrefix(), func_02167E88());
    gpResult = func_02185CB4(pconnection, 0x704, firstname);
    if (func_0216A460(gpResult))
        return;

    func_02059408(func_02178F00(), 43, aimname);
    gpResult = func_02185CB4(pconnection, 0x717, aimname);
    if (func_0216A460(gpResult))
        return;

    gpResult = func_02185CB4(pconnection, 0x708, func_02167EA0());
    if (func_0216A460(gpResult))
        return;

    if (arg->result == 0) {
        if (g_021AA874->state == 2) {
            if (g_021AA874->userdata->gs_profile_id == arg->profile) {
                g_021AA874->state = 5;
                gpResult = func_0216F20C(1);
                if (func_0216A460(gpResult))
                    return;
                g_021AA874->callback(0, arg->profile, g_021AA874->param);
                if (DWCi_GT2Startup())
                    return;
                func_02176AA8(arg->profile);
                func_02176ABC();
            } else {
                func_0216A3B8(6, -60000);
            }
        } else if (g_021AA874->state == 3) {
            gpResult = func_02185BD8(pconnection, arg->profile, 0, 0, func_0216A8F4, 0);
            func_0216A460(gpResult);
        }
    } else {
        func_0216A460(arg->result);
    }
}
