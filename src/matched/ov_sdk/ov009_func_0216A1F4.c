/*
 * function: func_0216A1F4
 * address:  0x0216A1F4
 * packet:   pkt_ov009_0216A1F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_LoginInit (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02178F30  0x02178F30  arm  ov009
 *   g_021AA874  0x021AA874  data
 */

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
	int a30;
	unsigned char pad1[0x14];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt;

extern LoginCnt *g_021AA874;


extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_02178F30(void);

void func_0216A1F4(LoginCnt *logcnt, void *userdata, void **pGpObj, int productID, unsigned long gamecode, unsigned short *playerName, void *callback, void *param)
{
	g_021AA874 = logcnt;
	func_02082BCC(g_021AA874, 0, 0x260);
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
