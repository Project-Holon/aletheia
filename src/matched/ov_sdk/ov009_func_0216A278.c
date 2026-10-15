/*
 * function: DWCi_LoginAsync
 * address:  0x0216A278
 * packet:   pkt_ov009_0216A278
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   DWCi_RemoteLogin  0x0216A6F4  arm  ov009
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

extern int DWCi_RemoteLogin(void);

int DWCi_LoginAsync(void)
{
	if (!DWCi_RemoteLogin())
		return 0;
	gDwcLoginControl->state = 1;
	gDwcLoginControl->a30 = 0;
	return 1;
}
