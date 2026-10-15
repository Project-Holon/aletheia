/*
 * function: DWCi_Auth_GetConsoleUserId
 * address:  0x02178F00
 * packet:   pkt_ov009_02178F00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_GetConsoleUserId (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 *
 * symbols:
 *   DWC_Auth_GetId  0x02058FB4  arm
 */

struct DWCAuthWiFiId {
	unsigned long long id_a;
	unsigned long long id_b;
	int use_a;
};

extern void DWC_Auth_GetId(struct DWCAuthWiFiId *id);

unsigned long long DWCi_Auth_GetConsoleUserId(void)
{
	struct DWCAuthWiFiId authid;

	DWC_Auth_GetId(&authid);
	if (authid.use_a != 0)
		return authid.id_a;
	return authid.id_b;
}
