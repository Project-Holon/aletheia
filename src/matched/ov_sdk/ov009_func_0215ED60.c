/*
 * function: SOCL_CalmDown
 * address:  0x0215ED60
 * packet:   pkt_ov009_0215ED60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_CalmDown (libsoc.TWL.HYB.a(socl_cleanup.o))
 *
 * symbols:
 *   SOCL_CloseAll  0x0215ECB8  arm  ov009
 *   SOCL_Close  0x0215E84C  arm  ov009
 *   SOCL_IsClosed  0x0215E794  arm  ov009
 *   SOCLi_TrashSocket  0x0215EBB4  arm  ov009
 *   CPS_CalmDown  0x021575DC  arm  ov009
 *   WCM_SetRecvDCFCallback  0x02166424  arm  ov009
 *   g_021AA44C     0x021AA44C  data
 */

#include "../include/G_Sock.h"

extern int SOCL_CloseAll(void);
extern int SOCL_Close(int s);
extern int SOCL_IsClosed(int s);
extern void SOCLi_TrashSocket(void);
extern int CPS_CalmDown(void);
extern void WCM_SetRecvDCFCallback(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));
extern struct Sock *g_021AA44C;

int SOCL_CalmDown(void)
{
	int result;

	if ((*(int *)&g_021AA44C)) {
		result = SOCL_CloseAll();
		if (result == 0) {
			SOCL_Close((*(int *)&g_021AA44C));
			if (SOCL_IsClosed((*(int *)&g_021AA44C))) {
				(*(int *)&g_021AA44C) = 0;
			}
			result = -26;
		}
		SOCLi_TrashSocket();
	} else {
		if (CPS_CalmDown() == 0) {
			result = -26;
		} else {
			result = 0;
			WCM_SetRecvDCFCallback(0);
		}
	}
	return result;
}
