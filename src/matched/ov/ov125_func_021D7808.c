/*
 * function: GDS_SOCKET_ResetConnection
 * address: 0x021D7808
 * packet: pkt_ov125_021D7808
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   GDS_SOCKET_Close 0x021D7F60 arm ov125
 *   GDS_SOCKET_Free 0x021D7C90 arm ov125
 *   GDS_SOCKET_InitSsl 0x021D858C arm ov125
 */

#include "../include/G_Clear.h"

extern struct Clear gGdsSocket;
extern void GDS_SOCKET_Close(void);
extern void GDS_SOCKET_Free(int);
extern void GDS_SOCKET_InitSsl(void);
void GDS_SOCKET_ResetConnection(void) {
 GDS_SOCKET_Close();
 if(((int *)&gGdsSocket)[0x258/4]) {
  GDS_SOCKET_Free(((int *)&gGdsSocket)[0x258/4]);
  ((int *)&gGdsSocket)[0x258/4]=0;
 }
 ((int *)&gGdsSocket)[0x244/4]=15;
 ((int *)&gGdsSocket)[0x248/4]=30;
 ((int *)&gGdsSocket)[0x24c/4]=30;
 ((int *)&gGdsSocket)[0x254/4]=0;
 ((int *)&gGdsSocket)[0x25c/4]=0;
 ((int *)&gGdsSocket)[0x260/4]=0;
 ((int *)&gGdsSocket)[0x264/4]=0;
 ((int *)&gGdsSocket)[0x268/4]=0;
 ((int *)&gGdsSocket)[0x13c/4]=1;
 ((int *)&gGdsSocket)[0x250/4]=0;
 GDS_SOCKET_InitSsl();
}
