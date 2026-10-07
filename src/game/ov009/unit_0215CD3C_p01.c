/*
 * file:     unit_0215CD3C_p01.c
 * unit:     yes
 * function: func_0215CDD0, func_0215CE14
 * address:  0x0215CDD0
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
 *   g_021AA480  0x021AA480  data
 *   g_021A1CD8  0x021A1CD8  data
 *   OS_ReceiveMessage           0x02085e50 arm
 *   SOCLiCommandPacketQueue    0x021aa484 data
 */
#include "../../matched/include/G_021A1CD8.h"
#include "../../matched/include/G_Cmd.h"

struct OSMessageQueue;
union SOCLiCommandPacket;
typedef struct {
	void *packets;
	char pad0[0x14];
	int a;
	int pad1;
	int b;
} Cmd;

extern int OS_ReceiveMessage(struct OSMessageQueue *mq, void **msg, long flags);
int func_0215CDD0(void);
union SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag);
extern struct Cmd g_021AA480;
extern struct G_021A1CD8 *g_021A1CD8;
extern struct OSMessageQueue SOCLiCommandPacketQueue;


/*
 * sdk:      SOCLi_CleanupCommandPacketQueue (libsoc.TWL.HYB.a(socl_command.o))
 */
int func_0215CDD0(void)
{
	if (g_021AA480.b < g_021AA480.a)
		return -1;
	g_021A1CD8->free(g_021AA480.packets);
	g_021AA480.packets = 0;
	return 0;
}


union SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag)
{
    union SOCLiCommandPacket *cp;

    if (OS_ReceiveMessage(&SOCLiCommandPacketQueue, (void **)&cp, flag) != 0)
        return cp;
    return 0;
}
