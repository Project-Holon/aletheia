/*
 * function: GDS_SOCKET_GetErrorUnlocked
 * address: 0x021D7C48
 * packet: pkt_ov125_021D7C48
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_Lock 0x021D7CAC arm ov125
 *   GDS_SOCKET_GetStateUnlocked 0x021D7BCC arm ov125
 *   GDS_SOCKET_Unlock 0x021D7CC0 arm ov125
 *   gGdsSocket 0x021D9E40 data a4
 */

#include "../include/G_Clear.h"

extern void GDS_SOCKET_Lock(void);
extern unsigned GDS_SOCKET_GetStateUnlocked(void);
extern void GDS_SOCKET_Unlock(void);
extern struct Clear gGdsSocket;
int GDS_SOCKET_GetErrorUnlocked(void){GDS_SOCKET_Lock();if(GDS_SOCKET_GetStateUnlocked()!=9){GDS_SOCKET_Unlock();return 0;}else{GDS_SOCKET_Unlock();return *(int*)(((char *)&gGdsSocket)+0x250);}}
