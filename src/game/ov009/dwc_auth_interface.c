/*
 * file:     dwc_auth_interface.c
 * unit:     yes
 * function: func_02178C88, func_02178CE0, func_02178D14, DWCi_Auth_AbortAuthentication, func_02178DB4, func_02178E70, func_02178E80, func_02178E90, func_02178EA0, DWCi_Auth_ShutdownAuthentication, func_02178F00, func_02178F30
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
 *   g_021A2424     0x021A2424  data
 *   g_021A244C     0x021A244C  data
 *   g_021A2470     0x021A2470  data
 *   g_021AB1A4     0x021AB1A4  data
 *   g_021AB208     0x021AB208  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020870D0  0x020870D0  arm
 *   func_02177EE8  0x02177EE8  arm  ov009
 *   g_021AB1C0     0x021AB1C0  data
 *   g_021AB1F4     0x021AB1F4  data
 *   func_021781DC  0x021781DC  arm  ov009
 *   func_02178224  0x02178224  arm  ov009
 *   func_02178144  0x02178144  arm  ov009
 *   func_02094860  0x02094860  arm
 *   func_02058FB4  0x02058FB4  arm
 */
#include "../../matched/include/G_DWCAuthState.h"
#include "../../matched/include/G_DWCAuthParam.h"

struct DWCAuthParam;
typedef struct {
    int code;
    char pad[0x1c0];
} AuthResult;

struct DWCAuthResult {
	int code;
	unsigned char pad0[0x46];
	char authtoken[0x12d];
	char partnerchallenge[9];
	unsigned char pad1[0x44];
};

typedef unsigned int   u32;

typedef unsigned char  u8;

struct DWCAuthWiFiId {
	unsigned long long id_a;
	unsigned long long id_b;
	int use_a;
};

extern void DWC_Auth_SetCustomNas(int v);
extern void MI_CpuFill8(void *dst, int data, unsigned long size);
extern void MI_CpuCopy8(void *src, void *dst, unsigned long size);
extern unsigned long long func_020870D0(void);
extern int func_02177EE8(struct DWCAuthParam *param, void *http);
extern void func_021780A8(void);
extern void func_02178144(void);
extern int func_021781DC(void);
extern void func_02178224(int *result);
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
extern void func_02058FB4(struct DWCAuthWiFiId *id);
int func_02178C88(int auth_server);
void func_02178CE0(void);
int func_02178D14(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long));
void DWCi_Auth_AbortAuthentication(void);
void func_02178DB4(void);
int func_02178E70(void);
int func_02178E80(void);
int func_02178E90(void);
void func_02178EA0(char *authtoken, char *partnerchallenge);
void DWCi_Auth_ShutdownAuthentication(void);
unsigned long long func_02178F00(void);
int func_02178F30(void);
extern char g_021A2424[];
extern char g_021A244C[];
extern char g_021A2470[];
extern struct DWCAuthState g_021AB1A4;
extern unsigned char g_021AB208[];
extern struct DWCAuthParam g_021AB1C0;
extern unsigned char g_021AB1F4[];



/*
 * sdk:      DWCi_Auth_InitInterface (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
int func_02178C88(int auth_server)
{
	switch (auth_server) {
	case 0:
		DWC_Auth_SetCustomNas((int)g_021A2424);
		break;
	case 2:
		DWC_Auth_SetCustomNas((int)g_021A244C);
		break;
	case 1:
		DWC_Auth_SetCustomNas((int)g_021A2470);
		break;
	default:
		return 0;
	}
	return 1;
}



/*
 * sdk:      DWCi_Auth_InitAdapterParam (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
void func_02178CE0(void)
{
	g_021AB1A4.s_finished = 0;
	g_021AB1A4.state = 0;
	g_021AB1A4.returnCode = 0;
	MI_CpuFill8(g_021AB208, 0, 0x1c50);
}



/*
 * sdk:      DWCi_Auth_StartAuthentication (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
int func_02178D14(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long))
{
	func_02178CE0();
	MI_CpuCopy8(ingamesn, &g_021AB1C0, 0x34);
	MI_CpuCopy8(gsbrcd, g_021AB1F4, 0xc);
	g_021AB1C0.allocator = allocator;
	g_021AB1C0.deallocator = deallocator;
	g_021AB1A4.tick = func_020870D0();
	g_021AB1A4.userid = userid;
	if (func_02177EE8(&g_021AB1C0, g_021AB208) == 0)
		return 1;
	return 0;
}


void DWCi_Auth_AbortAuthentication(void)
{
    func_021780A8();
    func_02178144();
}


void func_02178DB4(void)
{
    int authError;
    int returnCode;

    authError = func_021781DC();
    if (authError == 0x15) {
        AuthResult result;
        func_02178224((int *)(&result));
        if (result.code == 0x4e22) {
            func_02178144();
            func_02178CE0();
            if (func_02177EE8((struct DWCAuthParam *)((char *)&g_021AB1C0), g_021AB208) == 0) {
                return;
            }
            returnCode = -20100;
        } else {
            g_021AB1A4.s_finished = 1;
            g_021AB1A4.state = 1;
            return;
        }
    } else {
        AuthResult result;
        if (authError == 0) {
            return;
        }
        func_02178224((int *)(&result));
        func_02178144();
        returnCode = result.code;
    }
    g_021AB1A4.s_finished = 1;
    g_021AB1A4.state = 0;
    g_021AB1A4.returnCode = returnCode;
}


int func_02178E70(void)
{
    return *(int *)((char *)&g_021AB1A4);
}



/*
 * The word at +8 of the module state block.
 */
int func_02178E80(void)
{
    return *(int *)(((char *)&g_021AB1A4) + 8);
}



/*
 * The word at +4 of the module state block.
 */
int func_02178E90(void)
{
    return *(int *)(((char *)&g_021AB1A4) + 4);
}



/*
 * sdk:      DWCi_Auth_GetGameSpyToken (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
void func_02178EA0(char *authtoken, char *partnerchallenge)
{
	struct DWCAuthResult result;

	func_02178224((int *)(&result));
	func_02094860((u8 *)authtoken, (const u8 *)result.authtoken, 0x12d);
	authtoken[0x12c] = 0;
	func_02094860((u8 *)partnerchallenge, (const u8 *)result.partnerchallenge, 9);
	partnerchallenge[8] = 0;
}


void DWCi_Auth_ShutdownAuthentication(void)
{
    func_02178144();
}


unsigned long long func_02178F00(void)
{
	struct DWCAuthWiFiId authid;

	func_02058FB4(&authid);
	if (authid.use_a != 0)
		return authid.id_a;
	return authid.id_b;
}


/*
 * Reads the use_a word of the 0x14-byte frame filled by func_02058FB4.
 */
/*
 * Reads a word back out of a 0x14-byte frame filled by func_02058FB4.
 */
int func_02178F30(void)
{
    struct DWCAuthWiFiId authid;

    func_02058FB4(&authid);
    return authid.use_a;
}
