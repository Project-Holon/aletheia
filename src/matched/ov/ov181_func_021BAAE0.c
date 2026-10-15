/*
 * unit: no
 * function: STAFF_ROLL_CmdQueueLight
 * address: 0x021BAAE0
 * packet: pkt_ov181_021BAAE0
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STAFF_ROLL_QueueLight 0x021B9FD8 thumb ov181
 *   STAFF_ROLL_SetLightMode 0x021BA2A8 thumb ov181
 */
#include "../include/Obj14415.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void STAFF_ROLL_QueueLight(u8 *,int,int);
extern void STAFF_ROLL_SetLightMode(u8 *,u32);
int STAFF_ROLL_CmdQueueLight(u8 *p,u8 *q){u8 *s=(u8 *)((u32)p+0x28);STAFF_ROLL_QueueLight(s,q[7],((struct Obj14415 *)q)->f4);STAFF_ROLL_SetLightMode(s,1);return 1;}
