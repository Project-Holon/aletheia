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
 *   func_02059F38  0x02059F38  arm
 *   func_02168D7C  0x02168D7C  arm  ov009
 *   func_02168DA4  0x02168DA4  arm  ov009
 *   DWCi_UpdateServersCallback  0x0216BF98  arm  ov009
 *   g_021AA878  0x021AA878  data
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

extern struct DwcGlobal g_021AA878;



extern int func_02059F38(void);
extern int func_02168D7C(void);
extern void func_02168DA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void DWCi_UpdateServersCallback(int error, int isChanged);

int DWC_UpdateServersAsync(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam)
{
	if (func_02059F38() || ((DwcState *)g_021AA878.st)->state < 3 || func_02168D7C())
		return 0;
	((DwcState *)g_021AA878.st)->updateCallback = updateCallback;
	((DwcState *)g_021AA878.st)->updateParam = updateParam;
	func_02168DA4((int)((DwcState *)g_021AA878.st)->updateBuf0, (int)((DwcState *)g_021AA878.st)->updateBuf1, (int)DWCi_UpdateServersCallback, 0, (int)statusCallback, (int)statusParam, (int)deleteCallback, (int)deleteParam);
	return 1;
}
