/*
 * function: SOCLi_CleanupCommandPacketQueue
 * address:  0x0215CDD0
 * packet:   pkt_ov009_0215CDD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CleanupCommandPacketQueue (libsoc.TWL.HYB.a(socl_command.o))
 *
 * symbols:
 *   gSoclCmdQueue  0x021AA480  data
 *   gSoclConfig  0x021A1CD8  data
 */

#include "../include/G_021A1CD8.h"
#include "../include/G_Cmd.h"

typedef struct {
	void *packets;
	char pad0[0x14];
	int a;
	int pad1;
	int b;
} Cmd;

extern struct Cmd gSoclCmdQueue;
extern struct G_021A1CD8 *gSoclConfig;

int SOCLi_CleanupCommandPacketQueue(void)
{
	if (gSoclCmdQueue.b < gSoclCmdQueue.a)
		return -1;
	gSoclConfig->free(gSoclCmdQueue.packets);
	gSoclCmdQueue.packets = 0;
	return 0;
}
