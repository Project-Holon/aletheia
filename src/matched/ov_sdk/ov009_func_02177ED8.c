/*
 * function: DWC_Auth_GetCustomNas
 * address:  0x02177ED8
 * packet:   pkt_ov009_02177ED8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_GetCustomNas (libdwcauth.TWL.HYB.a dwc_auth.o)
 * symbols:
 *   DWCauthhttpparam                 0x021a2358 data ov009
 */

typedef struct DWCHttpParam {
	char *customnas;
} DWCHttpParam;

extern DWCHttpParam DWCauthhttpparam;

char *DWC_Auth_GetCustomNas(void)
{
	return DWCauthhttpparam.customnas;
}
