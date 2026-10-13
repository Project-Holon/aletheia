/*
 * function: func_021BD808
 * address: 0x021BD808
 * packet: pkt_ov110_021BD808
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_0203630C 0x0203630C arm
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
extern int TOUCHPANEL_GetCont(void);
extern unsigned int func_0203630C(void);
int func_021BD808(u8 *p,void *q) {
 void (*cb)(u8 *,void *);
 if(((struct Obj00012 *)p)->f70==1) {
  if(TOUCHPANEL_GetCont()) return 0;
  if(func_0203630C()) { cb=*(void (**)(u8 *,void *))(p+0x74); ((struct Obj00012 *)p)->f70=0; if(cb) cb(p,q); return 1; }
 } else {
  if(func_0203630C()) return 0;
  if(TOUCHPANEL_GetCont()) { cb=*(void (**)(u8 *,void *))(p+0x74); ((struct Obj00012 *)p)->f70=1; if(cb) cb(p,q); return 1; }
 }
 return 0;
}
