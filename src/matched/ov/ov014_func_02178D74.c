/*
 * function: WIH_StateOutSetMPData
 * address: 0x02178D74
 * packet: pkt_ov014_02178D74
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C.
 * symbols:
 *   WIH_SetError 0x0217814C thumb ov014
 */
#include "../include/Obj12476.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Cb)(int);
extern void WIH_SetError(int);
void WIH_StateOutSetMPData(u8 *p) {
 int v = ((struct Obj12476 *)p)->f2;
 if (v != 0 && v != 15) { WIH_SetError(v); }
 else { Cb cb = *(Cb *)&((struct Obj12476 *)p)->f20; if (cb != 0) cb(v == 0); }
}
