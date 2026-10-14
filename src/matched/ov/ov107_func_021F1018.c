/*
 * function: MB_COMM_SYS_StartNet
 * address: 0x021F1018
 * packet: pkt_ov107_021F1018
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_StartByNetType 0x0203D01C arm
 */
#include "../include/Obj22294.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void GFL_NET_StartByNetType(void);
void MB_COMM_SYS_StartNet(u8 *p) { GFL_NET_StartByNetType();((struct Obj22294 *)p)->f4=1; }
