/*
 * function: func_0216A838
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
 *   func_02178DB4  0x02178DB4  arm  ov009
 *   func_02178E70  0x02178E70  arm  ov009
 *   func_02178E80  0x02178E80  arm  ov009
 *   func_02178EA0  0x02178EA0  arm  ov009
 *   func_02178EF4  0x02178EF4  arm  ov009
 *   func_020596C8  0x020596C8  arm
 *   func_0216A68C  0x0216A68C  arm  ov009
 *   func_02178F00  0x02178F00  arm  ov009
 *   func_020590C8  0x020590C8  arm
 *   func_02178E90  0x02178E90  arm  ov009
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   func_0216A4D4  0x0216A4D4  arm  ov009
 *   g_021AA874  0x021AA874  data
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

extern LoginCnt *g_021AA874;

extern void func_02178DB4(void);
extern int func_02178E70(void);
extern int func_02178E80(void);
extern void func_02178EA0(char *authtoken, char *partnerchallenge);
extern void func_02178EF4();
extern int func_020596C8(void *userdata);
extern void func_0216A68C(void *callback, int next_state);
extern unsigned long long func_02178F00(void);
extern void func_020590C8(void *loginId, unsigned long long userid);
extern int func_02178E90(void);
extern void func_0216A3B8(int error, int errorCode);
extern void func_0216A4D4(void **pconnection, void *arg);

void func_0216A838(void)
{
	long errorcode;

	func_02178DB4();
	if (!func_02178E70())
		return;
	if (func_02178E80()) {
		func_02178EA0(g_021AA874->authToken, g_021AA874->partnerChallenge);
		func_02178EF4();
		if (func_020596C8(g_021AA874->userdata)) {
			func_0216A68C(func_0216A4D4, 2);
			return;
		}
		func_020590C8(g_021AA874->loginId, func_02178F00());
		func_0216A68C(func_0216A4D4, 3);
		return;
	}
	errorcode = func_02178E90();
	if (errorcode <= -29000)
		func_0216A3B8(9, errorcode);
	else
		func_0216A3B8(2, errorcode);
}
