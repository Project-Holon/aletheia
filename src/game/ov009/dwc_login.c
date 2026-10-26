/*
 * file:     dwc_login.c
 * unit:     yes
 * function: DWCi_LoginInit, DWCi_LoginAsync, DWCi_LoginProcess, DWCi_GetUserData, DWCi_StopLogin, DWCi_ShutdownLogin, DWCi_CloseLogin, DWCi_HandleGPError, DWCi_GPConnectCallback, DWCi_GPConnect, DWCi_RemoteLogin, DWCi_RemoteLoginProcess, DWCi_GPGetInfoCallback, DWCi_CheckLogin, DWCi_GetAuthInfo, DWCi_GetLoginTicket
 * address:  0x0216A1F4
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWCi_Auth_IsConsoleUserIdAuthentic  0x02178F30  arm  ov009
 *   gDwcLoginControl  0x021AA874  data
 *   DWCi_IsError  0x02059F38  arm
 *   gpProcess  0x02185948  arm  ov009
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv  0x0209C00C  arm
 *   DWCi_SetError  0x02059F54  arm
 *   DWCi_Auth_IsFinished  0x02178E70  arm  ov009
 *   DWCi_Auth_AbortAuthentication  0x02178DA4  arm  ov009
 *   DWCi_Auth_ShutdownAuthentication  0x02178EF4  arm  ov009
 *   DWCi_Np_GetConsoleIdPrefix  0x02167E94  arm  ov009
 *   DWCi_Np_GetConsoleId  0x02167E88  arm  ov009
 *   OS_SNPrintf  0x02084F80  arm
 *   gpSetInfosA  0x02185CB4  arm  ov009
 *   DWCi_Auth_GetConsoleUserId  0x02178F00  arm  ov009
 *   DWCi_Acc_U64ToString32  0x02059408  arm
 *   DWCi_Np_GetAppGameName  0x02167EA0  arm  ov009
 *   DWCi_GPSetServerStatus  0x0216F20C  arm  ov009
 *   DWCi_GT2Startup  0x0216BA4C  arm  ov009
 *   DWCi_SetMatchmakeProfileId  0x02176AA8  arm  ov009
 *   DWCi_RegisterMatchmakeKeys  0x02176ABC  arm  ov009
 *   gpGetInfo  0x02185BD8  arm  ov009
 *   gpConnectPreAuthenticatedA  0x021859C0  arm  ov009
 *   DWCi_Acc_IsAuthentic  0x020596C8  arm
 *   DWCi_Acc_LoginIdToUserName  0x02059474  arm
 *   DWCi_Acc_GetUserId  0x02059084  arm
 *   DWCi_Acc_IsValidLoginId  0x020596B0  arm
 *   DWCi_Acc_CheckConsoleUserId  0x02059644  arm
 *   DWCi_Acc_CreateTempLoginId  0x02059588  arm
 *   OS_GetTick     0x020870D0  arm
 *   DWCi_Acc_SetPlayerId  0x020590F0  arm
 *   DWCi_Auth_StartAuthentication  0x02178D14  arm  ov009
 *   DWC_Alloc  0x0205A16C  arm
 *   DWC_Free  0x0205A1B0  arm
 *   DWCi_Auth_ProcessAuthentication  0x02178DB4  arm  ov009
 *   DWCi_Auth_IsSucceeded  0x02178E80  arm  ov009
 *   DWCi_Auth_GetGameSpyToken  0x02178EA0  arm  ov009
 *   DWCi_Acc_SetUserId  0x020590C8  arm
 *   DWCi_Auth_GetErrorCode  0x02178E90  arm  ov009
 *   gpDisconnect  0x02185ACC  arm  ov009
 *   strcmp         0x020948E0  arm
 *   DWCi_Acc_SetLoginIdToUserData  0x020597F0  arm
 *   @16552  0x021A201C  data
 *   gpGetLoginTicket  0x02186618  arm  ov009
 */
#include "../sdk_dwc.h"
#include "dwc_login_types.h"
#include "dwc_auth_interface.h"
#include "../arm9/dwc_memfunc.h"

void DWCi_LoginInit(DWCstLoginControl *logcnt, DWCstAccUserData *userdata, void **pGpObj, int productID, u32 gamecode, u16 *playerName, void (*callback)(int, int, void *), void *param);
int DWCi_LoginAsync(void);
void DWCi_LoginProcess(void);
DWCstAccUserData *DWCi_GetUserData(void);
void DWCi_StopLogin(int error, int errorCode);
void DWCi_ShutdownLogin(void);
void DWCi_CloseLogin(void);
static int DWCi_HandleGPError(int result);
void DWCi_GPConnectCallback(void **pconnection, void *argp, void *unused);
void DWCi_GPConnect(GPCallback callback, int next_state);
int DWCi_RemoteLogin(void);
void DWCi_RemoteLoginProcess(void);
void DWCi_GPGetInfoCallback(void **pconnection, void *argp, void *unused);
int DWCi_CheckLogin(void);
int DWCi_GetAuthInfo(char **authToken, char **partnerChallenge);
int DWCi_GetLoginTicket(char *loginTicket);











/*
 * sdk:      DWCi_LoginInit (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
void DWCi_LoginInit(DWCstLoginControl *logcnt, DWCstAccUserData *userdata, void **pGpObj, int productID, u32 gamecode, u16 *playerName, void (*callback)(int, int, void *), void *param)
{
	gDwcLoginControl = logcnt;
	MI_CpuFill8(gDwcLoginControl, 0, 0x260);
	gDwcLoginControl->connection = pGpObj;
	gDwcLoginControl->state = 0;
	gDwcLoginControl->productID = productID;
	gDwcLoginControl->gamecode = gamecode;
	gDwcLoginControl->playerName = playerName;
	gDwcLoginControl->callback = callback;
	gDwcLoginControl->param = param;
	gDwcLoginControl->userdata = userdata;
	DWCi_Auth_IsConsoleUserIdAuthentic();
}












/*
 * sdk:      DWCi_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int DWCi_LoginAsync(void)
{
	if (!DWCi_RemoteLogin())
		return 0;
	gDwcLoginControl->state = 1;
	gDwcLoginControl->connectFlag = 0;
	return 1;
}











void DWCi_LoginProcess(void)
{
	u64 elapsed;

	if (gDwcLoginControl == 0)
		return;
	if (DWCi_IsError())
		return;
	switch (gDwcLoginControl->state) {
	case 0:
	case 5:
		break;
	case 1:
		DWCi_RemoteLoginProcess();
		break;
	case 2:
	case 3:
	case 4:
		if (gDwcLoginControl->connection != 0 && *gDwcLoginControl->connection != 0)
			gpProcess(gDwcLoginControl->connection);
		if (gDwcLoginControl->connectFlag != 0) {
			elapsed = OS_GetTick() - gDwcLoginControl->tick;
			if (elapsed * 64 / 0x82ea > 60000) {
				DWCi_StopLogin(6, -61070);
				gDwcLoginControl->connectFlag = 0;
			}
		}
		break;
	}
}










DWCstAccUserData *DWCi_GetUserData(void)
{
    DWCstLoginControl *p = gDwcLoginControl;

    return p != 0 ? p->userdata : 0;
}










/*
 * sdk:      DWCi_StopLogin (dwc_login.o)
 *
 * Extra open callee of DWCi_HandleGPError (0x0216BD04).
 */
void DWCi_StopLogin(int error, int errorCode)
{
    if (gDwcLoginControl == 0 || error == 0) return;
    DWCi_SetError(error, errorCode);
    if (gDwcLoginControl->callback != 0) {
        gDwcLoginControl->callback(error, 0, gDwcLoginControl->param);
    }
    DWCi_CloseLogin();
}










/*
 * Clears the word at 0x021AA874 after DWCi_Auth_AbortAuthentication when DWCi_Auth_IsFinished reports zero.
 */
void DWCi_ShutdownLogin(void)
{
    if (DWCi_Auth_IsFinished() == 0) DWCi_Auth_AbortAuthentication();
    gDwcLoginControl = 0;
}










/*
 * sdk:      DWCi_CloseLogin (dwc_login.o)
 *
 * Extra open callee of DWCi_StopLogin (0x0216A3B8).
 */
void DWCi_CloseLogin(void)
{
    if (gDwcLoginControl == 0) return;
    DWCi_Auth_ShutdownAuthentication();
    gDwcLoginControl->state = 0;
    gDwcLoginControl->connectFlag = 0;
}










/*
 * sdk:      DWCi_HandleGPError (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
static int DWCi_HandleGPError(int result)
{
	int dwcError;
	int errorCode;

	if (result == 0)
		return 0;
	switch (result) {
	case 1:
		dwcError = 9;
		errorCode = -1;
		break;
	case 2:
		dwcError = 9;
		errorCode = -2;
		break;
	case 3:
		dwcError = 6;
		errorCode = -10;
		break;
	case 4:
		dwcError = 6;
		errorCode = -20;
		break;
	}
	DWCi_StopLogin(dwcError, errorCode - 61000);
	return result;
}








void DWCi_GPConnectCallback(void **pconnection, void *argp, void *unused)
{
    GPConnectResponseArg *arg = (GPConnectResponseArg *)argp;
    int gpResult;
    char firstname[31];
    char aimname[51];

    gDwcLoginControl->connectFlag = 0;

    OS_SNPrintf(firstname, sizeof(firstname), "%s:%016llu", DWCi_Np_GetConsoleIdPrefix(), DWCi_Np_GetConsoleId());
    gpResult = gpSetInfosA(pconnection, 0x704, firstname);
    if (DWCi_HandleGPError(gpResult))
        return;

    DWCi_Acc_U64ToString32(DWCi_Auth_GetConsoleUserId(), 43, aimname);
    gpResult = gpSetInfosA(pconnection, 0x717, aimname);
    if (DWCi_HandleGPError(gpResult))
        return;

    gpResult = gpSetInfosA(pconnection, 0x708, DWCi_Np_GetAppGameName());
    if (DWCi_HandleGPError(gpResult))
        return;

    if (arg->result == 0) {
        if (gDwcLoginControl->state == 2) {
            if (gDwcLoginControl->userdata->gs_profile_id == arg->profile) {
                gDwcLoginControl->state = 5;
                gpResult = DWCi_GPSetServerStatus(1);
                if (DWCi_HandleGPError(gpResult))
                    return;
                gDwcLoginControl->callback(0, arg->profile, gDwcLoginControl->param);
                if (DWCi_GT2Startup())
                    return;
                DWCi_SetMatchmakeProfileId(arg->profile);
                DWCi_RegisterMatchmakeKeys();
            } else {
                DWCi_StopLogin(6, -60000);
            }
        } else if (gDwcLoginControl->state == 3) {
            gpResult = gpGetInfo(pconnection, arg->profile, 0, 0, DWCi_GPGetInfoCallback, 0);
            DWCi_HandleGPError(gpResult);
        }
    } else {
        DWCi_HandleGPError(arg->result);
    }
}







void DWCi_GPConnect(GPCallback callback, int next_state)
{
	int gpResult;
	u64 tick;

	tick = OS_GetTick();
	gDwcLoginControl->tick = tick;
	gDwcLoginControl->connectFlag = 1;
	gpResult = gpConnectPreAuthenticatedA(gDwcLoginControl->connection, gDwcLoginControl->authToken, gDwcLoginControl->partnerChallenge, 1, 0, callback, 0);
	if (DWCi_HandleGPError(gpResult) == 0)
		gDwcLoginControl->state = next_state;
}






int DWCi_RemoteLogin(void)
{
    u64 userid;
    if (DWCi_Acc_IsAuthentic(gDwcLoginControl->userdata)) {
        DWCi_Acc_LoginIdToUserName(&gDwcLoginControl->userdata->authentic, gDwcLoginControl->userdata->gamecode, gDwcLoginControl->username);
        userid = DWCi_Acc_GetUserId(&gDwcLoginControl->userdata->authentic);
    } else {
        if (!DWCi_Acc_IsValidLoginId(&gDwcLoginControl->loginId)) {
            if (DWCi_Acc_CheckConsoleUserId(&gDwcLoginControl->userdata->pseudo))
                gDwcLoginControl->loginId = gDwcLoginControl->userdata->pseudo;
            else
                DWCi_Acc_CreateTempLoginId(&gDwcLoginControl->loginId);
        } else {
            DWCi_Acc_SetPlayerId(&gDwcLoginControl->loginId, (u32)((OS_GetTick() * 0x5D588B656C078965ULL + 0x269EC3) >> 32));
        }
        DWCi_Acc_LoginIdToUserName(&gDwcLoginControl->loginId, gDwcLoginControl->gamecode, gDwcLoginControl->username);
        userid = 0;
    }
#ifdef __MWERKS__
    return DWCi_Auth_StartAuthentication(gDwcLoginControl->playerName, gDwcLoginControl->gsbrcd, userid, (DWCAuthAlloc)DWC_Alloc, (DWCAuthFree)DWC_Free);
#else
    return DWCi_Auth_StartAuthentication(gDwcLoginControl->playerName, gDwcLoginControl->gsbrcd, userid, DWC_AllocCallback, DWC_FreeCallback);
#endif
}





void DWCi_RemoteLoginProcess(void)
{
	long errorcode;

	DWCi_Auth_ProcessAuthentication();
	if (!DWCi_Auth_IsFinished())
		return;
	if (DWCi_Auth_IsSucceeded()) {
		DWCi_Auth_GetGameSpyToken(gDwcLoginControl->authToken, gDwcLoginControl->partnerChallenge);
		DWCi_Auth_ShutdownAuthentication();
		if (DWCi_Acc_IsAuthentic(gDwcLoginControl->userdata)) {
			DWCi_GPConnect(DWCi_GPConnectCallback, 2);
			return;
		}
		DWCi_Acc_SetUserId(&gDwcLoginControl->loginId, DWCi_Auth_GetConsoleUserId());
		DWCi_GPConnect(DWCi_GPConnectCallback, 3);
		return;
	}
	errorcode = DWCi_Auth_GetErrorCode();
	if (errorcode <= -29000)
		DWCi_StopLogin(9, errorcode);
	else
		DWCi_StopLogin(2, errorcode);
}




void DWCi_GPGetInfoCallback(void **pconnection, void *argp, void *unused)
{
    GPGetInfoResponseArg *arg = (GPGetInfoResponseArg *)argp;
    char pseudo_name2[21];
    char pseudo_name[21];
    char username[21];
    int gpResult;

    if (arg->result != 0)
        return;
    if (gDwcLoginControl->state == 3) {
        if (arg->lastname[0] == 0) {
            DWCi_Acc_LoginIdToUserName(&gDwcLoginControl->userdata->pseudo, gDwcLoginControl->gamecode, pseudo_name2);
            gpResult = gpSetInfosA(pconnection, 0x705, pseudo_name2);
            if (DWCi_HandleGPError(gpResult))
                return;
            gDwcLoginControl->state = 4;
            gpResult = gpGetInfo(pconnection, arg->profile, 0, 0, DWCi_GPGetInfoCallback, 0);
            DWCi_HandleGPError(gpResult);
        } else {
            gpDisconnect(pconnection);
            DWCi_RemoteLogin();
            gDwcLoginControl->state = 1;
        }
    } else if (gDwcLoginControl->state == 4) {
        DWCi_Acc_LoginIdToUserName(&gDwcLoginControl->userdata->pseudo, gDwcLoginControl->gamecode, pseudo_name);
        if (strcmp(arg->lastname, pseudo_name) == 0) {
            DWCi_Acc_LoginIdToUserName(&gDwcLoginControl->loginId, gDwcLoginControl->gamecode, username);
            DWCi_Acc_SetLoginIdToUserData(gDwcLoginControl->userdata, &gDwcLoginControl->loginId, arg->profile);
            gpDisconnect(pconnection);
            DWCi_GPConnect(DWCi_GPConnectCallback, 2);
        } else {
            gpResult = gpGetInfo(pconnection, arg->profile, 0, 0, DWCi_GPGetInfoCallback, 0);
            DWCi_HandleGPError(gpResult);
        }
    }
}



int DWCi_CheckLogin(void)
{
    DWCstLoginControl *p = gDwcLoginControl;

    if (p != 0 && p->state == 5) return 1;
    return 0;
}


/*
 * sdk:      DWCi_GetAuthInfo (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int DWCi_GetAuthInfo(char **authToken, char **partnerChallenge)
{
	if (!DWCi_CheckLogin())
		return 0;
	*authToken = gDwcLoginControl->authToken;
	*partnerChallenge = gDwcLoginControl->partnerChallenge;
	return 1;
}



/*
 * sdk:      DWCi_GetLoginTicket (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int DWCi_GetLoginTicket(char *loginTicket)
{
	if (!DWCi_CheckLogin())
		return 0;
	if (gpGetLoginTicket(gDwcLoginControl->connection, loginTicket) == 0)
		return 1;
	return 0;
}
