/*
 * function: DWCi_GPGetInfoCallback
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
 *   DWCi_Acc_LoginIdToUserName  0x02059474  arm
 *   func_02185CB4  0x02185CB4  arm  ov009
 *   DWCi_HandleGPError  0x0216A460  arm  ov009
 *   gpGetInfo  0x02185BD8  arm  ov009
 *   func_02185ACC  0x02185ACC  arm  ov009
 *   DWCi_RemoteLogin  0x0216A6F4  arm  ov009
 *   strcmp         0x020948E0  arm
 *   DWCi_Acc_SetLoginIdToUserData  0x020597F0  arm
 *   DWCi_GPConnect  0x0216A68C  arm  ov009
 *   gDwcLoginControl     0x021AA874  data
 *   DWCi_GPGetInfoCallback  0x0216A8F4  arm  ov009
 *   DWCi_GPConnectCallback  0x0216A4D4  arm  ov009
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

extern LoginControl *gDwcLoginControl;

struct DWCstAccLoginId;
struct DWCstAccUserData;
extern void DWCi_Acc_LoginIdToUserName(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username);
extern int func_02185CB4(void **connection, int info, char *value);
extern int DWCi_HandleGPError(int result);
extern int gpGetInfo(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
extern void func_02185ACC(void **connection);
extern int DWCi_RemoteLogin(void);
extern int strcmp(const char *a, const char *b);
extern void DWCi_Acc_SetLoginIdToUserData(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id);
struct GPConnectResponseArg;
extern void DWCi_GPConnect(void *callback, int next_state);
extern void DWCi_GPGetInfoCallback(void **pconnection, GPGetInfoResponseArg *arg);
extern void DWCi_GPConnectCallback(void **pconnection, struct GPConnectResponseArg *arg);

void DWCi_GPGetInfoCallback(void **pconnection, GPGetInfoResponseArg *arg)
{
    char pseudo_name2[21];
    char pseudo_name[21];
    char username[21];
    int gpResult;

    if (arg->result != 0)
        return;
    if (gDwcLoginControl->state == 3) {
        if (arg->nick[0] == 0) {
            DWCi_Acc_LoginIdToUserName((struct DWCstAccLoginId *)(&gDwcLoginControl->userdata->consoleId), gDwcLoginControl->gamecode, pseudo_name2);
            gpResult = func_02185CB4(pconnection, 0x705, pseudo_name2);
            if (DWCi_HandleGPError(gpResult))
                return;
            gDwcLoginControl->state = 4;
            gpResult = gpGetInfo(pconnection, arg->profile, 0, 0, (void (*)(void **, void *, void *))DWCi_GPGetInfoCallback, 0);
            DWCi_HandleGPError(gpResult);
        } else {
            func_02185ACC(pconnection);
            DWCi_RemoteLogin();
            gDwcLoginControl->state = 1;
        }
    } else if (gDwcLoginControl->state == 4) {
        DWCi_Acc_LoginIdToUserName((struct DWCstAccLoginId *)(&gDwcLoginControl->userdata->consoleId), gDwcLoginControl->gamecode, pseudo_name);
        if (strcmp(arg->nick, pseudo_name) == 0) {
            DWCi_Acc_LoginIdToUserName((struct DWCstAccLoginId *)(&gDwcLoginControl->loginId), gDwcLoginControl->gamecode, username);
            DWCi_Acc_SetLoginIdToUserData((struct DWCstAccUserData *)gDwcLoginControl->userdata, (struct DWCstAccLoginId *)(&gDwcLoginControl->loginId), arg->profile);
            func_02185ACC(pconnection);
            DWCi_GPConnect(DWCi_GPConnectCallback, 2);
        } else {
            gpResult = gpGetInfo(pconnection, arg->profile, 0, 0, (void (*)(void **, void *, void *))DWCi_GPGetInfoCallback, 0);
            DWCi_HandleGPError(gpResult);
        }
    }
}
