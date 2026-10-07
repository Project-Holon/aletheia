/*
 * function: func_0216B94C
 * address:  0x0216B94C
 * packet:   pkt_ov009_0216B94C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_02176410  0x02176410  arm  ov009
 *   g_021AA878  0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

extern unsigned char func_0216B838(void);
extern char *func_02176410(unsigned char aid);
extern struct DwcGlobal g_021AA878;

int func_0216B94C(unsigned char aid)
{
	if (*(int *)(((char *)&g_021AA878) + 4) == 0)
		return 0;
	if (aid == func_0216B838())
		return 0;
	if (func_02176410(aid))
		return 1;
	return 0;
}
