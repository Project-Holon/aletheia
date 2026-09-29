/*
 * function: func_0216A68C
 * address:  0x0216A68C
 * packet:   pkt_ov009_0216A68C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPConnect (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   func_021859C0  0x021859C0  arm  ov009
 *   func_0216A460  0x0216A460  arm  ov009
 *   g_021AA874  0x021AA874  data
 */

#pragma pack(4)
typedef struct LoginCnt {
	void **connection;
	int state;
	unsigned char pad0[0x28];
	int a30;
	unsigned long long tick;
	unsigned char pad1[0xc];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt;
#pragma pack()

extern LoginCnt *g_021AA874;


extern unsigned long long func_020870D0(void);
extern int func_021859C0(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, void *callback, void *param);
extern int func_0216A460(int result);

void func_0216A68C(void *callback, int next_state)
{
	int gpResult;
	unsigned long long tick;

	tick = func_020870D0();
	g_021AA874->tick = tick;
	g_021AA874->a30 = 1;
	gpResult = func_021859C0(g_021AA874->connection, g_021AA874->authToken, g_021AA874->partnerChallenge, 1, 0, callback, 0);
	if (func_0216A460(gpResult) == 0)
		g_021AA874->state = next_state;
}
