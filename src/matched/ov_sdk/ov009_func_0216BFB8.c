/*
 * function: func_0216BFB8
 * address:  0x0216BFB8
 * packet:   pkt_ov009_0216BFB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MatchedCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   func_0216BC84  0x0216BC84  arm  ov009
 *   func_0216EC18  0x0216EC18  arm  ov009
 *   g_021AA878  0x021AA878  data
 */

typedef struct DwcState {
	void *gt2Socket;
	unsigned char pad0a[0x10];
	int outSize;
	int inSize;
	unsigned char pad0[0x8];
	int state;
	unsigned char pad1[0x3c];
	int profileID;
	unsigned char pad2[0x8];
	void (*loginCallback)(int, int, void *);
	void *loginParam;
	void *updateCallback;
	void *updateParam;
	void *matchedCallback;
	void *matchedParam;
	unsigned char pad3[0x50];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
	unsigned char pad4[0x694];
	int a96c;
	unsigned char pad5[0x195];
	unsigned char b05;
} DwcState;

typedef struct DwcGlobal {
	int lastSocketError;
	DwcState *st;
} DwcGlobal;

extern DwcGlobal g_021AA878;

extern void func_0216BC84(int state);
extern void func_0216EC18(void);

void func_0216BFB8(int error, int cancel, int self, int isServer, int index)
{
	if (error == 0 && cancel != 0) {
		if (g_021AA878.st->a96c == 0) {
			func_0216BC84(3);
			func_0216EC18();
		}
	} else if (error == 0) {
		func_0216BC84(5);
	}
	if (g_021AA878.st->b05 == 0)
		((void (*)(int, int, int, int, int, void *))g_021AA878.st->matchedCallback)(error, cancel, self, isServer, index, g_021AA878.st->matchedParam);
	if (error != 0 && g_021AA878.st != 0 && (unsigned int)(g_021AA878.st->state - 4) <= 1)
		func_0216BC84(3);
}
