/*
 * function: SOCL_Cleanup
 * address:  0x0215EBF0
 * packet:   pkt_ov009_0215EBF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_Cleanup (libsoc.TWL.HYB.a(socl_cleanup.o))
 *
 * symbols:
 *   SOCL_CalmDown  0x0215ED60  arm  ov009
 *   OS_Sleep  0x02085A38  arm
 *   SOCLi_CleanupCommandPacketQueue  0x0215CDD0  arm  ov009
 *   SOCLi_CleanupCPS  0x0215EC90  arm  ov009
 *   SOCLi_InitResource  0x0215F0D4  arm  ov009
 *   g_021AA444     0x021AA444  data
 *   g_021A82BC     0x021A82BC  data
 *   gSoclConfig     0x021A1CD8  data
 *   g_021AA450     0x021AA450  data
 */

#include "../include/G_CPSConfig.h"

typedef struct {
	unsigned char pad0[0x1c];
	unsigned long field1c;
} CPSConfig;

typedef struct {
	unsigned char pad0[0x1c];
	void (*func1c)(unsigned long);
	unsigned char pad1[0x08];
	int flag28;
} SOCConfig;

extern int SOCL_CalmDown(void);
extern void OS_Sleep(unsigned long msec);
extern int SOCLi_CleanupCommandPacketQueue(void);
extern void SOCLi_CleanupCPS(void);
extern void SOCLi_InitResource(void);
extern unsigned long g_021AA444;
extern unsigned long g_021A82BC;
extern SOCConfig *gSoclConfig;
extern struct CPSConfig g_021AA450;

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
		if (gSoclConfig->flag28 == 0) {
			gSoclConfig->func1c(g_021AA450.field1c);
		}
		gSoclConfig = 0;
		SOCLi_InitResource();
	}
	return result;
}
