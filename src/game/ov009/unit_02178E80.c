/*
 * file:     unit_02178E80.c
 * unit:     yes
 * function: func_02178E80, func_02178E90, func_02178EA0
 * address:  0x02178E80
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
 *   g_021AB1A4  0x021AB1A4  data
 *   func_02178224  0x02178224  arm  ov009
 *   func_02094860  0x02094860  arm
 */
#include "../../matched/include/G_DWCAuthState.h"

struct DWCAuthResult {
	int code;
	unsigned char pad0[0x46];
	char authtoken[0x12d];
	char partnerchallenge[9];
	unsigned char pad1[0x44];
};

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_02178224(int *result);
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
int func_02178E80(void);
int func_02178E90(void);
void func_02178EA0(char *authtoken, char *partnerchallenge);
extern struct DWCAuthState g_021AB1A4;


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
