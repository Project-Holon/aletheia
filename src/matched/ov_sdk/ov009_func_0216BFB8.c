/*
 * function: DWCi_MatchedCallback
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
 *   DWCi_SetState  0x0216BC84  arm  ov009
 *   func_0216EC18  0x0216EC18  arm  ov009
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
	unsigned char pad4[0x694];
	int a96c;
	unsigned char pad5[0x195];
	unsigned char b05;
} DwcState;

typedef struct DwcGlobal DwcGlobal;

extern struct DwcGlobal gDwcGlobalState;

extern void DWCi_SetState(int state);
extern void func_0216EC18(void);

void DWCi_MatchedCallback(int error, int cancel, int self, int isServer, int index)
{
	if (error == 0 && cancel != 0) {
		if (((DwcState *)gDwcGlobalState.st)->a96c == 0) {
			DWCi_SetState(3);
			func_0216EC18();
		}
	} else if (error == 0) {
		DWCi_SetState(5);
	}
	if (((DwcState *)gDwcGlobalState.st)->b05 == 0)
		((void (*)(int, int, int, int, int, void *))((DwcState *)gDwcGlobalState.st)->matchedCallback)(error, cancel, self, isServer, index, ((DwcState *)gDwcGlobalState.st)->matchedParam);
	if (error != 0 && gDwcGlobalState.st != 0 && (unsigned int)(((DwcState *)gDwcGlobalState.st)->state - 4) <= 1)
		DWCi_SetState(3);
}
