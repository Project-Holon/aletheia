/*
 * function: POKETRADE_PROC_StepSendCursorChoice
 * address: 0x021DA700
 * packet: pkt_ov119_021DA700
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021D4B88 0x021D4B88 thumb ov117
 *   func_021D6F2C 0x021D6F2C thumb ov118
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern int POKETRADE_PROC_IsNetSession(void *),POKETRADE_PROC_IsHostSide(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021D4B88(u8 *p);
extern void func_021D6F2C(u8 *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
void POKETRADE_PROC_StepSendCursorChoice(char *p) {
 u8 b=((struct Obj00001 *)p)->f10A0;
 if(POKETRADE_PROC_IsNetSession(p)) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc03,1,(u32)(&b))==0) return;}
 *(unsigned *)0x04001000 &= 0xffff1fff;
 if(POKETRADE_PROC_IsHostSide(p)==0) POKETRADE_PROC_SetStep(p,(int)func_021D4B88);
 else POKETRADE_PROC_SetStep(p,(int)func_021D6F2C);
}
