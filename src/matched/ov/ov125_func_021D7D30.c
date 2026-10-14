/*
 * function: GDS_SOCKET_StartThread
 * address: 0x021D7D30
 * packet: pkt_ov125_021D7D30
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gGdsConnectThread 0x021DA0B4 data a4
 *   gGdsSocket 0x021D9E40 data a4
 *   gGdsConnectThreadStackTop 0x021D9640 data a4
 *   GDS_SOCKET_ThreadEntry 0x021D7D24 arm ov125
 *   OS_CreateThread  0x020853C0  arm  arm9
 *   OS_WakeupThreadDirect  0x02085868  arm  arm9
 */

#include "../include/G_Clear.h"

extern char gGdsConnectThread[], gGdsConnectThreadStackTop[];
extern struct Clear gGdsSocket;
extern void GDS_SOCKET_ThreadEntry(void *);
extern void OS_CreateThread(void *, void (*)(void *), int, void *, int, unsigned);
extern void OS_WakeupThreadDirect(void *);
int GDS_SOCKET_StartThread(void) {
 OS_CreateThread(gGdsConnectThread, GDS_SOCKET_ThreadEntry, 0, gGdsConnectThreadStackTop, 0x800, ((unsigned *)&gGdsSocket)[0x270/4]);
 OS_WakeupThreadDirect(gGdsConnectThread);
 return 1;
}
