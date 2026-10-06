/*
 * function: func_02178EA0
 * address:  0x02178EA0
 * packet:   pkt_ov009_02178EA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_GetGameSpyToken (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 *
 * symbols:
 *   func_02178224  0x02178224  arm  ov009
 *   func_02094860  0x02094860  arm
 */

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

void func_02178EA0(char *authtoken, char *partnerchallenge)
{
	struct DWCAuthResult result;

	func_02178224((int *)(&result));
	func_02094860((u8 *)authtoken, (const u8 *)result.authtoken, 0x12d);
	authtoken[0x12c] = 0;
	func_02094860((u8 *)partnerchallenge, (const u8 *)result.partnerchallenge, 9);
	partnerchallenge[8] = 0;
}
