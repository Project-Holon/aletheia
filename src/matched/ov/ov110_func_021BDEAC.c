/*
 * function: func_021BDEAC
 * address: 0x021BDEAC
 * packet: pkt_ov110_021BDEAC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_021BDCB4 0x021BDCB4 thumb ov110
 *   func_021BDB98 0x021BDB98 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern int func_021BD808(u8 *p, void *q);
extern int func_021BDCB4(u8 *,unsigned *);
extern int func_021BDB98(u8 *,unsigned *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int func_021BDEAC(u8 *p,unsigned *q) {
 if(*q<=1 && func_021BD808(p,q) && !((struct Obj00012 *)p)->f70) { GFL_USE_PlaySeDefaultVolume(1352); return 0; }
 if(((struct Obj00012 *)p)->f70==0) { return func_021BDCB4(p,q); }
 else { return func_021BDB98(p,q); }
}
