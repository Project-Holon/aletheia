/*
 * file:     unit_0216AB20_p07.c
 * unit:     yes
 * function: func_0216BC3C, func_0216BC84, func_0216BCA4, func_0216BCD0, func_0216BD04, func_0216BE00
 * address:  0x0216BC3C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02195E78  0x02195E78  arm  ov009
 *   g_021AA8A0  0x021AA8A0  data
 *   g_021AA878  0x021AA878  data
 *   func_02176410  0x02176410  arm  ov009
 *   func_02176164  0x02176164  arm  ov009
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   func_0216EB68  0x0216EB68  arm  ov009
 *   func_02168E50  0x02168E50  arm  ov009
 */
#include "../../matched/include/G_DwcGlobal.h"

typedef struct ConnData {
	unsigned char pad0;
	unsigned char aid;
} ConnData;

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

extern int func_02195E78(const int *p);
extern char *func_02176410(unsigned char aid);
extern int func_02176164(unsigned char aid);
extern void func_0216A3B8(int error, int errorCode);
extern void func_0216EB68(int error, int errorCode);
extern void func_02168E50(int error, int errorCode);
int func_0216BC3C(unsigned char aid);
void func_0216BC84(int v);
int DWCi_DeleteAID(unsigned char aid);
int func_0216BCD0(unsigned char *p, int n);
int func_0216BD04(int result);
int func_0216BE00(int result);
extern void *g_021AA8A0[];
extern struct DwcGlobal g_021AA878;


/*
 * sdk:      DWCi_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216BC3C(unsigned char aid)
{
	int i;

	for (i = 0; i < 0x20; i++) {
		if (g_021AA8A0[i] != 0) {
			if (aid == ((ConnData *)func_02195E78(g_021AA8A0[i]))->aid)
				return 1;
		}
	}
	return 0;
}


/*
 * Copies the +0x24 link of the current object to +0x28 and then sets the
 * +0x24 link to v.
 */
void func_0216BC84(int v)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    *(int *)(p + 0x28) = *(int *)(p + 0x24);
    p = *(char **)(((char *)&g_021AA878) + 4);
    *(int *)(p + 0x24) = v;
}


int DWCi_DeleteAID(unsigned char aid)
{
    char *pNodeInfo = func_02176410(aid);
    int profileID;

    if (pNodeInfo == 0) return 0;
    profileID = *(int *)pNodeInfo;
    func_02176164(aid);
    return profileID;
}

/*
 * Builds a bit mask over the first n bytes of the array: m |= 1 << p[i].
 */
int func_0216BCD0(unsigned char *p, int n)
{
    int m = 0;
    int i;

    for (i = 0; i < n; i++)
        m |= 1 << p[i];
    return m;
}


/*
 * sdk:      DWCi_HandleGPError (dwc_main.o)
 *
 * Extra open callee of DWCi_GPErrorCallback (0x0216C08C).
 */
int func_0216BD04(int result)
{
    int errorCode;
    int dwcError;

    if (result == 0) return 0;
    switch (result) {
    case 1: dwcError = 9; errorCode = -1; break;
    case 2: dwcError = 9; errorCode = -2; break;
    case 3: dwcError = 6; errorCode = -10; break;
    case 4: dwcError = 6; errorCode = -20; break;
    }
    switch (*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24)) {
    case 1:
        errorCode += (int)0xffff11b8;
        func_0216A3B8(dwcError, errorCode);
        break;
    case 2:
        errorCode += (int)0xffff11b8;
        if (*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x94) < 1)
            func_0216A3B8(dwcError, errorCode);
        break;
    case 4:
        errorCode += (int)0xfffec398;
        func_0216EB68(dwcError, errorCode);
        break;
    default:
        errorCode += (int)0xfffe9c88;
        break;
    }
    func_02168E50(dwcError, errorCode);
    return result;
}


/*
 * sdk:      DWCi_HandleGT2Error (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216BE00(int result)
{
	int dwcError;
	int errorCode;

	if (result == 0)
		return 0;
	switch (result) {
	case 1:
		dwcError = 9;
		errorCode = -1;
		break;
	case 2:
	case 5:
		dwcError = 0;
		errorCode = 0;
		result = 0;
		break;
	case 3:
		dwcError = 6;
		errorCode = -10;
		break;
	case 4:
		dwcError = 6;
		errorCode = -30;
		break;
	case 6:
		dwcError = 6;
		errorCode = -70;
		break;
	case 7:
		dwcError = 6;
		errorCode = -80;
		break;
	}
	if (dwcError != 0)
		func_0216A3B8(dwcError, errorCode - 67000);
	return result;
}
