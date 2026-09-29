/*
 * function: func_0216A2B0
 * address:  0x0216A2B0
 * packet:   pkt_ov009_0216A2B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_LoginProcess (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_0216A838  0x0216A838  arm  ov009
 *   func_02185948  0x02185948  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv  0x0209C00C  arm
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   g_021AA874  0x021AA874  data
 */

#pragma pack(4)
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
	int timerActive;
	unsigned long long tick;
	unsigned char loginId[12];
	char authToken[0x100];
	char partnerChallenge[0x100];
} LoginCnt;
#pragma pack()

extern LoginCnt *g_021AA874;

extern int func_02059F38(void);
extern void func_0216A838(void);
extern int func_02185948(void **connection);
extern unsigned long long func_020870D0(void);
extern void func_0216A3B8(int error, int errorCode);

void func_0216A2B0(void)
{
	unsigned long long elapsed;

	if (g_021AA874 == 0)
		return;
	if (func_02059F38())
		return;
	switch (g_021AA874->state) {
	case 0:
	case 5:
		break;
	case 1:
		func_0216A838();
		break;
	case 2:
	case 3:
	case 4:
		if (g_021AA874->connection != 0 && *g_021AA874->connection != 0)
			func_02185948(g_021AA874->connection);
		if (g_021AA874->timerActive != 0) {
			elapsed = func_020870D0() - g_021AA874->tick;
			if (elapsed * 64 / 0x82ea > 60000) {
				func_0216A3B8(6, -61070);
				g_021AA874->timerActive = 0;
			}
		}
		break;
	}
}
