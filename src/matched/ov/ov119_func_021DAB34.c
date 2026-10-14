/*
 * function: func_021DAB34
 * address: 0x021DAB34
 * packet: pkt_ov119_021DAB34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_CheckSaveFlag 0x021D89A8 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DAB0C 0x021DAB0C thumb ov119
 */
#include "../include/Obj04476.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int POKETRADE_PROC_IsNetSession(void *);
extern int POKETRADE_PROC_CheckSaveFlag(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021DAB0C(char *p);
void func_021DAB34(char *p) {
 u8 b[2];
 if(POKETRADE_PROC_IsNetSession(p)) {
  b[0]=((struct Obj04476 *)p)->f630;b[1]=POKETRADE_PROC_CheckSaveFlag(p);
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc10,2,(u32)((void *)b))) {((struct Obj04476 *)p)->fF2C=0;POKETRADE_PROC_SetStep(p,(int)func_021DAB0C);}
 } else {
  p[0x11f2]=((struct Obj04476 *)p)->f630;((struct Obj04476 *)p)->f107E=((struct Obj04476 *)p)->f11F2*160+16;
  ((struct Obj04476 *)p)->fF2C=0;POKETRADE_PROC_SetStep(p,(int)func_021DAB0C);
 }
}
