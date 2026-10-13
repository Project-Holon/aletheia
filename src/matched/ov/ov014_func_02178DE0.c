/*
 * function: WIH_StateOutEnd
 * address: 0x02178DE0
 * packet: pkt_ov014_02178DE0
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data a4
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 */
#include "../include/Obj12477.h"
#include "../include/G_S.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Cb)(int);
extern struct S *gWihWork;
extern void WIH_ChangeSysState(int);
void WIH_StateOutEnd(u8 *p) {
 Cb cb = *(Cb *)(((u8 *)gWihWork) + 0x1E64);
 if (cb != 0) cb(((struct Obj12477 *)p)->f2 == 0 ? 1 : 0);
 if (((struct Obj12477 *)p)->f2 != 0) WIH_ChangeSysState(10); else WIH_ChangeSysState(0);
}
