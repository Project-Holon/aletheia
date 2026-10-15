/*
 * function: DWC_ConnectToAnybodyAsync
 * address:  0x0216B284
 * packet:   pkt_ov009_0216B284
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ConnectToAnybodyAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   DWCi_IsError  0x02059F38  arm
 *   DWCi_ClearGT2ConnectionList  0x0216BB98  arm  ov009
 *   DWCi_SetState  0x0216BC84  arm  ov009
 *   DWCi_CustomCommonInit  0x0216C7E0  arm  ov009
 *   func_0216CF1C  0x0216CF1C  arm  ov009
 *   DWCi_MatchedCallback  0x0216BFB8  arm  ov009
 *   gDwcGlobalState  0x021AA878  data
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

extern struct DwcGlobal gDwcGlobalState;

extern int DWCi_IsError(void);
extern void DWCi_ClearGT2ConnectionList(void);
extern void DWCi_SetState(int state);
extern void DWCi_CustomCommonInit(unsigned char matchType);
extern void func_0216CF1C(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
extern void DWCi_MatchedCallback(int error, int cancel, int self, int isServer, int index);

int DWC_ConnectToAnybodyAsync(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (DWCi_IsError() || ((DwcState *)gDwcGlobalState.st)->state != 3)
		return 0;
	DWCi_ClearGT2ConnectionList();
	((DwcState *)gDwcGlobalState.st)->matchedCallback = matchedCallback;
	((DwcState *)gDwcGlobalState.st)->matchedParam = matchedParam;
	DWCi_SetState(4);
	DWCi_CustomCommonInit(0);
	func_0216CF1C(topology, maxEntry - 1, addFilter, DWCi_MatchedCallback, 0, newClientCallback, newClientParam, evalCallback, evalParam, attemptCallback, connectionUserData, attemptParam);
	return 1;
}
