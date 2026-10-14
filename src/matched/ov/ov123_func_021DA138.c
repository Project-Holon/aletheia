/*
 * function: PDWACC_STATE_StateWaitInputClearWindow
 * address: 0x021DA138
 * packet: pkt_ov123_021DA138
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   PDWACC_MESSAGE_ClearWindow 0x021D97B0 thumb ov123
 *   func_02009448 0x02009448 thumb
 *   func_020092E0 0x020092E0 thumb
 *   PDWACC_STATE_StateRestartTimeIcon 0x021DA110 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj14001.h"
typedef unsigned char u8;
extern unsigned int KEY_GetTrg(void);
extern void PDWACC_MESSAGE_ClearWindow(char *);
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
struct Sub02009210Obj;
extern void func_020092E0(struct Sub02009210Obj *obj, u8 value);
extern void PDWACC_STATE_StateRestartTimeIcon(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StateWaitInputClearWindow(char *p) { if(KEY_GetTrg()) { PDWACC_MESSAGE_ClearWindow(*(char * *)&((struct Obj14001 *)p)->f10); func_020092E0((struct Sub02009210Obj *)func_02009448(((struct Obj14001 *)p)->f1C),1); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateRestartTimeIcon,0x11a); } }
