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
 *   SOCLiRequestedIP     0x021AA444  data
 *   gCpsMyIp     0x021A82BC  data
 *   gSoclConfig     0x021A1CD8  data
 *   SOCLiCPSConfig     0x021AA450  data
 *   CPS_Cleanup  0x02157640  arm  ov009
 *   CPS_SetScavengerCallback  0x02157630  arm  ov009
 *   CPS_SetCheckNConfigCallback  0x02157280  arm  ov009
 *   WCM_SetRecvDCFCallback  0x02166424  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SOCL_Close  0x0215E84C  arm  ov009
 *   SOCLiUDPSendSocket     0x021AA44C  data
 *   SOCLiSocketList     0x021AA4B4  data
 *   SOCLiTrashList     0x021AA4B8  data
 *   SOCL_IsClosed  0x0215E794  arm  ov009
 *   SOCLi_TrashSocket  0x0215EBB4  arm  ov009
 *   CPS_CalmDown  0x021575DC  arm  ov009
 */
#include "socl_command_types.h"

/* SOCLiCPSConfig: the CPS configuration object (only bufSize and the field at
 * 0x1c, the command-packet size, are read). */
#include "ov009_globals.h"

/* The SOCL socket list entries at SOCLiUDPSendSocket/SOCLiSocketList/SOCLiTrashList: only the
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
extern unsigned long SOCLiRequestedIP;
extern unsigned long gCpsMyIp;
extern SoclConfig *gSoclConfig;
extern CpsConfig SOCLiCPSConfig;
extern SoclSocket *SOCLiUDPSendSocket;
extern SoclSocket *SOCLiSocketList;
extern SoclSocket *SOCLiTrashList;


/*
 * sdk:      SOCL_Cleanup (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
int SOCL_Cleanup(void)
{
	int result;

	if (SOCLiRequestedIP == 0) {
		SOCLiRequestedIP = gCpsMyIp;
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
			gSoclConfig->free((void *)SOCLiCPSConfig.lan_buf);
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
		for (socket = ((SoclSocket *)SOCLiSocketList); socket != 0; socket = socket->next) {
			if (socket != ((SoclSocket *)SOCLiUDPSendSocket) && (socket->state & 0x10) == 0) {
				break;
			}
		}
		OS_RestoreInterrupts(enable);
		if (socket == 0) {
			break;
		}
		SOCL_Close((int)socket);
	}
	if (((SoclSocket *)SOCLiSocketList) == 0 || (((SoclSocket *)SOCLiSocketList) == ((SoclSocket *)SOCLiUDPSendSocket) && SOCLiSocketList->next == 0)) {
		if (((SoclSocket *)SOCLiTrashList) == 0) {
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

	if ((*(int *)&SOCLiUDPSendSocket)) {
		result = SOCL_CloseAll();
		if (result == 0) {
			SOCL_Close((*(int *)&SOCLiUDPSendSocket));
			if (SOCL_IsClosed((*(int *)&SOCLiUDPSendSocket))) {
				(*(int *)&SOCLiUDPSendSocket) = 0;
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
