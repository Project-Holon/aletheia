/*
 * function: func_021D97B4
 * address: 0x021D97B4
 * packet: pkt_ov093_021D97B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj10056.h"
extern int func_021D775C(int);
extern void *func_021C88A4(void *,int,int);
extern void func_021C88C8(void *,void *);
void func_021D97B4(void *a,int b,int c) { unsigned char *p; int k=2; if(b==func_021D775C(k)) { p=func_021C88A4(a,0x1d,b); ((struct Obj10056 *)p)->f0 |= k<<22; p[4]=c; p[5]=0xff; func_021C88C8(a,p); } }
