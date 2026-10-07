/*
 * file:     unit_0216A1F4_p01.c
 * unit:     yes
 * function: func_0216A1F4, func_0216A278
 * address:  0x0216A1F4
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02178F30  0x02178F30  arm  ov009
 *   g_021AA874  0x021AA874  data
 *   func_0216A6F4  0x0216A6F4  arm  ov009
 */
typedef struct LoginCnt_0216A1F4 {
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
} LoginCnt_0216A1F4;

typedef struct LoginCnt_0216A278 {
	void *connection;
	int state;
	unsigned char pad0[0x28];
	int a30;
	unsigned long long tick;
	unsigned char pad1[0x10];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt_0216A278;

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_02178F30(void);
extern int func_0216A6F4(void);
void func_0216A1F4(LoginCnt_0216A1F4 *logcnt, void *userdata, void **pGpObj, int productID, unsigned long gamecode, unsigned short *playerName, void *callback, void *param);
int func_0216A278(void);
extern LoginCnt_0216A1F4 *g_021AA874;


/*
 * sdk:      DWCi_LoginInit (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
void func_0216A1F4(LoginCnt_0216A1F4 *logcnt, void *userdata, void **pGpObj, int productID, unsigned long gamecode, unsigned short *playerName, void *callback, void *param)
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


/*
 * sdk:      DWCi_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int func_0216A278(void)
{
	if (!func_0216A6F4())
		return 0;
	g_021AA874->state = 1;
	g_021AA874->a30 = 0;
	return 1;
}
