/*
 * function: GDS_SOCKET_GetReplySizeUnlocked
 * address: 0x021D7C14
 * packet: pkt_ov125_021D7C14
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
int GDS_SOCKET_GetReplySizeUnlocked(void){GDS_SOCKET_Lock();if(GDS_SOCKET_GetStateUnlocked()!=8){GDS_SOCKET_Unlock();return -1;}else{GDS_SOCKET_Unlock();return *(int*)(((char *)&gGdsSocket)+0x25c);}}
