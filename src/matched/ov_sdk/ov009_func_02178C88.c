/*
 * function: DWCi_Auth_InitInterface
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
 *   gDwcAuthNasUrlTest     0x021A2424  data
 *   gDwcAuthNasUrlDev     0x021A244C  data
 *   gDwcAuthNasUrlProd     0x021A2470  data
 */

extern void DWC_Auth_SetCustomNas(int v);
extern char gDwcAuthNasUrlTest[];
extern char gDwcAuthNasUrlDev[];
extern char gDwcAuthNasUrlProd[];

int DWCi_Auth_InitInterface(int auth_server)
{
	switch (auth_server) {
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
