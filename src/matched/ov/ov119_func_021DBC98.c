/*
 * function: func_021DBC98
 * address: 0x021DBC98
 * packet: pkt_ov119_021DBC98
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_NEGO_FindFreeOfferIndex 0x021DD3D4 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DBC3C 0x021DBC3C thumb ov119
 */
#include "../include/Obj08057.h"
typedef unsigned short u16;extern int POKETRADE_PROC_IsHostSide(void *);extern int POKETRADE_NEGO_FindFreeOfferIndex(void *,int,int,int);extern void *GFL_NET_HANDLE_GetCurrentHandle(void);extern int GFL_NET_SendToHandle(void *a, u16 b, u16 c, void *d);extern void POKETRADE_PROC_SetStep(void *,int);extern void func_021DBC3C(void);
void func_021DBC98(char *p) {int same=0;if(((struct Obj08057 *)p)->fF88==((struct Obj08057 *)p)->f630)same=1;if(POKETRADE_PROC_IsHostSide(p)) {int n=POKETRADE_NEGO_FindFreeOfferIndex(p,0,((struct Obj08057 *)p)->fF84,((struct Obj08057 *)p)->fF88);if(n!=-1) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),n+0xc13,1,&same)) {POKETRADE_PROC_SetStep(p,(int)func_021DBC3C);return;}} else {POKETRADE_PROC_SetStep(p,(int)func_021DBC3C);return;}} else {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc16,1,&same))POKETRADE_PROC_SetStep(p,(int)func_021DBC3C);}}
