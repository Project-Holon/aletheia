/*
 * file:     socl_cleanup.c
 * unit:     yes
 * function: SOCL_Cleanup, SOCLi_CleanupCPS, SOCL_CloseAll, SOCL_CalmDown
 * address:  0x0215EBF0
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
 *   OS_Sleep  0x02085A38  arm
 *   SOCLi_CleanupCommandPacketQueue  0x0215CDD0  arm  ov009
 *   SOCLi_InitResource  0x0215F0D4  arm  ov009
 *   g_021AA444     0x021AA444  data
 *   g_021A82BC     0x021A82BC  data
 *   gSoclConfig     0x021A1CD8  data
 *   g_021AA450     0x021AA450  data
 *   CPS_Cleanup  0x02157640  arm  ov009
 *   CPS_SetScavengerCallback  0x02157630  arm  ov009
 *   CPS_SetCheckNConfigCallback  0x02157280  arm  ov009
 *   WCM_SetRecvDCFCallback  0x02166424  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SOCL_Close  0x0215E84C  arm  ov009
 *   g_021AA44C     0x021AA44C  data
 *   g_021AA4B4     0x021AA4B4  data
 *   g_021AA4B8     0x021AA4B8  data
 *   SOCL_IsClosed  0x0215E794  arm  ov009
 *   SOCLi_TrashSocket  0x0215EBB4  arm  ov009
 *   CPS_CalmDown  0x021575DC  arm  ov009
 */
#include "socl_command_types.h"

/* g_021AA450: the CPS configuration object (only bufSize and the field at
 * 0x1c, the command-packet size, are read). */
#include "ov009_globals.h"

/* The SOCL socket list entries at g_021AA44C/g_021AA4B4/g_021AA4B8: only the
 * state word and the next link are read here. */
typedef struct SoclSocket {
	unsigned char reserved0[0xAC];
	short state;
	unsigned char reservedAE[0xA];
	void *next;
} SoclSocket;

extern void OS_Sleep(unsigned long msec);
extern int SOCLi_CleanupCommandPacketQueue(void);
extern void SOCLi_InitResource(void);
extern void CPS_Cleanup(void);
extern void CPS_SetScavengerCallback(int v);
extern void CPS_SetCheckNConfigCallback(int v);
extern void WCM_SetRecvDCFCallback(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int SOCL_Close(int s);
extern int SOCL_IsClosed(int s);
extern void SOCLi_TrashSocket(void);
extern int CPS_CalmDown(void);
int SOCL_Cleanup(void);
void SOCLi_CleanupCPS(void);
int SOCL_CloseAll(void);
int SOCL_CalmDown(void);
extern unsigned long g_021AA444;
extern unsigned long g_021A82BC;
extern SoclConfig *gSoclConfig;
extern CpsConfig g_021AA450;
extern SoclSocket *g_021AA44C;
extern SoclSocket *g_021AA4B4;
extern SoclSocket *g_021AA4B8;


/*
 * sdk:      SOCL_Cleanup (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
int SOCL_Cleanup(void)
{
	int result;

	if (g_021AA444 == 0) {
		g_021AA444 = g_021A82BC;
	}
	result = SOCL_CalmDown();
	while (result == -26) {
		OS_Sleep(100);
		result = SOCL_CalmDown();
	}
	result = SOCLi_CleanupCommandPacketQueue();
	if (result >= 0) {
		SOCLi_CleanupCPS();
		if (gSoclConfig->serviceFlag == 0) {
			gSoclConfig->free((void *)g_021AA450.field1c);
		}
		gSoclConfig = 0;
		SOCLi_InitResource();
	}
	return result;
}


/*
 * sdk:      SOCLi_CleanupCPS (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
void SOCLi_CleanupCPS(void)
{
	CPS_Cleanup();
	CPS_SetScavengerCallback(0);
	CPS_SetCheckNConfigCallback(0);
	WCM_SetRecvDCFCallback(0);
}


/*
 * sdk:      SOCL_CloseAll (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
int SOCL_CloseAll(void)
{
	unsigned long enable;
	SoclSocket *socket;

	for (;;) {
		enable = OS_DisableInterrupts();
		for (socket = ((SoclSocket *)g_021AA4B4); socket != 0; socket = socket->next) {
			if (socket != ((SoclSocket *)g_021AA44C) && (socket->state & 0x10) == 0) {
				break;
			}
		}
		OS_RestoreInterrupts(enable);
		if (socket == 0) {
			break;
		}
		SOCL_Close((int)socket);
	}
	if (((SoclSocket *)g_021AA4B4) == 0 || (((SoclSocket *)g_021AA4B4) == ((SoclSocket *)g_021AA44C) && g_021AA4B4->next == 0)) {
		if (((SoclSocket *)g_021AA4B8) == 0) {
			return 0;
		}
	}
	return -26;
}


/*
 * sdk:      SOCL_CalmDown (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
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
