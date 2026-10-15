/*
 * function: DWCi_GetAuthInfo
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
 *   DWCi_CheckLogin  0x0216AA70  arm  ov009
 *   gDwcLoginControl  0x021AA874  data
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

extern LoginCnt *gDwcLoginControl;


extern int DWCi_CheckLogin(void);

int DWCi_GetAuthInfo(char **authToken, char **partnerChallenge)
{
	if (!DWCi_CheckLogin())
		return 0;
	*authToken = gDwcLoginControl->authToken;
	*partnerChallenge = gDwcLoginControl->partnerChallenge;
	return 1;
}
