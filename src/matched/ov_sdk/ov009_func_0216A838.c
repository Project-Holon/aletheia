/*
 * function: DWCi_RemoteLoginProcess
 * address:  0x0216A838
 * packet:   pkt_ov009_0216A838
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RemoteLoginProcess (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   DWCi_Auth_ProcessAuthentication  0x02178DB4  arm  ov009
 *   DWCi_Auth_IsFinished  0x02178E70  arm  ov009
 *   DWCi_Auth_IsSucceeded  0x02178E80  arm  ov009
 *   DWCi_Auth_GetGameSpyToken  0x02178EA0  arm  ov009
 *   DWCi_Auth_ShutdownAuthentication  0x02178EF4  arm  ov009
 *   func_020596C8  0x020596C8  arm
 *   DWCi_GPConnect  0x0216A68C  arm  ov009
 *   DWCi_Auth_GetConsoleUserId  0x02178F00  arm  ov009
 *   func_020590C8  0x020590C8  arm
 *   DWCi_Auth_GetErrorCode  0x02178E90  arm  ov009
 *   DWCi_StopLogin  0x0216A3B8  arm  ov009
 *   DWCi_GPConnectCallback  0x0216A4D4  arm  ov009
 *   gDwcLoginControl  0x021AA874  data
 */

#pragma pack(4)
typedef struct LoginCnt {
	void **connection;
	int state;
	int productID;
	unsigned long gamecode;
	unsigned short *playerName;
	void *callback;
	void *param;
	void *userdata;
	unsigned char pad0[0x10];
	int timerActive;
	unsigned long long tick;
	unsigned char loginId[12];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt;
#pragma pack()

extern LoginCnt *gDwcLoginControl;

extern void DWCi_Auth_ProcessAuthentication(void);
extern int DWCi_Auth_IsFinished(void);
extern int DWCi_Auth_IsSucceeded(void);
extern void DWCi_Auth_GetGameSpyToken(char *authtoken, char *partnerchallenge);
extern void DWCi_Auth_ShutdownAuthentication();
extern int func_020596C8(void *userdata);
extern void DWCi_GPConnect(void *callback, int next_state);
extern unsigned long long DWCi_Auth_GetConsoleUserId(void);
extern void func_020590C8(void *loginId, unsigned long long userid);
extern int DWCi_Auth_GetErrorCode(void);
extern void DWCi_StopLogin(int error, int errorCode);
struct GPConnectResponseArg;
extern void DWCi_GPConnectCallback(void **pconnection, struct GPConnectResponseArg *arg);

void DWCi_RemoteLoginProcess(void)
{
	long errorcode;

	DWCi_Auth_ProcessAuthentication();
	if (!DWCi_Auth_IsFinished())
		return;
	if (DWCi_Auth_IsSucceeded()) {
		DWCi_Auth_GetGameSpyToken(gDwcLoginControl->authToken, gDwcLoginControl->partnerChallenge);
		DWCi_Auth_ShutdownAuthentication();
		if (func_020596C8(gDwcLoginControl->userdata)) {
			DWCi_GPConnect(DWCi_GPConnectCallback, 2);
			return;
		}
		func_020590C8(gDwcLoginControl->loginId, DWCi_Auth_GetConsoleUserId());
		DWCi_GPConnect(DWCi_GPConnectCallback, 3);
		return;
	}
	errorcode = DWCi_Auth_GetErrorCode();
	if (errorcode <= -29000)
		DWCi_StopLogin(9, errorcode);
	else
		DWCi_StopLogin(2, errorcode);
}
