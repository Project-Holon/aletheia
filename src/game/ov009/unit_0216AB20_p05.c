/*
 * file:     unit_0216AB20_p05.c
 * unit:     yes
 * function: func_0216BC3C, func_0216BC84, func_0216BCA4, func_0216BCD0, func_0216BD04, func_0216BE00, func_0216BEA4, func_0216BF38, func_0216BF98, func_0216BFB8, DWCi_GPErrorCallback, func_0216C0C4
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
 *   func_02059F38  0x02059F38  arm
 *   func_0216BAF4  0x0216BAF4  arm  ov009
 *   func_0216C230  0x0216C230  arm  ov009
 *   func_02195DC4  0x02195DC4  arm  ov009
 *   func_0216909C  0x0216909C  arm  ov009
 *   func_0216EC18  0x0216EC18  arm  ov009
 *   strlen         0x0209477C  arm
 *   memcmp         0x020923F0  arm
 *   strchr         0x02094A28  arm
 *   strncpy        0x02094860  arm
 *   strtoul        0x02095EAC  arm
 *   func_0216EAB8  0x0216EAB8  arm  ov009
 *   g_021A2030     0x021A2030  data
 *   g_021A2038     0x021A2038  data
 */
#include "../../matched/include/G_DwcGlobal.h"
#include "../../matched/include/G_DwcGlobal.h"
#include "../../matched/arm9_sdk/libc/string.h"

struct GTI2Connection;
typedef struct ConnData {
	unsigned char pad0;
	unsigned char aid;
} ConnData;

typedef struct DwcState {
	void *gt2Socket;
	unsigned char pad4[0x10];
	int outSize;
	int inSize;
	unsigned char pad1c[0x8];
	int state;
	unsigned char pad28[0x3c];
	int profileID;
	unsigned char pad68[0x8];
	void (*loginCallback)(int, int, void *);
	void *loginParam;
	void *updateCallback;
	void *updateParam;
	void *matchedCallback;
	void *matchedParam;
	unsigned char pad88[0x50];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
	unsigned char pad2d8[0x694];
	int a96c;
	unsigned char pad970[0x195];
	unsigned char b05;
	unsigned char padb06[0x2];
} DwcState;

typedef struct DwcGlobal DwcGlobal;

typedef unsigned char u8;

typedef struct {
    int profile;
    int pad4;
    char *message;
} GPRecvBuddyMessageArg;

typedef struct {
    char pad0[0x24];
    int state;
    char pad28[0x33c];
    volatile u8 mode;   /* volatile: the image reloads it for each compare */
} Ctl;

extern int func_02195E78(const int *p);
extern char *func_02176410(unsigned char aid);
extern int func_02176164(unsigned char aid);
extern void func_0216A3B8(int error, int errorCode);
extern void func_0216EB68(int error, int errorCode);
extern void func_02168E50(int error, int errorCode);
extern int func_02059F38(void);
extern int func_0216BAF4(int aid);
extern void func_0216C230(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
extern void func_02195DC4(int conn);
extern void func_0216909C(void);
extern void func_0216EC18(void);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern char *strchr(const char *s, int c);
extern char *strncpy(char *d, const char *s, unsigned long n);
extern unsigned long strtoul(const char *s, char **end, int base);
extern void func_0216EAB8(void **pconnection, int profileID, char *message);
/* * sdk: DWCi_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o)) */ int func_0216BC3C(unsigned char aid);
/* * Copies the +0x24 link of the current object to +0x28 and then sets the * +0x24 link to v. */ void func_0216BC84(int v);
int DWCi_DeleteAID(unsigned char aid);
/* * Builds a bit mask over the first n bytes of the array: m |= 1 << p[i]. */ int func_0216BCD0(unsigned char *p, int n);
/* * sdk: DWCi_HandleGPError (dwc_main.o) * * Extra open callee of DWCi_GPErrorCallback (0x0216C08C). */ int func_0216BD04(int result);
/* * sdk: DWCi_HandleGT2Error (libdwcmatch.TWL.HYB.a(dwc_main.o)) */ int func_0216BE00(int result);
/* * DWCi_CloseConnectionHard: closes an aid's connection, or runs the closed path for a node with none. */ int func_0216BEA4(unsigned char aid);
void func_0216BF38(int error, int profileID);
void DWCi_UpdateServersCallback(int error, int isChanged);
void func_0216BFB8(int error, int cancel, int self, int isServer, int index);
void DWCi_GPErrorCallback(void *connection, int *arg);
void func_0216C0C4(void **pconnection, GPRecvBuddyMessageArg *arg);
extern void *g_021AA8A0[];
extern struct DwcGlobal g_021AA878;
extern char g_021A2030[];
extern char g_021A2038[];




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




/*
 * DWCi_CloseConnectionHard: closes an aid's connection, or runs the closed path for a node with none.
 */
int func_0216BEA4(unsigned char aid)
{
    int conn;
    unsigned char *node;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || func_02059F38() != 0 ||
        (*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24) != 4 &&
         *(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24) != 5)) {
        return -1;
    }
    conn = func_0216BAF4(aid);
    if (conn == 0) {
        node = (unsigned char *)func_02176410(aid);
        if (node == 0) {
            return -2;
        }
        func_0216C230(0, 0, 1, node[0x16]);
        return 0;
    }
    func_02195DC4(conn);
    return 0;
}




void func_0216BF38(int error, int profileID)
{
	if (error == 0) {
		((DwcState *)g_021AA878.st)->profileID = profileID;
		func_0216BC84(3);
		func_0216909C();
	} else {
		func_0216BC84(0);
	}
	if (((DwcState *)g_021AA878.st)->loginCallback != 0)
		((DwcState *)g_021AA878.st)->loginCallback(error, profileID, ((DwcState *)g_021AA878.st)->loginParam);
}




void DWCi_UpdateServersCallback(int error, int isChanged)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    ((void (*)(int, int, int))*(void **)(p + 0x78))(error, isChanged,
        *(int *)(p + 0x7c));
}




/*
 * sdk:      DWCi_MatchedCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
void func_0216BFB8(int error, int cancel, int self, int isServer, int index)
{
	if (error == 0 && cancel != 0) {
		if (((DwcState *)g_021AA878.st)->a96c == 0) {
			func_0216BC84(3);
			func_0216EC18();
		}
	} else if (error == 0) {
		func_0216BC84(5);
	}
	if (((DwcState *)g_021AA878.st)->b05 == 0)
		((void (*)(int, int, int, int, int, void *))((DwcState *)g_021AA878.st)->matchedCallback)(error, cancel, self, isServer, index, ((DwcState *)g_021AA878.st)->matchedParam);
	if (error != 0 && g_021AA878.st != 0 && (unsigned int)(((DwcState *)g_021AA878.st)->state - 4) <= 1)
		func_0216BC84(3);
}




void DWCi_GPErrorCallback(void *connection, int *arg)
{
    int v = arg[1];

    if (v == 0x603 || v == 0x901 || v == 0xb01) return;
    func_0216BD04(3);
}



/*
 * sdk:      DWCi_GPRecvBuddyMessageCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
void func_0216C0C4(void **pconnection, GPRecvBuddyMessageArg *arg)
{
    unsigned long len;
    char *message;
    char version[12] = {0};

    message = arg->message;
    if (memcmp(message, g_021A2030, strlen(g_021A2030)) != 0)
        return;
    message += strlen(g_021A2030);
    len = strchr(message, 'v') - message;
    strncpy(version, message, len);
    if (len > 10)
        return;
    if (strtoul(version, 0, 10) != 90)
        return;
    message += len + 1;
    if (memcmp(message, g_021A2038, strlen(g_021A2038)) != 0)
        return;
    if (((Ctl *)g_021AA878.st)->state != 4) {
        if (((Ctl *)g_021AA878.st)->state != 5)
            return;
        if (((Ctl *)g_021AA878.st)->mode != 2 && ((Ctl *)g_021AA878.st)->mode != 3)
            return;
    }
    func_0216EAB8(pconnection, arg->profile, message + strlen(g_021A2038));
}
