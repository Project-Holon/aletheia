/*
 * function: func_021D9554
 * address: 0x021D9554
 * packet: pkt_ov121_021D9554
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_DATA_CheckPacketCrc 0x0200A21C thumb
 */
#include "../include/Obj13943.h"
typedef unsigned char  u8;
extern int MYSTERY_DATA_CheckPacketCrc(u8 *obj);
int func_021D9554(char *p,int n) {
 if(MYSTERY_DATA_CheckPacketCrc((u8 *)p)!=0 && n==0 && (((struct Obj13943 *)p)->fCC==0 || (((struct Obj13943 *)p)->fCC&0x200000)!=0)) return 1;
 return 0;
}
