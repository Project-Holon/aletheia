/*
 * function: LIVEBATTLEMATCH_IRC_GetMenuValue
 * address: 0x0217DFE4
 * packet: pkt_ov176_0217DFE4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 */
#include "../include/Obj00348.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
int LIVEBATTLEMATCH_IRC_GetMenuValue(int *p) {return WIFIBATTLEMATCH_UTIL_GetBusy(*(int * *)&((struct Obj00348 *)p)->f18);}
