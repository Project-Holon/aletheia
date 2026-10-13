/*
 * function: DWC_SetupGameServer
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
 *   DWCi_ClearGT2ConnectionList  0x0216BB98  arm  ov009
 *   DWCi_SetState  0x0216BC84  arm  ov009
 *   DWCi_CustomCommonInit  0x0216C7E0  arm  ov009
 *   DWCi_SetupGameServer  0x0216D138  arm  ov009
 *   DWCi_MatchedCallback  0x0216BFB8  arm  ov009
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
	void *matchedCallback;
	void *matchedParam;
	unsigned char pad3[0x50];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
} DwcState;

typedef struct DwcGlobal DwcGlobal;

extern struct DwcGlobal g_021AA878;

extern int func_02059F38(void);
extern void DWCi_ClearGT2ConnectionList(void);
extern void DWCi_SetState(int state);
extern void DWCi_CustomCommonInit(unsigned char matchType);
extern void DWCi_SetupGameServer(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
extern void DWCi_MatchedCallback(int error, int cancel, int self, int isServer, int index);

int DWC_SetupGameServer(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (func_02059F38() || ((DwcState *)g_021AA878.st)->state != 3)
		return 0;
	DWCi_ClearGT2ConnectionList();
	((DwcState *)g_021AA878.st)->matchedCallback = matchedCallback;
	((DwcState *)g_021AA878.st)->matchedParam = matchedParam;
	DWCi_SetState(4);
	DWCi_CustomCommonInit(2);
	DWCi_SetupGameServer(topology, (unsigned char)(maxEntry - 1), (int)DWCi_MatchedCallback, 0, (int)newClientCallback, (int)newClientParam, (int)attemptCallback, (int)connectionUserData, (int)attemptParam);
	return 1;
}
