/*
 * function: func_0216AA9C
 * address:  0x0216AA9C
 * packet:   pkt_ov009_0216AA9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetAuthInfo (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   g_021AA874  0x021AA874  data
 */

typedef struct LoginCnt {
	void **connection;
	int state;
	unsigned char pad0[0x28];
	int a30;
	unsigned int tickLo;
	unsigned int tickHi;
	unsigned char pad1[0xc];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt;

extern LoginCnt *g_021AA874;


extern int func_0216AA70(void);

int func_0216AA9C(char **authToken, char **partnerChallenge)
{
	if (!func_0216AA70())
		return 0;
	*authToken = g_021AA874->authToken;
	*partnerChallenge = g_021AA874->partnerChallenge;
	return 1;
}
