/*
 * unit: yes
 * function: GURU2_COMM_RecvMemberCount,GURU2_COMM_RecvStatusFlags,GURU2_COMM_RecvPlayerReady,GURU2_COMM_RecvSlotAssignment,GURU2_COMM_RecvPlayerCount,GURU2_COMM_RecvPlayerInput
 * address: 0x021DCD14
 * packet: pkt_ov137_021DCD14
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * GURU2_RECEIPT_SetStateFromChild 0x021DE17C thumb ov137
 * GURU2_MAIN_StoreSlotAssignment 0x021E172C thumb ov137
 * GURU2_MAIN_SyncPlayerCount 0x021E1758 thumb ov137
 * GURU2_MAIN_SetPlayerInput 0x021E168C thumb ov137
 * GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj14206.h"
#include "../include/Obj23680.h"
#include "../include/Obj23682.h"
#include "../include/Obj23683.h"
#include "../include/Obj23684.h"
#include "../include/Obj23685.h"
#include "../include/Obj23687.h"
#include "../include/Obj23688.h"
#include "../include/Obj23690.h"
#include "../include/Obj23691.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void GURU2_RECEIPT_SetStateFromChild(char *p, int command, int player);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GURU2_MAIN_StoreSlotAssignment(char *p, unsigned short *q);
extern void GURU2_MAIN_SyncPlayerCount(char *p, int a1);
extern void GURU2_MAIN_SetPlayerInput(int *p, int a);
void GURU2_COMM_RecvMemberCount(int a,int b,u8 *c,u8 *p)
{
    GURU2_RECEIPT_SetStateFromChild(((struct Obj23680 *)(*(u8 * *)&((struct Obj14206 *)p)->f0))->f20,1,*c);
    if(!GFL_NET_SYSTEM_GetCurrentAid()) ((struct Obj14206 *)p)->f34=0;
}
void GURU2_COMM_RecvStatusFlags(int a,int b,u16 *c,u8 *p) { ((struct Obj23682 *)p)->f40|=*c; }
void GURU2_COMM_RecvPlayerReady(int a,int b,void *c,u8 *p) { ((struct Obj23683 *)p)->f42|=(u16)(1<<a); }
void GURU2_COMM_RecvSlotAssignment(int a,int b,void *c,u8 *p) { GURU2_MAIN_StoreSlotAssignment(((struct Obj23685 *)(*(u8 * *)&((struct Obj23684 *)p)->f0))->f1C,c); }
void GURU2_COMM_RecvPlayerCount(int a,int b,int *c,u8 *p) { GURU2_MAIN_SyncPlayerCount(((struct Obj23688 *)(*(u8 * *)&((struct Obj23687 *)p)->f0))->f1C,*c); }
void GURU2_COMM_RecvPlayerInput(int a,int b,u8 *c,u8 *p) { GURU2_MAIN_SetPlayerInput(((struct Obj23691 *)(*(u8 * *)&((struct Obj23690 *)p)->f0))->f1C,*c); }
