/*
 * function: GURU2_COMM_RecvParentNotice, GURU2_COMM_GetOwnPlayerId
 * unit: yes
 * address: 0x021DCCF0
 * packet: pkt_ov137_021DCCF0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_SetStateFromParent 0x021DE08C thumb ov137
 */
#include "../include/Obj23677.h"
#include "../include/Obj23678.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GURU2_RECEIPT_SetStateFromParent(char *p, int state, int player);
void GURU2_COMM_RecvParentNotice(int a,int b,int c,u8 *p) {if(GFL_NET_SYSTEM_GetCurrentAid()!=0) GURU2_RECEIPT_SetStateFromParent(*(char * *)&((struct Obj23678 *)(*(u8 * *)&((struct Obj23677 *)p)->f0))->f20,13,0);}
int GURU2_COMM_GetOwnPlayerId(void) {return GFL_NET_SYSTEM_GetCurrentAid();}
