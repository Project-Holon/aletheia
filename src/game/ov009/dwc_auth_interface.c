/*
 * file:     dwc_auth_interface.c
 * unit:     yes
 * function: DWCi_Auth_InitInterface, DWCi_Auth_InitAdapterParam, DWCi_Auth_StartAuthentication, DWCi_Auth_AbortAuthentication, DWCi_Auth_ProcessAuthentication, DWCi_Auth_IsFinished, DWCi_Auth_IsSucceeded, DWCi_Auth_GetErrorCode, DWCi_Auth_GetGameSpyToken, DWCi_Auth_ShutdownAuthentication, DWCi_Auth_GetConsoleUserId, DWCi_Auth_IsConsoleUserIdAuthentic
 * address:  0x02178C88
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Calls the two module helpers in order.

 * sdk:      DWCi_Auth_ProcessAuthentication (dwc_auth_interface.o)
 * The word at the head of the module state block.
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 * sdk:      DWCi_Auth_GetConsoleUserId (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 *
 * symbols:
 *   DWC_Auth_SetCustomNas  0x02177EC8  arm
 *   gDwcAuthNasUrlTest     0x021A2424  data
 *   gDwcAuthNasUrlDev     0x021A244C  data
 *   gDwcAuthNasUrlProd     0x021A2470  data
 *   gDwcAuthState     0x021AB1A4  data
 *   gDwcAuthResultBuf     0x021AB208  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020870D0  0x020870D0  arm
 *   DWC_Auth_Create  0x02177EE8  arm  ov009
 *   gDwcAuthParam     0x021AB1C0  data
 *   gDwcAuthGsbrcdBuffer     0x021AB1F4  data
 *   DWC_Auth_GetError  0x021781DC  arm  ov009
 *   DWC_Auth_GetResult  0x02178224  arm  ov009
 *   DWC_Auth_Destroy  0x02178144  arm  ov009
 *   strncpy  0x02094860  arm
 *   DWC_Auth_GetId  0x02058FB4  arm
 *   DWC_Auth_Abort  0x021780A8  arm
 */
#include "dwc_auth_types.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

struct DWCAuthWiFiId {
	unsigned long long idA;
	unsigned long long idB;
	int useA;
};

extern void DWC_Auth_SetCustomNas(int v);
extern void MI_CpuFill8(void *dst, int data, unsigned long size);
extern void MI_CpuCopy8(void *src, void *dst, unsigned long size);
extern unsigned long long func_020870D0(void);
extern int DWC_Auth_Create(struct DWCAuthParam *param, void *http);
extern void DWC_Auth_Abort(void);
extern void DWC_Auth_Destroy(void);
extern int DWC_Auth_GetError(void);
extern void DWC_Auth_GetResult(int *result);
extern u8 *strncpy(u8 *dest, const u8 *src, u32 n);
extern void DWC_Auth_GetId(struct DWCAuthWiFiId *id);
int DWCi_Auth_InitInterface(int auth_server);
void DWCi_Auth_InitAdapterParam(void);
int DWCi_Auth_StartAuthentication(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long));
void DWCi_Auth_AbortAuthentication(void);
void DWCi_Auth_ProcessAuthentication(void);
int DWCi_Auth_IsFinished(void);
int DWCi_Auth_IsSucceeded(void);
int DWCi_Auth_GetErrorCode(void);
void DWCi_Auth_GetGameSpyToken(char *authtoken, char *partnerchallenge);
void DWCi_Auth_ShutdownAuthentication(void);
unsigned long long DWCi_Auth_GetConsoleUserId(void);
int DWCi_Auth_IsConsoleUserIdAuthentic(void);
extern char gDwcAuthNasUrlTest[];
extern char gDwcAuthNasUrlDev[];
extern char gDwcAuthNasUrlProd[];
extern struct DWCAuthState gDwcAuthState;
extern unsigned char gDwcAuthResultBuf[];
extern struct DWCAuthParam gDwcAuthParam;
extern unsigned char gDwcAuthGsbrcdBuffer[];



/*
 * sdk:      DWCi_Auth_InitInterface (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
int DWCi_Auth_InitInterface(int authServer)
{
	switch (authServer) {
	case 0:
		DWC_Auth_SetCustomNas((int)gDwcAuthNasUrlTest);
		break;
	case 2:
		DWC_Auth_SetCustomNas((int)gDwcAuthNasUrlDev);
		break;
	case 1:
		DWC_Auth_SetCustomNas((int)gDwcAuthNasUrlProd);
		break;
	default:
		return 0;
	}
	return 1;
}



/*
 * sdk:      DWCi_Auth_InitAdapterParam (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
void DWCi_Auth_InitAdapterParam(void)
{
	gDwcAuthState.finished = 0;
	gDwcAuthState.state = 0;
	gDwcAuthState.returnCode = 0;
	MI_CpuFill8(gDwcAuthResultBuf, 0, 0x1c50);
}



/*
 * sdk:      DWCi_Auth_StartAuthentication (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
int DWCi_Auth_StartAuthentication(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long))
{
	DWCi_Auth_InitAdapterParam();
	MI_CpuCopy8(ingamesn, &gDwcAuthParam, 0x34);
	MI_CpuCopy8(gsbrcd, gDwcAuthGsbrcdBuffer, 0xc);
	gDwcAuthParam.alloc = allocator;
	gDwcAuthParam.free = deallocator;
	gDwcAuthState.tick = func_020870D0();
	gDwcAuthState.userid = userid;
	if (DWC_Auth_Create(&gDwcAuthParam, gDwcAuthResultBuf) == 0)
		return 1;
	return 0;
}


void DWCi_Auth_AbortAuthentication(void)
{
    DWC_Auth_Abort();
    DWC_Auth_Destroy();
}


void DWCi_Auth_ProcessAuthentication(void)
{
    int authError;
    int returnCode;

    authError = DWC_Auth_GetError();
    if (authError == 0x15) {
        DWCAuthResult result;
        DWC_Auth_GetResult((int *)(&result));
        if (result.returncode == 0x4e22) {
            DWC_Auth_Destroy();
            DWCi_Auth_InitAdapterParam();
            if (DWC_Auth_Create(&gDwcAuthParam, gDwcAuthResultBuf) == 0) {
                return;
            }
            returnCode = -20100;
        } else {
            gDwcAuthState.finished = 1;
            gDwcAuthState.state = 1;
            return;
        }
    } else {
        DWCAuthResult result;
        if (authError == 0) {
            return;
        }
        DWC_Auth_GetResult((int *)(&result));
        DWC_Auth_Destroy();
        returnCode = result.returncode;
    }
    gDwcAuthState.finished = 1;
    gDwcAuthState.state = 0;
    gDwcAuthState.returnCode = returnCode;
}


int DWCi_Auth_IsFinished(void)
{
    return gDwcAuthState.finished;
}



/*
 * The word at +8 of the module state block.
 */
int DWCi_Auth_IsSucceeded(void)
{
    return gDwcAuthState.state;
}



/*
 * The word at +4 of the module state block.
 */
int DWCi_Auth_GetErrorCode(void)
{
    return gDwcAuthState.returnCode;
}



/*
 * sdk:      DWCi_Auth_GetGameSpyToken (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
void DWCi_Auth_GetGameSpyToken(char *authtoken, char *partnerchallenge)
{
	struct DWCAuthResult result;

	DWC_Auth_GetResult((int *)(&result));
	strncpy((u8 *)authtoken, (const u8 *)result.token, 0x12d);
	authtoken[0x12c] = 0;
	strncpy((u8 *)partnerchallenge, (const u8 *)result.challenge, 9);
	partnerchallenge[8] = 0;
}


void DWCi_Auth_ShutdownAuthentication(void)
{
    DWC_Auth_Destroy();
}


unsigned long long DWCi_Auth_GetConsoleUserId(void)
{
	struct DWCAuthWiFiId authid;

	DWC_Auth_GetId(&authid);
	if (authid.useA != 0)
		return authid.idA;
	return authid.idB;
}


/*
 * Reads the use_a word of the 0x14-byte frame filled by DWC_Auth_GetId.
 */
/*
 * Reads a word back out of a 0x14-byte frame filled by DWC_Auth_GetId.
 */
int DWCi_Auth_IsConsoleUserIdAuthentic(void)
{
    struct DWCAuthWiFiId authid;

    DWC_Auth_GetId(&authid);
    return authid.useA;
}
