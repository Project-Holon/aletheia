/*
 * function: func_0216BA4C
 * address:  0x0216BA4C
 * packet:   pkt_ov009_0216BA4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GT2Startup (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   func_021685CC  0x021685CC  arm  ov009
 *   func_02198620  0x02198620  arm  ov009
 *   func_02195AB4  0x02195AB4  arm  ov009
 *   func_0216BE00  0x0216BE00  arm  ov009
 *   func_02195B20  0x02195B20  arm  ov009
 *   func_02195E68  0x02195E68  arm  ov009
 *   func_0216C7A8  0x0216C7A8  arm  ov009
 *   func_0216E5B0  0x0216E5B0  arm  ov009
 *   func_0216E4C0  0x0216E4C0  arm  ov009
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
	unsigned char pad3[0x58];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
} DwcState;

typedef struct DwcGlobal {
	int lastSocketError;
	DwcState *st;
} DwcGlobal;

extern DwcGlobal g_021AA878;

extern unsigned long func_021685CC(unsigned long max);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_02195AB4(void **socket, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void *callback);
extern int func_0216BE00(int result);
extern void func_02195B20(int *p, int v);
extern void func_02195E68(int *p, int v);
extern void func_0216C7A8(void *socket);
extern void func_0216E5B0();
extern int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);

int func_0216BA4C(void)
{
	int gt2Result;
	unsigned short baseport;

	if (g_021AA878.st->gt2Socket != 0)
		return 0;
	baseport = func_021685CC(0x4000) + 0xc000;
	gt2Result = func_02195AB4(&g_021AA878.st->gt2Socket, func_02198620(0, baseport, 0), g_021AA878.st->outSize, g_021AA878.st->inSize, func_0216C7A8);
	if (func_0216BE00(gt2Result))
		return gt2Result;
	func_02195B20(g_021AA878.st->gt2Socket, (int)func_0216E5B0);
	func_02195E68(g_021AA878.st->gt2Socket, (int)func_0216E4C0);
	return gt2Result;
}
