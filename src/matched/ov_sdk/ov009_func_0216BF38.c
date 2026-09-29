/*
 * function: func_0216BF38
 * address:  0x0216BF38
 * packet:   pkt_ov009_0216BF38
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_LoginCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   func_0216BC84  0x0216BC84  arm  ov009
 *   func_0216909C  0x0216909C  arm  ov009
 *   g_021AA878  0x021AA878  data
 */

typedef struct DwcState {
	unsigned char pad0[0x24];
	int state;
	unsigned char pad1[0x3c];
	int profileID;
	unsigned char pad2[0x8];
	void (*loginCallback)(int, int, void *);
	void *loginParam;
	void *updateCallback;
	void *updateParam;
	unsigned char pad3[0x58];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
} DwcState;

typedef struct DwcGlobal {
	int lastSocketError;
	DwcState *st;
} DwcGlobal;

extern DwcGlobal g_021AA878;

extern void func_0216BC84(int state);
extern void func_0216909C(void);

void func_0216BF38(int error, int profileID)
{
	if (error == 0) {
		g_021AA878.st->profileID = profileID;
		func_0216BC84(3);
		func_0216909C();
	} else {
		func_0216BC84(0);
	}
	if (g_021AA878.st->loginCallback != 0)
		g_021AA878.st->loginCallback(error, profileID, g_021AA878.st->loginParam);
}
