/*
 * function: DWCi_LoginCallback
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
 *   DWCi_SetState  0x0216BC84  arm  ov009
 *   DWCi_InitGPProcessCount  0x0216909C  arm  ov009
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

extern void DWCi_SetState(int state);
extern void DWCi_InitGPProcessCount(void);

void DWCi_LoginCallback(int error, int profileID)
{
	if (error == 0) {
		((DwcState *)gDwcGlobalState.st)->profileID = profileID;
		DWCi_SetState(3);
		DWCi_InitGPProcessCount();
	} else {
		DWCi_SetState(0);
	}
	if (((DwcState *)gDwcGlobalState.st)->loginCallback != 0)
		((DwcState *)gDwcGlobalState.st)->loginCallback(error, profileID, ((DwcState *)gDwcGlobalState.st)->loginParam);
}
