/*
 * function: DWCi_RemoteLogin
 * address:  0x0216A6F4
 * packet:   pkt_ov009_0216A6F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RemoteLogin (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   func_020596C8  0x020596C8  arm
 *   DWCi_Acc_LoginIdToUserName  0x02059474  arm
 *   func_02059084  0x02059084  arm
 *   DWCi_Acc_IsValidLoginId  0x020596B0  arm
 *   DWCi_Acc_CheckConsoleUserId  0x02059644  arm
 *   DWCi_Acc_CreateTempLoginId  0x02059588  arm
 *   OS_GetTick     0x020870D0  arm
 *   DWCi_Acc_SetPlayerId  0x020590F0  arm
 *   DWCi_Auth_StartAuthentication  0x02178D14  arm  ov009
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   gDwcLoginControl     0x021AA874  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct {
    u32 w0;
    u32 w1;
    u32 w2;
} LoginId;

typedef struct {
    char pad0[4];
    LoginId consoleId;
    char loginId[0x14];
    u32 gamecode;
} UserData;

typedef struct {
    char pad0[0xc];
    u32 gamecode;
    u16 *ingamesn;
    char pad14[8];
    UserData *userdata;
    char pad20[0x1c];
    LoginId loginId;
    char pad48[0x200];
    char username[9];
    char gsbrcd[9];
} LoginControl;

extern LoginControl *gDwcLoginControl;

extern int func_020596C8(UserData *userdata);
struct DWCstAccLoginId;
extern void DWCi_Acc_LoginIdToUserName(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username);
extern u64 func_02059084(void *loginId);
extern int DWCi_Acc_IsValidLoginId(void *loginid);
extern int DWCi_Acc_CheckConsoleUserId(struct DWCstAccLoginId *loginid);
extern void DWCi_Acc_CreateTempLoginId(struct DWCstAccLoginId *loginid);
extern u64 OS_GetTick(void);
extern void DWCi_Acc_SetPlayerId(int *p, int v);
extern int DWCi_Auth_StartAuthentication(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long));
extern void *func_0205A16C(u32, long);
extern void func_0205A1B0(u32, void *, long);

int DWCi_RemoteLogin(void)
{
    u64 userid;

    if (func_020596C8(gDwcLoginControl->userdata)) {
        DWCi_Acc_LoginIdToUserName((struct DWCstAccLoginId *)gDwcLoginControl->userdata->loginId, gDwcLoginControl->userdata->gamecode, gDwcLoginControl->username);
        userid = func_02059084(gDwcLoginControl->userdata->loginId);
    } else {
        if (!DWCi_Acc_IsValidLoginId(&gDwcLoginControl->loginId)) {
            if (DWCi_Acc_CheckConsoleUserId((struct DWCstAccLoginId *)(&gDwcLoginControl->userdata->consoleId)))
                gDwcLoginControl->loginId = gDwcLoginControl->userdata->consoleId;
            else
                DWCi_Acc_CreateTempLoginId((struct DWCstAccLoginId *)(&gDwcLoginControl->loginId));
        } else {
            DWCi_Acc_SetPlayerId((int *)(&gDwcLoginControl->loginId), (u32)((OS_GetTick() * 0x5D588B656C078965ULL + 0x269EC3) >> 32));
        }
        DWCi_Acc_LoginIdToUserName((struct DWCstAccLoginId *)(&gDwcLoginControl->loginId), gDwcLoginControl->gamecode, gDwcLoginControl->username);
        userid = 0;
    }
    return DWCi_Auth_StartAuthentication(gDwcLoginControl->ingamesn, gDwcLoginControl->gsbrcd, userid, func_0205A16C, func_0205A1B0);
}
