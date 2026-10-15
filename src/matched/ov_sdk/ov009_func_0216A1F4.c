/*
 * function: DWCi_LoginInit
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWCi_Auth_IsConsoleUserIdAuthentic  0x02178F30  arm  ov009
 *   gDwcLoginControl  0x021AA874  data
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

extern LoginCnt *gDwcLoginControl;


extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWCi_Auth_IsConsoleUserIdAuthentic(void);

void DWCi_LoginInit(LoginCnt *logcnt, void *userdata, void **pGpObj, int productID, unsigned long gamecode, unsigned short *playerName, void *callback, void *param)
{
	gDwcLoginControl = logcnt;
	MI_CpuFill8(gDwcLoginControl, 0, 0x260);
	gDwcLoginControl->connection = pGpObj;
	gDwcLoginControl->state = 0;
	gDwcLoginControl->productID = productID;
	gDwcLoginControl->gamecode = gamecode;
	gDwcLoginControl->playerName = playerName;
	gDwcLoginControl->callback = callback;
	gDwcLoginControl->param = param;
	gDwcLoginControl->userdata = userdata;
	DWCi_Auth_IsConsoleUserIdAuthentic();
}
