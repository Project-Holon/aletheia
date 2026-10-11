/*
 * file:     unit_0216AB20_p05.c
 * unit:     yes
 * function: func_0216BC3C, func_0216BC84, func_0216BCA4, func_0216BCD0, func_0216BD04, func_0216BE00, func_0216BEA4, func_0216BF38, func_0216BF98, func_0216BFB8, DWCi_GPErrorCallback, func_0216C0C4, func_0216C224, func_0216C230, DWCi_GT2ClosedCallback, func_0216C79C, DWCi_GT2SocketErrorCallback, func_0216C7E0, func_0216C800, func_0216C82C
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
 *   func_02177340  0x02177340  arm  ov009
 *   DWCi_IsShutdownMatch                      0x0216F370  arm   ov009
 *   gt2GetConnectionData                      0x02195E78  arm   ov009
 *   DWCi_NodeInfoList_GetNodeInfoForAID       0x02176410  arm   ov009
 *   DWCi_ClearTransConnection                 0x021776A0  arm   ov009
 *   DWCi_NodeInfoList_GetServerNodeInfo       0x02176358  arm   ov009
 *   DWCi_IsBackupMine                         0x021754FC  arm   ov009
 *   DWCi_GetGT2Connection                     0x0216BAF4  arm   ov009
 *   DWC_IsServerMyself                        0x0216BA08  arm   ov009
 *   DWC_GetNumConnectionHost                  0x0216B804  arm   ov009
 *   DWCi_NodeInfoList_GetCount                0x0217603C  arm   ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex     0x0217637C  arm   ov009
 *   DWCi_GetFriendListIndex                   0x02169038  arm   ov009
 *   DWCi_IsFullMesh                           0x0217695C  arm   ov009
 *   DWCi_GPSetServerStatus                    0x0216F20C  arm   ov009
 *   DWCi_ProcessMatchSCClosing                0x0216F1E8  arm   ov009
 *   DWCi_ProcessMatchClosing                  0x0216F0A0  arm   ov009
 *   DWCi_SetError                             0x02059F54  arm
 *   qr2_send_statechanged                     0x0219B490  arm   ov009
 *   DWCi_StopMeshMaking                       0x02176674  arm   ov009
 *   DWCi_SetMatchStatus                       0x02175F4C  arm   ov009
 *   DWCi_NNFreeNegotiateList                  0x02176B34  arm   ov009
 *   DWCi_SetState                             0x0216BC84  arm   ov009
 *   DWCi_ClearQR2Key                          0x0216EC18  arm   ov009
 *   DWCi_IsServerChangeEnabled                0x02175FC8  arm   ov009
 *   DWCi_GT2ClosedProcess        0x0216C230  arm
 *   func_02177398  0x02177398  arm  ov009
 *   func_02195E60  0x02195E60  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   func_0216B9B0  0x0216B9B0  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 */
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

typedef unsigned short u16;

typedef unsigned long u32;

struct DWCstConnectionInfo {
    u8 index;                /* 0x00 */
    u8 aid;                  /* 0x01 */
    u16 pad;                 /* 0x02 */
    int profileID;           /* 0x04 */
};

struct DWCstNodeInfo {
	int profileID;
	unsigned int publicInetAddress;
	unsigned int privateInetAddress;
	unsigned short publicQueryPort;
	unsigned short privateQueryPort;
	unsigned int gt2IP;
	unsigned short gt2Port;
	unsigned char aid;
	unsigned char hasPrivateAddress;
	int nnTryCount;
	unsigned long long nextMeshMakeTryTick;
	unsigned char connUserData[4];
};

typedef void (*DwcClosedProc)(int, int, int, int, int, void *);

struct DWCControl {
    char pad00[0x24];
    int f24;                          /* 0x24 */
    char pad28[0x2d - 0x28];
    u8 f2d;                           /* 0x2d */
    char pad2e[0x88 - 0x2e];
    DwcClosedProc cb88;               /* 0x88 */
    void *f8c;                        /* 0x8c */
    char pad90[0x360 - 0x90];
    void *f360;                       /* 0x360 */
    u8 f364;                          /* 0x364 */
    volatile u8 f365;                 /* 0x365 */
    u8 f366;                          /* 0x366 */
    char pad367[0x36c - 0x367];
    int f36c;                         /* 0x36c */
    char pad370[0x394 - 0x370];
    int f394;                         /* 0x394 */
    int f398;                         /* 0x398 */
    char pad39c[0x96c - 0x39c];
    int f96c;                         /* 0x96c */
    char pad970[0x9c8 - 0x970];
    int f9c8;                         /* 0x9c8 */
    char pad9cc[0xa28 - 0x9cc];
    u8 fa28;                          /* 0xa28 */
    char pada29[0xab8 - 0xa29];
    unsigned long long fab8;          /* 0xab8 */
    char padac0[0xadc - 0xac0];
    int fadc;                         /* 0xadc */
    char pade0[0xaf0 - 0xae0];
    unsigned long long faf0;          /* 0xaf0 */
    char padaf8[0xb14 - 0xaf8];
    int fb14;                         /* 0xb14 */
};

extern int func_02195E78(const int *p);
extern char *func_02176410(unsigned char aid);
extern int func_02176164(unsigned char aid);
extern void func_0216A3B8(int error, int errorCode);
extern void func_0216EB68(int error, int errorCode);
extern void func_02168E50(int error, int errorCode);
extern int func_02059F38(void);
extern int func_0216BAF4(int aid);
extern void func_02195DC4(int conn);
extern void func_0216909C(void);
extern void func_0216EC18(void);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern char *strchr(const char *s, int c);
extern char *strncpy(char *d, const char *s, unsigned long n);
extern unsigned long strtoul(const char *s, char **end, int base);
extern void func_0216EAB8(void **pconnection, int profileID, char *message);
extern void func_02177340(void *connection, unsigned char *message, int size, int reliable);
extern int DWCi_IsShutdownMatch(void);
extern struct DWCstConnectionInfo *gt2GetConnectionData(struct GTI2Connection *connection);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern void DWCi_ClearTransConnection(unsigned char aid);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void);
extern int DWCi_IsBackupMine(void);
extern struct GTI2Connection *DWCi_GetGT2Connection(unsigned char aid);
extern int DWC_IsServerMyself(void);
extern int DWC_GetNumConnectionHost(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_GetFriendListIndex(int profileID);
extern int DWCi_IsFullMesh(void);
extern int DWCi_GPSetServerStatus(int matchType);
extern void DWCi_ProcessMatchSCClosing(int clientPid);
extern int DWCi_ProcessMatchClosing(int error, int errorCode, int profileID);
extern void DWCi_SetError(int error, int errorCode);
extern void qr2_send_statechanged(void *qrec);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_NNFreeNegotiateList(void);
extern void DWCi_SetState(int state);
extern void DWCi_ClearQR2Key(void);
extern int DWCi_IsServerChangeEnabled(void);
extern void DWCi_GT2ClosedProcess(void);
extern void func_02177398(void *connection, int latency);
int func_0216BC3C(unsigned char aid);
void func_0216BC84(int v);
int DWCi_DeleteAID(unsigned char aid);
int func_0216BCD0(unsigned char *p, int n);
int func_0216BD04(int result);
int func_0216BE00(int result);
int func_0216BEA4(unsigned char aid);
void func_0216BF38(int error, int profileID);
void DWCi_UpdateServersCallback(int error, int isChanged);
void func_0216BFB8(int error, int cancel, int self, int isServer, int index);
void DWCi_GPErrorCallback(void *connection, int *arg);
void func_0216C0C4(void **pconnection, GPRecvBuddyMessageArg *arg);
void func_0216C224(void *connection, unsigned char *message, int size, int reliable);
void func_0216C230(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
asm void DWCi_GT2ClosedCallback(void);
void func_0216C79C(void *connection, int latency);
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


void func_0216C224(void *connection, unsigned char *message, int size, int reliable)
{
    func_02177340(connection, message, size, reliable);
}



/*
 * sdk:      DWCi_GT2ClosedProcess (libdwcmatch dwc_main.o, static)
 *
 * Reconstructed from the DWARF of the defining object (param/local names and
 * registers) plus the object disassembly.  Object stamp is 4.0.0.1025.
 *
 * Closed 2026-10-01 (wave 3 lane 11) by re-deriving semantics from branch
 * targets: the fb14 if/else chain sits after the `dwcError == 0` block (the
 * image's `bne` at +0080 lands on it), its last arm is an if/else with two
 * stores, the final NodeInfoList_GetCount()==1 test is `f2d != 0`, faf0 and
 * fab8 are 64-bit fields (two stores off one base), locals declared in DWARF
 * order with pNodeInfo scoped to the IsBackupMine block, and f365 is a
 * volatile byte field (the image re-reads it, `ldrbne`).
 */
void func_0216C230(struct GTI2Connection *connection, int reason,
                           int isPseudClose, unsigned char closeAid)
{
    unsigned char aid;
    int profileID;
    int errorCode;
    int i;
    int isServer;
    int aidValid;
    struct DWCstConnectionInfo *conninfo;
    int dwcError;

    isServer = profileID = 0;

    if (DWCi_IsShutdownMatch())
        return;

    switch (reason) {
    case 0:
    case 1:
        errorCode = dwcError = profileID;
        break;
    case 2:
    case 3:
        dwcError = 6;
        errorCode = -7600;
        break;
    case 4:
        dwcError = 9;
        errorCode = -7601;
        break;
    }

    if (dwcError == 0) {
        if (!isPseudClose) {
            conninfo = gt2GetConnectionData(connection);
            if (conninfo == 0)
                return;
            aid = conninfo->aid;
        } else {
            aid = closeAid;
        }

        aidValid = DWCi_NodeInfoList_GetNodeInfoForAID(aid) != 0;

        if (!isPseudClose)
            DWCi_ClearTransConnection(aid);

        if (DWCi_NodeInfoList_GetServerNodeInfo() != 0) {
            if (aid == DWCi_NodeInfoList_GetServerNodeInfo()->aid)
                isServer = 1;
        }

        profileID = DWCi_DeleteAID(aid);
        ((struct DWCControl *)g_021AA878.st)->f36c &= ~(1 << aid);

        if (((struct DWCControl *)g_021AA878.st)->f398 != 0 && isServer) {
            if (!DWCi_IsBackupMine())
                ((struct DWCControl *)g_021AA878.st)->f394 = 1;
        }

        i = 0;

        if (profileID == 0)
            profileID = gt2GetConnectionData(DWCi_GetGT2Connection(aid))->profileID;

        if (!isPseudClose)
            g_021AA8A0[conninfo->index] = 0;
    }

    if (((struct DWCControl *)g_021AA878.st)->fb14 == 1 && DWC_IsServerMyself())
        ((struct DWCControl *)g_021AA878.st)->fb14 = 1;
    else if ((((struct DWCControl *)g_021AA878.st)->f365 == 3 || ((struct DWCControl *)g_021AA878.st)->f365 == 2))
        ((struct DWCControl *)g_021AA878.st)->fb14 = 0;
    else if (DWC_GetNumConnectionHost() == 1)
        ((struct DWCControl *)g_021AA878.st)->fb14 = 1;
    else
        ((struct DWCControl *)g_021AA878.st)->fb14 = 0;

    if (DWCi_IsBackupMine()) {
        struct DWCstNodeInfo *pNodeInfo;

        ((struct DWCControl *)g_021AA878.st)->fadc = 0;

        for (i = 0; i < DWCi_NodeInfoList_GetCount(); ) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);

            if (pNodeInfo->profileID != ((struct DWCControl *)g_021AA878.st)->f9c8 &&
                DWCi_GetGT2Connection(pNodeInfo->aid) == 0) {
                if (((struct DWCControl *)g_021AA878.st)->cb88 != 0) {
                    ((struct DWCControl *)g_021AA878.st)->cb88(dwcError, reason == 0, isServer,
                                          pNodeInfo->aid,
                                          DWCi_GetFriendListIndex(pNodeInfo->profileID),
                                          ((struct DWCControl *)g_021AA878.st)->f8c);
                }
                DWCi_DeleteAID(pNodeInfo->aid);
            } else {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                ((struct DWCControl *)g_021AA878.st)->fadc |= 1 << pNodeInfo->aid;
                i++;
            }
        }
    }

    if (reason != 0 && DWC_IsServerMyself() == 1) {
        ((struct DWCControl *)g_021AA878.st)->faf0 = 0;

        if (DWCi_IsFullMesh()) {
            if (((struct DWCControl *)g_021AA878.st)->f96c == 0x10 && ((struct DWCControl *)g_021AA878.st)->fa28 == 8) {
                ((struct DWCControl *)g_021AA878.st)->fab8 = 0;
            }
        }
    }

    if (((struct DWCControl *)g_021AA878.st)->f2d == 0 && ((struct DWCControl *)g_021AA878.st)->f24 == 5 && aidValid == 0) {
        if (!(((struct DWCControl *)g_021AA878.st)->f364 == 2 && dwcError == 0))
            return;

        DWCi_GPSetServerStatus(-1);
        DWCi_ProcessMatchSCClosing(profileID);
        return;
    }

    if (DWCi_ProcessMatchClosing(dwcError, errorCode, profileID) != 0)
        return;

    i = 0;

    if (dwcError != 0) {
        DWCi_SetError(dwcError, errorCode - 80000);
        return;
    }

    if (((struct DWCControl *)g_021AA878.st)->f364 == 2) {
        if (((struct DWCControl *)g_021AA878.st)->f2d == 0)
            DWCi_GPSetServerStatus(-1);
        else if (DWCi_NodeInfoList_GetCount() == 1)
            DWCi_GPSetServerStatus(1);
    } else if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_GPSetServerStatus(1);
    }

    if (((struct DWCControl *)g_021AA878.st)->f366 == 2)
        qr2_send_statechanged(((struct DWCControl *)g_021AA878.st)->f360);

    if (((struct DWCControl *)g_021AA878.st)->cb88 != 0 && aidValid != 0) {
        ((struct DWCControl *)g_021AA878.st)->cb88(dwcError, reason == 0, isServer, aid,
                              DWCi_GetFriendListIndex(profileID),
                              ((struct DWCControl *)g_021AA878.st)->f8c);
    }

    if (((struct DWCControl *)g_021AA878.st)->f2d == 0 && ((struct DWCControl *)g_021AA878.st)->f364 == 2)
        return;

    if (DWCi_StopMeshMaking() == 1)
        DWCi_SetMatchStatus(1);

    if (DWCi_NodeInfoList_GetCount() == 1) {
        if (((struct DWCControl *)g_021AA878.st)->f2d != 0) {
            DWCi_NNFreeNegotiateList();
            DWCi_SetState(3);
            DWCi_ClearQR2Key();
            ((struct DWCControl *)g_021AA878.st)->f366 = 0;
        } else {
            DWCi_SetMatchStatus(0xb);
        }
        return;
    }

    if (((struct DWCControl *)g_021AA878.st)->f364 == 3 && isServer && DWCi_NodeInfoList_GetCount() >= 1) {
        if (DWCi_NodeInfoList_GetCount() == 1 && DWCi_IsServerChangeEnabled())
            DWCi_SetMatchStatus(0xb);
        else
            DWCi_SetMatchStatus(9);
    }
}



asm void DWCi_GT2ClosedCallback(void)
{
	ldr ip, =DWCi_GT2ClosedProcess
	mov r2, #0
	mov r3, #0xff
	bx ip
}


void func_0216C79C(void *connection, int latency)
{
    func_02177398(connection, latency);
}

extern int func_02195E60(const int *p);
extern int func_0217ED54(void);
extern void func_02059F54(int error, int errorCode);
extern unsigned char func_0216B9B0(void);
extern char *func_0217637C(int index);
void DWCi_GT2SocketErrorCallback(void *socket);
/* * Writes the mode byte at +0x365 and clears the word at +0xae8 of the * current object. */ void func_0216C7E0(unsigned char v);
unsigned char DWCi_GetServerOrSubServerAID(void);
/* * 1 unless the current object is in mode 2 (always 1) or carries a zero * byte at +0x35d with a mode other than 2. */ int func_0216C82C(void);


void DWCi_GT2SocketErrorCallback(void *socket)
{
    func_02195E60(socket);
    g_021AA878.lastSocketError = func_0217ED54();
    func_02059F54(9, (int)0xfffe8515);
    *(int *)g_021AA878.st = 0;
}



/*
 * Writes the mode byte at +0x365 and clears the word at +0xae8 of the
 * current object.
 */
void func_0216C7E0(unsigned char v)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    *(unsigned char *)(p + 0x365) = v;
    p = *(char **)(((char *)&g_021AA878) + 4);
    *(int *)(p + 0xae8) = 0;
}



unsigned char DWCi_GetServerOrSubServerAID(void)
{
    unsigned char aid = func_0216B9B0();
    if (aid == 0xff) {
        char *info = func_0217637C(0);
        if (info != 0) aid = info[0x16];
    }
    return aid;
}



/*
 * 1 unless the current object is in mode 2 (always 1) or carries a zero
 * byte at +0x35d with a mode other than 2.
 */
int func_0216C82C(void)
{
    int r = 1;
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    if (*(unsigned char *)(p + 0x365) != 2)
        if (*(unsigned char *)(p + 0x35d) == 0) r = 0;
    return r;
}
