/*
 * function: DWC_UpdateServersAsync
 * address:  0x0216B1E0
 * packet:   pkt_ov009_0216B1E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_UpdateServersAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   DWCi_IsError  0x02059F38  arm
 *   DWCi_IsServerUpdating  0x02168D7C  arm  ov009
 *   DWCi_UpdateServersAsync  0x02168DA4  arm  ov009
 *   DWCi_UpdateServersCallback  0x0216BF98  arm  ov009
 *   gDwcGlobalState  0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

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

typedef struct DwcGlobal DwcGlobal;

extern struct DwcGlobal gDwcGlobalState;



extern int DWCi_IsError(void);
extern int DWCi_IsServerUpdating(void);
extern void DWCi_UpdateServersAsync(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void DWCi_UpdateServersCallback(int error, int isChanged);

int DWC_UpdateServersAsync(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam)
{
	if (DWCi_IsError() || ((DwcState *)gDwcGlobalState.st)->state < 3 || DWCi_IsServerUpdating())
		return 0;
	((DwcState *)gDwcGlobalState.st)->updateCallback = updateCallback;
	((DwcState *)gDwcGlobalState.st)->updateParam = updateParam;
	DWCi_UpdateServersAsync((int)((DwcState *)gDwcGlobalState.st)->updateBuf0, (int)((DwcState *)gDwcGlobalState.st)->updateBuf1, (int)DWCi_UpdateServersCallback, 0, (int)statusCallback, (int)statusParam, (int)deleteCallback, (int)deleteParam);
	return 1;
}
