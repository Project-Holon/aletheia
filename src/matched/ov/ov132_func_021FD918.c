/*
 * function: STA_NET_SetState6Pair
 * address: 0x021FD918
 * packet: pkt_ov132_021FD918
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 */
#include "../include/Obj10568.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MUS_COMM_FUNC_SetTimingSync(int,int);
void STA_NET_SetState6Pair(char *p, u32 a, int b) {MUS_COMM_FUNC_SetTimingSync((int)p,0x40);((struct Obj10568 *)p)->f4C=6;((struct Obj10568 *)p)->f144=a;((struct Obj10568 *)p)->f148=b;}
