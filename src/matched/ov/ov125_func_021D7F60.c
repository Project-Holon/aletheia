/*
 * function: GDS_SOCKET_Close
 * address: 0x021D7F60
 * packet: pkt_ov125_021D7F60
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   gGdsSslConnection 0x021DA258 data a4
 *   GDS_SOCKET_FreeSslServerName 0x021D8C5C arm ov125
 *   SOC_Shutdown 0x0215F638 arm ov009
 *   SOC_Close 0x0215F644 arm ov009
 */

#include "../include/G_Clear.h"

extern struct Clear gGdsSocket;
extern char gGdsSslConnection[];
extern int SOC_Shutdown(int s, int how);
extern int SOC_Close(int s);
extern void GDS_SOCKET_FreeSslServerName(void *);
void GDS_SOCKET_Close(void) {
 if (((unsigned *)&gGdsSocket)[0x26c/4] == -1u) return;
 SOC_Shutdown(((unsigned *)&gGdsSocket)[0x26c/4], 2);
 SOC_Close(((unsigned *)&gGdsSocket)[0x26c/4]);
 ((unsigned *)&gGdsSocket)[0x26c/4] = -1u;
 GDS_SOCKET_FreeSslServerName(gGdsSslConnection);
}
