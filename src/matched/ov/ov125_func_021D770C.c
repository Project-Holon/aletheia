/*
 * function: GDS_SOCKET_Reset
 * address: 0x021D770C
 * packet: pkt_ov125_021D770C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   gGdsHostTail 0x021DA040 data a4
 *   GDS_SOCKET_ResetConnection 0x021D7808 arm ov125
 *   GDS_SOCKET_Nop 0x021D7CEC arm ov125
 *   GDS_SOCKET_NopVoid 0x021D7D20 arm ov125
 */

#include "../include/G_Clear.h"

typedef struct { int words[78]; } Clear;
extern struct Clear gGdsSocket;
extern char gGdsHostTail[];
extern void GDS_SOCKET_ResetConnection(void);
extern int GDS_SOCKET_Nop(void *);
extern void GDS_SOCKET_NopVoid(void);
void GDS_SOCKET_Reset(void)
{
    GDS_SOCKET_ResetConnection();
    __builtin__clear(&gGdsSocket, sizeof(Clear));
    *(int *)((char *)&gGdsSocket + 0x138) = 0;
    *((char *)&gGdsSocket + 0x140) = 0;
    *(short *)(gGdsHostTail + 0x40) = 0;
    GDS_SOCKET_Nop(gGdsHostTail);
    GDS_SOCKET_NopVoid();
}
