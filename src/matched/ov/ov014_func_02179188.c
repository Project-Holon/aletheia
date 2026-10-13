/*
 * function: WIH_IndicateHandler
 * address: 0x02179188
 * packet: pkt_ov014_02179188
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0217919E precede labelled 021791A0.
 * symbols:
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_SetError 0x0217814C thumb ov014
 */
#include "../include/Obj19343.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void WIH_ChangeSysState(int);
extern void WIH_SetError(int);
void WIH_IndicateHandler(u8 *p) { if (((struct Obj19343 *)p)->f2 == 8) { WIH_ChangeSysState(9); WIH_SetError(25); } }
