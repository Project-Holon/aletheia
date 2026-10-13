/*
 * function: WIH_StateOutReset
 * address: 0x02178D00
 * packet: pkt_ov014_02178D00
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_SetError 0x0217814C thumb ov014
 */
#include "../include/Obj12475.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void WIH_ChangeSysState(int);
extern void WIH_SetError(int);
void WIH_StateOutReset(u8 *p) { if (((struct Obj12475 *)p)->f2 != 0) { WIH_ChangeSysState(9); WIH_SetError(((struct Obj12475 *)p)->f2); } else { WIH_ChangeSysState(1); } }
