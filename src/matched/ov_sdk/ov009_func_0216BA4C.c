/*
 * function: DWCi_GT2Startup
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
 *   DWCi_HandleGT2Error  0x0216BE00  arm  ov009
 *   gt2Listen  0x02195B20  arm  ov009
 *   gt2SetUnrecognizedMessageCallback  0x02195E68  arm  ov009
 *   DWCi_GT2SocketErrorCallback  0x0216C7A8  arm  ov009
 *   func_0216E5B0  0x0216E5B0  arm  ov009
 *   func_0216E4C0  0x0216E4C0  arm  ov009
 *   g_021AA878  0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

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

typedef struct DwcGlobal DwcGlobal;

extern struct DwcGlobal g_021AA878;

extern unsigned long func_021685CC(unsigned long max);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_02195AB4(void **socket, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void *callback);
extern int DWCi_HandleGT2Error(int result);
extern void gt2Listen(int *p, int v);
extern void gt2SetUnrecognizedMessageCallback(int *p, int v);
extern void DWCi_GT2SocketErrorCallback(void *socket);
extern void func_0216E5B0();
extern int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);

int DWCi_GT2Startup(void)
{
	int gt2Result;
	unsigned short baseport;

	if (((DwcState *)g_021AA878.st)->gt2Socket != 0)
		return 0;
	baseport = func_021685CC(0x4000) + 0xc000;
	gt2Result = func_02195AB4(&((DwcState *)g_021AA878.st)->gt2Socket, func_02198620(0, baseport, 0), ((DwcState *)g_021AA878.st)->outSize, ((DwcState *)g_021AA878.st)->inSize, DWCi_GT2SocketErrorCallback);
	if (DWCi_HandleGT2Error(gt2Result))
		return gt2Result;
	gt2Listen(((DwcState *)g_021AA878.st)->gt2Socket, (int)func_0216E5B0);
	gt2SetUnrecognizedMessageCallback(((DwcState *)g_021AA878.st)->gt2Socket, (int)func_0216E4C0);
	return gt2Result;
}
