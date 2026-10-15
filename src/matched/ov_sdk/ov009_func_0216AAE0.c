/*
 * function: DWCi_GetLoginTicket
 * address:  0x0216AAE0
 * packet:   pkt_ov009_0216AAE0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetLoginTicket (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   DWCi_CheckLogin  0x0216AA70  arm  ov009
 *   func_02186618  0x02186618  arm  ov009
 *   gDwcLoginControl  0x021AA874  data
 */

typedef struct LoginCnt {
	void *connection;
	int state;
	unsigned char pad0[0x28];
	int a30;
	unsigned long long tick;
	unsigned char pad1[0x10];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt;

extern LoginCnt *gDwcLoginControl;

extern int DWCi_CheckLogin(void);
extern int func_02186618(void **connection, char *loginTicket);

int DWCi_GetLoginTicket(char *loginTicket)
{
	if (!DWCi_CheckLogin())
		return 0;
	if (func_02186618(gDwcLoginControl->connection, loginTicket) == 0)
		return 1;
	return 0;
}
