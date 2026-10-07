/*
 * file:     unit_0216A1F4_p03.c
 * unit:     yes
 * function: func_0216AA9C, func_0216AAE0
 * address:  0x0216AA9C
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
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   g_021AA874  0x021AA874  data
 *   func_02186618  0x02186618  arm  ov009
 */
typedef struct LoginCnt_0216AA9C {
	void **connection;
	int state;
	unsigned char pad0[0x28];
	int a30;
	unsigned int tickLo;
	unsigned int tickHi;
	unsigned char pad1[0xc];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt_0216AA9C;

typedef struct LoginCnt_0216AAE0 {
	void *connection;
	int state;
	unsigned char pad0[0x28];
	int a30;
	unsigned long long tick;
	unsigned char pad1[0x10];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt_0216AAE0;

extern int func_0216AA70(void);
extern int func_02186618(void **connection, char *loginTicket);
int func_0216AA9C(char **authToken, char **partnerChallenge);
int func_0216AAE0(char *loginTicket);
extern LoginCnt_0216AA9C *g_021AA874;


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
