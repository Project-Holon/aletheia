/*
 * function: func_02178C88
 * address:  0x02178C88
 * packet:   pkt_ov009_02178C88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_InitInterface (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 *
 * symbols:
 *   DWC_Auth_SetCustomNas  0x02177EC8  arm
 *   g_021A2424     0x021A2424  data
 *   g_021A244C     0x021A244C  data
 *   g_021A2470     0x021A2470  data
 */

extern void DWC_Auth_SetCustomNas(int v);
extern char g_021A2424[];
extern char g_021A244C[];
extern char g_021A2470[];

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
