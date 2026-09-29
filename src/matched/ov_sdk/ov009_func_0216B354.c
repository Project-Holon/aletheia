/*
 * function: func_0216B354
 * address:  0x0216B354
 * packet:   pkt_ov009_0216B354
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SetupGameServer (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_0216BB98  0x0216BB98  arm  ov009
 *   func_0216BC84  0x0216BC84  arm  ov009
 *   func_0216C7E0  0x0216C7E0  arm  ov009
 *   func_0216D138  0x0216D138  arm  ov009
 *   func_0216BFB8  0x0216BFB8  arm  ov009
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
} DwcState;

typedef struct DwcGlobal {
	int lastSocketError;
	DwcState *st;
} DwcGlobal;

extern DwcGlobal g_021AA878;

extern int func_02059F38(void);
extern void func_0216BB98(void);
extern void func_0216BC84(int state);
extern void func_0216C7E0(unsigned char matchType);
extern void func_0216D138(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
extern void func_0216BFB8(int error, int cancel, int self, int isServer, int index);

int func_0216B354(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (func_02059F38() || g_021AA878.st->state != 3)
		return 0;
	func_0216BB98();
	g_021AA878.st->matchedCallback = matchedCallback;
	g_021AA878.st->matchedParam = matchedParam;
	func_0216BC84(4);
	func_0216C7E0(2);
	func_0216D138(topology, maxEntry - 1, func_0216BFB8, 0, newClientCallback, newClientParam, attemptCallback, connectionUserData, attemptParam);
	return 1;
}
