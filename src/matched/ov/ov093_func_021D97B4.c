/*
 * function: BTL_TOKUSEI_StartWeather
 * address: 0x021D97B4
 * packet: pkt_ov093_021D97B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj10056.h"
extern int BTL_EVENT_GetVar(int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *,void *);
void BTL_TOKUSEI_StartWeather(void *a,int b,int c) { unsigned char *p; int k=2; if(b==BTL_EVENT_GetVar(k)) { p=func_021C88A4(a,0x1d,b); ((struct Obj10056 *)p)->f0 |= k<<22; p[4]=c; p[5]=0xff; func_021C88C8(a,p); } }
