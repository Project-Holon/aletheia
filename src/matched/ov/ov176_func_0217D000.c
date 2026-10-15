/*
 * function: DIGITALCARDCHECK_GetMenuResult
 * address: 0x0217D000
 * packet: pkt_ov176_0217D000
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 */
#include "../include/Obj24422.h"
typedef unsigned char u8;
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
int DIGITALCARDCHECK_GetMenuResult(u8 *p){return WIFIBATTLEMATCH_UTIL_GetBusy(*(int * *)&((struct Obj24422 *)p)->f1A4);}
