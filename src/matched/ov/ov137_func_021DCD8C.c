/*
 * unit: yes
 * function: GURU2_COMM_RecvRoundResult,GURU2_COMM_RecvSelectedSlot,GURU2_COMM_RecvAngles,GURU2_COMM_RecvAbortVote,GURU2_COMM_RecvContinueVote,GURU2_COMM_GetRecvBuffer
 * address: 0x021DCD8C
 * packet: pkt_ov137_021DCD8C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * GURU2_MAIN_StoreRoundResult 0x021E1694 thumb ov137
 * GURU2_MAIN_SetPlayerSelectedSlot 0x021E180C thumb ov137
 * GURU2_MAIN_StoreAngles 0x021E1814 thumb ov137
 */
#include "../include/Obj23692.h"
#include "../include/Obj23693.h"
#include "../include/Obj23695.h"
#include "../include/Obj23696.h"
#include "../include/Obj23697.h"
#include "../include/Obj23698.h"
#include "../include/Obj23699.h"
#include "../include/Obj23700.h"
#include "../include/Obj23701.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void GURU2_MAIN_StoreRoundResult(void *,void *);
extern void GURU2_MAIN_StoreAngles(unsigned char *p, u16 *q);
extern void GURU2_MAIN_SetPlayerSelectedSlot(int *p, int a, int b);
void GURU2_COMM_RecvRoundResult(int a,int b,void *c,u8 *p) { if(a==0) GURU2_MAIN_StoreRoundResult(((struct Obj23693 *)(*(u8 * *)&((struct Obj23692 *)p)->f0))->f1C,c); }
void GURU2_COMM_RecvSelectedSlot(int a,int b,int *c,u8 *p) { GURU2_MAIN_SetPlayerSelectedSlot(((struct Obj23696 *)(*(u8 * *)&((struct Obj23695 *)p)->f0))->f1C,a,*c); }
void GURU2_COMM_RecvAngles(int a,int b,void *c,u8 *p) { GURU2_MAIN_StoreAngles(((struct Obj23698 *)(*(u8 * *)&((struct Obj23697 *)p)->f0))->f1C,c); }
void GURU2_COMM_RecvAbortVote(int a,int b,void *c,u8 *p) { ((struct Obj23699 *)p)->f48|=(u16)(1<<a); }
void GURU2_COMM_RecvContinueVote(int a,int b,void *c,u8 *p) { ((struct Obj23700 *)p)->f4A|=(u16)(1<<a); }
void *GURU2_COMM_GetRecvBuffer(int a,u8 *p) { return *(u8 * *)&((struct Obj23701 *)p)->f4C+a*0x594; }
