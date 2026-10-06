/*
 * function: func_0216A8F4
 * address:  0x0216A8F4
 * packet:   pkt_ov009_0216A8F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPGetInfoCallback (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   func_02059474  0x02059474  arm
 *   func_02185CB4  0x02185CB4  arm  ov009
 *   func_0216A460  0x0216A460  arm  ov009
 *   func_02185BD8  0x02185BD8  arm  ov009
 *   func_02185ACC  0x02185ACC  arm  ov009
 *   func_0216A6F4  0x0216A6F4  arm  ov009
 *   strcmp         0x020948E0  arm
 *   func_020597F0  0x020597F0  arm
 *   func_0216A68C  0x0216A68C  arm  ov009
 *   g_021AA874     0x021AA874  data
 *   func_0216A8F4  0x0216A8F4  arm  ov009
 *   func_0216A4D4  0x0216A4D4  arm  ov009
 */

typedef unsigned long u32;

typedef struct {
    u32 w0;
    u32 w1;
    u32 w2;
} LoginId;

typedef struct {
    char pad0[4];
    LoginId consoleId;
} UserData;

typedef struct {
    char pad0[4];
    int state;
    char pad8[4];
    u32 gamecode;
    char pad10[0xc];
    UserData *userdata;
    char pad20[0x1c];
    LoginId loginId;
} LoginControl;

typedef struct {
    int result;
    int profile;
    char pad8[0x86];
    char nick[21];
} GPGetInfoResponseArg;

extern LoginControl *g_021AA874;

struct DWCstAccLoginId;
struct DWCstAccUserData;
extern void func_02059474(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username);
extern int func_02185CB4(void **connection, int info, char *value);
extern int func_0216A460(int result);
extern int func_02185BD8(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
extern void func_02185ACC(void **connection);
extern int func_0216A6F4(void);
extern int strcmp(const char *a, const char *b);
extern void func_020597F0(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id);
struct GPConnectResponseArg;
extern void func_0216A68C(void *callback, int next_state);
extern void func_0216A8F4(void **pconnection, GPGetInfoResponseArg *arg);
extern void func_0216A4D4(void **pconnection, struct GPConnectResponseArg *arg);

void func_0216A8F4(void **pconnection, GPGetInfoResponseArg *arg)
{
    char pseudo_name2[21];
    char pseudo_name[21];
    char username[21];
    int gpResult;

    if (arg->result != 0)
        return;
    if (g_021AA874->state == 3) {
        if (arg->nick[0] == 0) {
            func_02059474((struct DWCstAccLoginId *)(&g_021AA874->userdata->consoleId), g_021AA874->gamecode, pseudo_name2);
            gpResult = func_02185CB4(pconnection, 0x705, pseudo_name2);
            if (func_0216A460(gpResult))
                return;
            g_021AA874->state = 4;
            gpResult = func_02185BD8(pconnection, arg->profile, 0, 0, (void (*)(void **, void *, void *))func_0216A8F4, 0);
            func_0216A460(gpResult);
        } else {
            func_02185ACC(pconnection);
            func_0216A6F4();
            g_021AA874->state = 1;
        }
    } else if (g_021AA874->state == 4) {
        func_02059474((struct DWCstAccLoginId *)(&g_021AA874->userdata->consoleId), g_021AA874->gamecode, pseudo_name);
        if (strcmp(arg->nick, pseudo_name) == 0) {
            func_02059474((struct DWCstAccLoginId *)(&g_021AA874->loginId), g_021AA874->gamecode, username);
            func_020597F0((struct DWCstAccUserData *)g_021AA874->userdata, (struct DWCstAccLoginId *)(&g_021AA874->loginId), arg->profile);
            func_02185ACC(pconnection);
            func_0216A68C(func_0216A4D4, 2);
        } else {
            gpResult = func_02185BD8(pconnection, arg->profile, 0, 0, (void (*)(void **, void *, void *))func_0216A8F4, 0);
            func_0216A460(gpResult);
        }
    }
}
