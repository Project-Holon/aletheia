/*
 * file:     unit_0216A1F4.c
 * unit:     yes
 * function: func_0216A1F4, func_0216A278, func_0216A2B0, func_0216A39C, func_0216A3B8, func_0216A404, func_0216A42C, func_0216A460, func_0216A4D4, func_0216A68C, func_0216A6F4, func_0216A838, func_0216A8F4, func_0216AA70, func_0216AA9C, func_0216AAE0
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
 *   func_02178F30  0x02178F30  arm  ov009
 *   g_021AA874  0x021AA874  data
 *   func_02059F38  0x02059F38  arm
 *   func_02185948  0x02185948  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv  0x0209C00C  arm
 *   func_02059F54  0x02059F54  arm
 *   func_02178E70  0x02178E70  arm  ov009
 *   DWCi_Auth_AbortAuthentication  0x02178DA4  arm  ov009
 *   DWCi_Auth_ShutdownAuthentication  0x02178EF4  arm  ov009
 *   DWCi_Np_GetConsoleIdPrefix  0x02167E94  arm  ov009
 *   func_02167E88  0x02167E88  arm  ov009
 *   func_02084F80  0x02084F80  arm
 *   func_02185CB4  0x02185CB4  arm  ov009
 *   func_02178F00  0x02178F00  arm  ov009
 *   func_02059408  0x02059408  arm
 *   func_02167EA0  0x02167EA0  arm  ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   DWCi_GT2Startup  0x0216BA4C  arm  ov009
 *   func_02176AA8  0x02176AA8  arm  ov009
 *   func_02176ABC  0x02176ABC  arm  ov009
 *   func_02185BD8  0x02185BD8  arm  ov009
 *   func_021859C0  0x021859C0  arm  ov009
 *   func_020596C8  0x020596C8  arm
 *   func_02059474  0x02059474  arm
 *   func_02059084  0x02059084  arm
 *   func_020596B0  0x020596B0  arm
 *   func_02059644  0x02059644  arm
 *   func_02059588  0x02059588  arm
 *   OS_GetTick     0x020870D0  arm
 *   DWCi_Acc_SetPlayerId  0x020590F0  arm
 *   func_02178D14  0x02178D14  arm  ov009
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_02178DB4  0x02178DB4  arm  ov009
 *   func_02178E80  0x02178E80  arm  ov009
 *   func_02178EA0  0x02178EA0  arm  ov009
 *   func_020590C8  0x020590C8  arm
 *   func_02178E90  0x02178E90  arm  ov009
 *   func_02185ACC  0x02185ACC  arm  ov009
 *   strcmp         0x020948E0  arm
 *   func_020597F0  0x020597F0  arm
 *   @16552  0x021A201C  data
 *   func_02186618  0x02186618  arm  ov009
 */
#include "dwc_login_types.h"

void func_0216A1F4(DWCstLoginControl *logcnt, DWCstAccUserData *userdata, void **pGpObj, int productID, u32 gamecode, u16 *playerName, void (*callback)(int, int, void *), void *param);
int func_0216A278(void);
void func_0216A2B0(void);
DWCstAccUserData *func_0216A39C(void);
void func_0216A3B8(int error, int errorCode);
void func_0216A404(void);
void func_0216A42C(void);
int func_0216A460(int result);
void func_0216A4D4(void **pconnection, void *argp, void *unused);
void func_0216A68C(GPCallback callback, int next_state);
int func_0216A6F4(void);
void func_0216A838(void);
void func_0216A8F4(void **pconnection, void *argp, void *unused);
int func_0216AA70(void);
int func_0216AA9C(char **authToken, char **partnerChallenge);
int func_0216AAE0(char *loginTicket);











/*
 * sdk:      DWCi_LoginInit (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
void func_0216A1F4(DWCstLoginControl *logcnt, DWCstAccUserData *userdata, void **pGpObj, int productID, u32 gamecode, u16 *playerName, void (*callback)(int, int, void *), void *param)
{
	g_021AA874 = logcnt;
	MI_CpuFill8(g_021AA874, 0, 0x260);
	g_021AA874->connection = pGpObj;
	g_021AA874->state = 0;
	g_021AA874->productID = productID;
	g_021AA874->gamecode = gamecode;
	g_021AA874->playerName = playerName;
	g_021AA874->callback = callback;
	g_021AA874->param = param;
	g_021AA874->userdata = userdata;
	func_02178F30();
}












/*
 * sdk:      DWCi_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int func_0216A278(void)
{
	if (!func_0216A6F4())
		return 0;
	g_021AA874->state = 1;
	g_021AA874->connectFlag = 0;
	return 1;
}











void func_0216A2B0(void)
{
	u64 elapsed;

	if (g_021AA874 == 0)
		return;
	if (func_02059F38())
		return;
	switch (g_021AA874->state) {
	case 0:
	case 5:
		break;
	case 1:
		func_0216A838();
		break;
	case 2:
	case 3:
	case 4:
		if (g_021AA874->connection != 0 && *g_021AA874->connection != 0)
			func_02185948(g_021AA874->connection);
		if (g_021AA874->connectFlag != 0) {
			elapsed = func_020870D0() - g_021AA874->tick;
			if (elapsed * 64 / 0x82ea > 60000) {
				func_0216A3B8(6, -61070);
				g_021AA874->connectFlag = 0;
			}
		}
		break;
	}
}










DWCstAccUserData *func_0216A39C(void)
{
    DWCstLoginControl *p = g_021AA874;

    return p != 0 ? p->userdata : 0;
}










/*
 * sdk:      DWCi_StopLogin (dwc_login.o)
 *
 * Extra open callee of DWCi_HandleGPError (0x0216BD04).
 */
void func_0216A3B8(int error, int errorCode)
{
    if (g_021AA874 == 0 || error == 0) return;
    func_02059F54(error, errorCode);
    if (g_021AA874->callback != 0) {
        g_021AA874->callback(error, 0, g_021AA874->param);
    }
    func_0216A42C();
}










/*
 * Clears the word at 0x021AA874 after DWCi_Auth_AbortAuthentication when func_02178E70 reports zero.
 */
void func_0216A404(void)
{
    if (func_02178E70() == 0) DWCi_Auth_AbortAuthentication();
    g_021AA874 = 0;
}










/*
 * sdk:      DWCi_CloseLogin (dwc_login.o)
 *
 * Extra open callee of DWCi_StopLogin (0x0216A3B8).
 */
void func_0216A42C(void)
{
    if (g_021AA874 == 0) return;
    DWCi_Auth_ShutdownAuthentication();
    g_021AA874->state = 0;
    g_021AA874->connectFlag = 0;
}










/*
 * sdk:      DWCi_HandleGPError (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int func_0216A460(int result)
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
	func_0216A3B8(dwcError, errorCode - 61000);
	return result;
}








void func_0216A4D4(void **pconnection, void *argp, void *unused)
{
    GPConnectResponseArg *arg = (GPConnectResponseArg *)argp;
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







void func_0216A68C(GPCallback callback, int next_state)
{
	int gpResult;
	u64 tick;

	tick = func_020870D0();
	g_021AA874->tick = tick;
	g_021AA874->connectFlag = 1;
	gpResult = func_021859C0(g_021AA874->connection, g_021AA874->authToken, g_021AA874->partnerChallenge, 1, 0, callback, 0);
	if (func_0216A460(gpResult) == 0)
		g_021AA874->state = next_state;
}






int func_0216A6F4(void)
{
    u64 userid;
    if (func_020596C8(g_021AA874->userdata)) {
        func_02059474(&g_021AA874->userdata->authentic, g_021AA874->userdata->gamecode, g_021AA874->username);
        userid = func_02059084(&g_021AA874->userdata->authentic);
    } else {
        if (!func_020596B0(&g_021AA874->loginId)) {
            if (func_02059644(&g_021AA874->userdata->pseudo))
                g_021AA874->loginId = g_021AA874->userdata->pseudo;
            else
                func_02059588(&g_021AA874->loginId);
        } else {
            DWCi_Acc_SetPlayerId(&g_021AA874->loginId, (u32)((OS_GetTick() * 0x5D588B656C078965ULL + 0x269EC3) >> 32));
        }
        func_02059474(&g_021AA874->loginId, g_021AA874->gamecode, g_021AA874->username);
        userid = 0;
    }
    return func_02178D14(g_021AA874->playerName, g_021AA874->gsbrcd, userid, func_0205A16C, func_0205A1B0);
}





void func_0216A838(void)
{
	long errorcode;

	func_02178DB4();
	if (!func_02178E70())
		return;
	if (func_02178E80()) {
		func_02178EA0(g_021AA874->authToken, g_021AA874->partnerChallenge);
		DWCi_Auth_ShutdownAuthentication();
		if (func_020596C8(g_021AA874->userdata)) {
			func_0216A68C(func_0216A4D4, 2);
			return;
		}
		func_020590C8(&g_021AA874->loginId, func_02178F00());
		func_0216A68C(func_0216A4D4, 3);
		return;
	}
	errorcode = func_02178E90();
	if (errorcode <= -29000)
		func_0216A3B8(9, errorcode);
	else
		func_0216A3B8(2, errorcode);
}




void func_0216A8F4(void **pconnection, void *argp, void *unused)
{
    GPGetInfoResponseArg *arg = (GPGetInfoResponseArg *)argp;
    char pseudo_name2[21];
    char pseudo_name[21];
    char username[21];
    int gpResult;

    if (arg->result != 0)
        return;
    if (g_021AA874->state == 3) {
        if (arg->nick[0] == 0) {
            func_02059474(&g_021AA874->userdata->pseudo, g_021AA874->gamecode, pseudo_name2);
            gpResult = func_02185CB4(pconnection, 0x705, pseudo_name2);
            if (func_0216A460(gpResult))
                return;
            g_021AA874->state = 4;
            gpResult = func_02185BD8(pconnection, arg->profile, 0, 0, func_0216A8F4, 0);
            func_0216A460(gpResult);
        } else {
            func_02185ACC(pconnection);
            func_0216A6F4();
            g_021AA874->state = 1;
        }
    } else if (g_021AA874->state == 4) {
        func_02059474(&g_021AA874->userdata->pseudo, g_021AA874->gamecode, pseudo_name);
        if (strcmp(arg->nick, pseudo_name) == 0) {
            func_02059474(&g_021AA874->loginId, g_021AA874->gamecode, username);
            func_020597F0(g_021AA874->userdata, &g_021AA874->loginId, arg->profile);
            func_02185ACC(pconnection);
            func_0216A68C(func_0216A4D4, 2);
        } else {
            gpResult = func_02185BD8(pconnection, arg->profile, 0, 0, func_0216A8F4, 0);
            func_0216A460(gpResult);
        }
    }
}



int func_0216AA70(void)
{
    DWCstLoginControl *p = g_021AA874;

    if (p != 0 && p->state == 5) return 1;
    return 0;
}


/*
 * sdk:      DWCi_GetAuthInfo (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int func_0216AA9C(char **authToken, char **partnerChallenge)
{
	if (!func_0216AA70())
		return 0;
	*authToken = g_021AA874->authToken;
	*partnerChallenge = g_021AA874->partnerChallenge;
	return 1;
}



/*
 * sdk:      DWCi_GetLoginTicket (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int func_0216AAE0(char *loginTicket)
{
	if (!func_0216AA70())
		return 0;
	if (func_02186618(g_021AA874->connection, loginTicket) == 0)
		return 1;
	return 0;
}
