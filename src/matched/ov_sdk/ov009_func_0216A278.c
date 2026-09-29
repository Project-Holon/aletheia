/*
 * function: func_0216A278
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
 *   func_0216A6F4  0x0216A6F4  arm  ov009
 *   g_021AA874  0x021AA874  data
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

extern LoginCnt *g_021AA874;

extern int func_0216A6F4(void);

int func_0216A278(void)
{
	if (!func_0216A6F4())
		return 0;
	g_021AA874->state = 1;
	g_021AA874->a30 = 0;
	return 1;
}
